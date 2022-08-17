
class Visitor;

class Element {
public:
    virtual void Func1() = 0;
    // virtual void Func2(int data) = 0; // 变动
    virtual ~Element() {}
};

class ElementA : public Element {
public:
    void Func1() override {
        // ...
    }
    // virtual void Func2(int data) = 0; // 变动
};

class  Element2 : public Element {
public:
    void Func1() override {
        // ...
    }
    // virtual void Func2(int data) = 0; // 变动
};




