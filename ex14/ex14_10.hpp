    // 面向右值引用类型的重载
    template<typename PARAM0, typename PARAM1>
    void operator () (PARAM0 &&param0, PARAM1 &&param1) {
        using std::move;
        func(move(param1), move(param0));
        // 勿忘用std::move强制转义
    }
