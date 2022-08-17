#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Expression {
public:
    virtual int interpreter(map<char, int> var) = 0;
    virtual ~Expression() {}
};

// 变量表达式
class VarExpression : public Expression {
public:
    VarExpression(const char& key) : key(key) {}

    int interpreter(map<char, int> var) override {
        return var[key];
    }
private:
    char key;
};

// 符号表达式
class SymbolExpression : public Expression {
public:
    SymbolExpression(Expression* left, Expression* right) : left(left), right(right) {}

protected:
    Expression* left;
    Expression* right;
};

// 加法运算
class AddExpression : public SymbolExpression {
public:
    AddExpression(Expression* left, Expression* right) : SymbolExpression(left, right) {}
    int interpreter(map<char, int> var) override {
        return left->interpreter(var) + right->interpreter(var);
    }
};


// 减法运算
class SubExpression : public SymbolExpression {
public:
    SubExpression(Expression* left, Expression* right) : SymbolExpression(left, right) {}
    int interpreter(map<char, int> var) override {
        return left->interpreter(var) - right->interpreter(var);
    }
};

Expression* analyse(string expStr) {
    stack<Expression*> expStack;
    Expression* left = nullptr;
    Expression* right = nullptr;

    for (int i = 0; i < expStr.size(); ++ i) {
        switch(expStr[i]) {
            case '+':
                // 加法运算
                left = expStack.top();
                right = new VarExpression(expStr[++ i]);
                expStack.push(new AddExpression(left, right));
                break;
            case '-':
                // 减法运算
                left = expStack.top();
                right = new VarExpression(expStr[++ i]);
                expStack.push(new SubExpression(left, right));
                break;
            
            default:
                // 终结表达式
                expStack.push(new VarExpression(expStr[i]));
        }
    }
    return expStack.top();
}

void release(Expression* expr) {
    // 释放表达式树的节点内存...
}

int main() {
    string expStr = "a+b-c+d";
    map<char, int> var;
    var.insert({'a', 5});
    var.insert({'b', 2});
    var.insert({'c', 1});
    var.insert({'d', 6});
    
    Expression * expre = analyse(expStr);
    int result = expre->interpreter(var);
    cout << result << endl;
    release(expre);
    return 0;
    
}