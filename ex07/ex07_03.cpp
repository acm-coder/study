    std::vector small_vec;
    std::vector large_vec;

    do {
        load_data(large_vec);
        parallel_filtering_and_computing(large_vec, small_vec);
        // large_vec经过筛选后尺寸已缩小到与small_vec相同
        swap(large_vec, small_vec); // 通过swap将筛选结果快速送到small_vec
    } while (continue_process());
