import std.algorithm;           // 导入标准算法库以使用swap算法

class sub_matrix (M, bool is_const) // M是类型模板参数，is_const是布尔型模板参数
{
    M m;                        // D中自定义类变量自动为引用变量
    alias M.value_type value_type; // 嵌套类型重定义
    uint sz;                       // uint即无符号整数类型
    uint row_bias;
    uint col_bias;              // 子矩阵行列原点在原矩阵中的位置

    // 构造函数
    this(M _m, uint _sz, uint _row_bias, uint _col_bias) {
        m = _m;
        sz = _sz;
        row_bias = _row_bias;
        col_bias = _col_bias;
    }
    // 重载“调用”运算符即括号运算符
    value_type
    opCall(uint r, uint c) const {return m(r + row_bias, c + col_bias);}

    // 只有is_const == false即说明需要一个非常子矩阵时才编译以下内容
    static if (is_const == false) {
        // 返回左值的重载“调用”运算符
        ref value_type
            opCall(uint r, uint c) {return m(r + row_bias, c + col_bias);}
        // 行列交换函数
        void transpose() {
            foreach (uint i; 0 .. sz)
                foreach (uint j; 0 .. i)
                    swap(opCall(i, j), opCall(j, i));
        }
    }
}

// 助手函数
auto sub (M) (M m, uint sz, uint row_bias, uint col_bias) {
    return new sub_matrix!(M, false)(m, sz, row_bias, col_bias);
}

auto const_sub (M) (const M m, uint sz, uint row_bias, uint col_bias) {
    return new sub_matrix!(const M, true)(m, sz, row_bias, col_bias);
}