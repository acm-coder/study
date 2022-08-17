void foo(int param)
{
    int local;
    auto f0 = [local] {
        int lambda_local;
        auto f1 = [=] {
            // local由f0显式捕获，故可由f1继续捕获
            // lambda_local对于f1可见，故亦可捕获
            return local + lambda_local;
        };

        // param未由f0捕获，则f2不可捕获
        // auto f2 = [=] {return param;};
    };

    auto f3 = [&] {
        // f3设置默认捕获类型，则f4可自由捕获local与param
        auto f4 = [=] {return local + param;};
    };
}
