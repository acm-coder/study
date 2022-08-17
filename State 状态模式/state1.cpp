enum NetwrokState {
    Network_Open,
    Network_Close,
    Network_Connect,
    // 变动
};

class NetworkProcessor {
public:
    void Operator1() {
        if (state == Network_Open) {
            // ...
            state = Network_Close;
        } else if (state == Network_Close) {
            // ...
            state = Network_Connect;
        } else if (state == Network_Connect) {
            // ...
            state = Network_Open;
        } // 变动
    }

    void Operator2() {
        if (state == Network_Open) {
            // ...
            state = Network_Connect;
        } else if (state == Network_Close) {
            // ...
            state = Network_Open;
        } else if (state == Network_Connect) {
            // ...
            state = Network_Close;
        } // 变动
    }

private:
    NetwrokState state;
};

