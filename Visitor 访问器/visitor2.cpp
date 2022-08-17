#include <iostream>

using namespace std;

class Visitor;

class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Element() {}
};

class ElementA : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visitElementA(*this);
    }
};

class ElementB : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visitElementB(*this);
    }
};

class Visitor {
public:
    virtual void visitElementA(ElementA& element) = 0;
    virtual void visitElementB(ElementB& element) = 0;
    virtual ~Visitor() {}
};

class Visitor1 : public Visitor {
public:
    void visitElementA(ElementA& element) override {
        cout << "Visitor1 is processing ElementA" << endl;
    }

    void visitElementB(ElementB& element) override {
        cout << "Visitor1 is processing ElementB" << endl;
    }
};

class Visitor2 : public Visitor {
public:
    void visitElementA(ElementA& element) override {
        cout << "Visitor2 is processing ElementA" << endl;
    }

    void visitElementB(ElementB& element) override {
        cout << "Visitor2 is processing ElementB" << endl;
    }
};

// class Visitor3 : public Visitor {} // 变动

int main() {
    Visitor2 visitor;
    ElementB element;
    element.accept(visitor); // double dispatch

    return 0;
}
