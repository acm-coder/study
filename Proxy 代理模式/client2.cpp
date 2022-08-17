
class ISubject {
public:
    virtual void process() = 0;
};

// Proxy的设计
class SubjectProxy : public ISubject {

public:
    virtual void process() {
        // 对RealSubject间接访问
        // ...
    }
};

class ClientApp {
public:
    ClientApp() {
        subject = new SubjectProxy;
    }

    void DoTask() {
        // ...
        subject->process();
        // ...
    }

private:
    ISubject* subject;
};

