
class NetworkState {
public:
    NetworkState* pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;
    virtual ~NetworkState() {}
};

class OpenState;
class CloseState;
class ConnectState;
class WaitState; // 变化

class OpenState : public NetworkState {
public:
    static NetworkState* getInstance() {
        if (m_instance == nullptr) m_instance = new OpenState();
        return m_instance;
    }

    virtual void Operation1() {
        // ...
        pNext = CloseState::getInstance();
    }

    virtual void Operation2() {
        // ...
        pNext = ConnectState::getInstance();
    }

    virtual void Operation3() {
        // ...
        pNext = OpenState::getInstance();
    }

private:
    static NetworkState* m_instance;
};

class CloseState : public NetworkState {
public:
    static NetworkState* getInstance() {
        if (m_instance == nullptr) m_instance = new CloseState();
        return m_instance;
    }

    virtual void Operation1() {
        // ...

    }

    virtual void Operation2() {

    }

    virtual void Operation3() {

    }

private:
    static NetworkState* m_instance;
};

class ConnectState : public NetworkState {
public:
    static NetworkState* getInstance() {
        if (m_instance == nullptr) m_instance = new ConnectState();
        return m_instance;
    }

    virtual void Operation1() {
        // ...

    }

    virtual void Operation2() {

    }

    virtual void Operation3() {

    }

private:
    static NetworkState* m_instance;
};

class WaitState : public NetworkState {

};

class NetworkProcessor {
public:
    NetworkProcessor(NetworkState* state) : pState(state) {}

    void Operation1() {
        // ...
        pState->Operation1();
        pState = pState->pNext;
        // ...
    }

    void Operation2() {
        // ...
        pState->Operation2();
        pState = pState->pNext;
        // ...
    }

    void Operation3() {
        // ...
        pState->Operation3();
        pState = pState->pNext;
        // ...
    }

private:
    NetworkState* pState;
};
