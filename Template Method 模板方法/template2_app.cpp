#include "template2_lib.h"

// 应用程序开发人员

class Application : public Library {

protected:
    virtual bool Step2() {
        // ... 子类实现
    }

    virtual bool Step4() {
        // ... 子类实现
    }
};

int main() {
    Library* plib = new Application;
    plib->Run();

    delete plib;
    return 0;
}

