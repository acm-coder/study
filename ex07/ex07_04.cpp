    int small_pool[SMALL_POOL_SIZE];
    int large_pool[LARGE_POOL_SIZE];
    mem_pool_allocator alloc_0(mem_pool_0);
    mem_pool_allocator alloc_1(mem_pool_1);

    std::vector small_vec(alloc_0);
    std::vector large_vec(alloc_1);

    do {
        load_data(large_vec);
        parallel_filtering_and_computing(large_vec, small_vec);
        swap(large_vec, small_vec); // 危险！
    } while (continue_process());
