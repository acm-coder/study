    // 参数约束为引用类型
    template<typename PARAM0, typename PARAM1>
    void operator () (PARAM0 &param0, PARAM1 &param1) {
        func(param1, param0);
    }
