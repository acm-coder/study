// 文件名： object_pool.hpp

#pragma once
#include <cstddef>
#include <algorithm>
#include <new>

// 预定义的每个chunk所含的内存块数，可由用户修改
#ifndef MYLIB_NUM_NODES_PER_CHUNK
#define MYLIB_NUM_NODES_PER_CHUNK 128
#endif

namespace mylib {
    class object_pool
    {
        static const unsigned char num_nodes_per_chunk =
            MYLIB_NUM_NODES_PER_CHUNK;

        typedef unsigned char counter_type;

        // 组块类型
        struct chunk_data
        {
            counter_type free_node_count;
            chunk_data *next;
        };
        static const size_t chunk_data_size = sizeof(chunk_data);

        chunk_data *chunk_data_head;

        struct free_node
        {
            counter_type bias;
            free_node *next;
        };

        static const size_t free_node_offset = offsetof(free_node, next);

        free_node *free_node_head;

        const size_t node_size;
        const size_t free_node_size;
        const size_t chunk_size;

    public:

        object_pool(size_t node_size) :
            chunk_data_head(0), free_node_head(0),
            node_size(node_size),
            free_node_size(free_node_offset +
                           std::max(sizeof(free_node*), node_size)),
            chunk_size(chunk_data_size +
                       free_node_size * num_nodes_per_chunk)
        {}
        ~object_pool() {
            // 析构时须释放所有已申请的组块内存
            while (chunk_data_head) {
                chunk_data *chunk = chunk_data_head;
                chunk_data_head = chunk_data_head->next;
                operator delete (chunk);
            }
        }

        // 分配及回收空间的函数
        void* allocate() throw (std::bad_alloc);
        void deallocate(void *ptr);

        size_t recycle();       // 释放空闲组块
    };

    // 可自动构造不同尺寸内存池的数组类
    class object_pool_array
    {
        size_t sz;
        object_pool *array;
    public:
        // 构造函数，参数sz为数组中对象池个数，step则为各对象池尺寸之差
        // 例如sz=4, step=8时将构造4个对象池，尺寸依次为：8, 16, 32, 40
        object_pool_array(size_t sz, size_t step) :
            sz(sz),
            // 先为array申请空间，但
构造内存池
            array(static_cast<object_pool*>(operator new (sizeof(object_pool) * sz)))
        {
            // 按步长递增尺寸构造对象池
            for (size_t i = 0; i < sz; ++i)
                new (array + i) object_pool(i * step + step);
        }
        ~object_pool_array() {
            // 先依次析构对象池
            for (size_t i = 1; i < sz; ++i)
                (array + i)->~object_pool();
            // 再释放内存
            operator delete (array);
        }

        size_t size() const {return sz;}

        // 重载下标操作符，使本类型具有数组语义
        object_pool& operator [] (size_t n) {return array[n];}
    };
} // namespace mylib
