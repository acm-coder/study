// 文件名：object_pool.cpp
#include "object_pool.hpp"
#include <new>

namespace mylib {

    // 方便按字节移位并转义指针
    template<typename T0, typename T1>
    inline
    T0* byte_shift(T1* ptr, size_t b)
    {
        return reinterpret_cast<T0*>(reinterpret_cast<char*>(ptr) + b);
    }

    void* object_pool::allocate() throw (std::bad_alloc)
    {
        if (!free_node_head) {
            // 无空闲节点，新申请一块chunk并同步更新chunk list与free node list
            chunk_data *new_chunk =
                reinterpret_cast<chunk_data*>(operator new(chunk_size));
            new_chunk->next = chunk_data_head;
            chunk_data_head = new_chunk;

            // 将所申请的chunk分成空闲块，并一一插入空闲列表，同时标记正确的bias值
            free_node_head = byte_shift<free_node>(new_chunk, chunk_data_size);
            free_node_head->bias = 0;
            free_node_head->next = 0;
            
            for (size_t node_index = 1;
                 node_index < num_nodes_per_chunk; ++node_index) {
                free_node *f = byte_shift<free_node>(free_node_head,
                                                     free_node_size);
                f->bias = free_node_head->bias + 1;
                f->next = free_node_head;
                free_node_head = f;
            }
        }
        

        free_node *return_node = free_node_head;
        free_node_head = free_node_head->next;

        return static_cast<void*>(&(return_node->next));
    }

    void object_pool::deallocate(void *ptr)
    {
        // 将所回收的块插入空闲列表
        free_node *f = byte_shift<free_node>(ptr, -1 * free_node_offset);
        f->next = free_node_head;
        free_node_head = f;
    }

    size_t object_pool::recycle()
    {
        // 预算free node到chunk的偏移量表
        size_t *shift_table = new size_t[num_nodes_per_chunk];
        shift_table[0] = -1 * chunk_data_size;
        for (size_t i = 1; i < num_nodes_per_chunk; ++i)
            shift_table[i] = shift_table[i - 1] - free_node_size;

        // 重置所有chunk的free_node_count
        for (chunk_data *p = chunk_data_head; p; p = p->next)
            p->free_node_count = 0;

        // 首先访问所有的free node，并更新其所属chunk的free_node_count
        for (free_node *f = free_node_head; f; f = f->next) {
            chunk_data *chunk = byte_shift<chunk_data>(f, shift_table[f->bias]);
            ++chunk->free_node_count;
        }

        // 将全空闲chunk的所属节点从free list中删除
        for (free_node **pp = &free_node_head; *pp; ) {
            chunk_data *chunk =
                byte_shift<chunk_data>(*pp, shift_table[(*pp)->bias]);
            if (chunk->free_node_count == num_nodes_per_chunk)
                *pp = (*pp)->next;
            else
                pp = &((*pp)->next);
        }

        // 将所有空闲chunk从链表中删除
        size_t num_recycled = 0;
        for (chunk_data **pp = &chunk_data_head; *pp;) {
            if ((*pp)->free_node_count == num_nodes_per_chunk) {
                // chunk的所有node都是free node，可以释放该chunk空间
                chunk_data *p = *pp;
                *pp = (*pp)->next;
                operator delete (p);
                ++num_recycled;
            }
            else {
                pp = &((*pp)->next);
            }
        }

        delete[] shift_table;
        return num_recycled * chunk_size;
    }
}   // namespace mylib
