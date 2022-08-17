// 目标接口(新接口)
class ITarget {
public:
    virtual void process() = 0;
};


// 遗留接口(老接口)
class IAdaptee {
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

// 遗留类型
class OldClass : public IAdaptee {
    // ...
};

class Adapter : public ITarget {
public:
    Adapter(IAdaptee* adaptee) : pAdaptee(adaptee) {}

    virtual void process() {
        int data = pAdaptee->bar();
        pAdaptee->foo(data);
    }

protected:
    IAdaptee* pAdaptee;
};

int main() {
    IAdaptee* pAdaptee = new OldClass;
    ITarget* target = new Adapter(pAdaptee);
    target->process();
}

