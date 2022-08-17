#include <iostream>
using namespace std;

template<typename T>
class Iterator {
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T& current() = 0;
};

template<typename T>
class MyCollection {
public:
    Iterator<T>* GetIterator() {
        // ..
    }
};

template<typename T>
class CollectionIterator : public Iteartor<T> {
public:
    CollectionIterator(const MyCollection<T>& c) : mc(c) {}
    void first() override {
        // ...
    }
    
    void next() override {
        // ...
    }

    bool isDone() const override {
        // ...
    }

    T& current() override {
        // ...
    }

private:
    MyCollection<T> mc;
};

void MyAlogrithm() {
    MyCollection<int> mc;

    Iterator<int>* iter = mc.GetIterator();

    for (iter->first(); !iter->isDone(); iter->next())
        cout << iter->current() << endl;
}
