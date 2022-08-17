#include <stdexcept>

template<typename T>
class my_vector
{
    T *array;
    unsigned size;
    unsigned block_size;
public:
    //构造函数通过malloc申请内存空间
    my_vector(unsigned bsz) :
        array((T*)malloc(sizeof(T) * bsz)), size(0), block_size(bsz) {}
    ~my_vector() {if (array) free(array);}

    void push_back(T const &elem)
        throw (std::runtime_error) {
        if (size == block_size) {
            //已有空间已经用完，需要申请更大空间
            block_size *= 2;
            T* new_array = (T*)realloc(array, block_size * sizeof(T));
            if (new_array != NULL) array = new_array;
            else {
                //申请新空间失败，内存耗尽
                free(array);
                array = NULL;
                throw std::runtime_error("Out of memory.");
            }
        }
        array[size++] = elem;
    }

    T& operator[] (unsigned i) {return array[i];}
    const T& operator[] (unsigned i) const {return array[i];}
    //告诉我们你占了多大内存。
    unsigned get_mem_size() const {return block_size * sizeof(T);}
};
