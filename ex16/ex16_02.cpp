    auto f = [] (bool cond, float i, int j) noexcept -> int {
        if (cond) return i;
        return j;
    };
