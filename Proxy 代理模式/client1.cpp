
class ISubject {
public:
    virtual void process() = 0;
};

class RealSubject : public ISubject {
public:
    virtual void process() {
        // ...
    }
};

class ClientApp {
public:
    ClientApp() {
        subject = new RealSubject;
    }

    void DoTask() {
        // ...
        subject->process();
        // ...
    }

private:
    ISubject* subject;
};

