#include <string>

class Memento {

public:
    Memento(const std::string& s, ...) : state(s), ... {}
    std::string getState() const { return state; }
    void setState(const std::string& s) { state = s; }

private:
    std::string state;
    // ...
};

class Originator {
public:
    Originator() {}
    Memento createMemento() {
        return Memento(state, ...);
    }

    void setMemento(const Memento& m) {
        state = m.getState();
        // ...
    }

private:
    std::string state;
    // ...
};

int main() {
    Originator originator;
    // 捕获对象状态，存储到备忘录
    Memento memento = originator.createMemento();

    // ... 改变originator状态

    // 从备忘录中恢复
    originator.setMemento(memento);
    return 0;
}
