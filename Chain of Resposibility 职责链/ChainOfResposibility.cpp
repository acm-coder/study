#include <iostream>
#include <string>

using namespace std;

enum class RequestType {
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3,
};

class Request {
public:
    Request(const string& desc, RequestType type):
        description(desc), reqType(type) {}
    
    RequestType getReqType() const { return reqType; }
    const string& getDescription() const { return description; }

private:
    string description;
    RequestType reqType;
};

class ChainHandler {
public:
    ChainHandler() : nextChain(nullptr) {}
    void setNextChain(ChainHandler* next) {
        nextChain = next;
    }

    void handle(const Request& req) {
        if (canHandleRequest(req)) processRequest(req);
        else sendRequestToNextHandler(req);
    }

private:
    void sendRequestToNextHandler(const Request& req) {
        if (nextChain != nullptr) nextChain->handle(req);
    }

protected:
    virtual bool canHandleRequest(const Request& req) = 0;
    virtual void processRequest(const Request& req) = 0;

private:
    ChainHandler* nextChain;
};

class Handle1 : public ChainHandler {
protected:
    bool canHandleRequest(const Request& req) override {
        return req.getReqType() == RequestType::REQ_HANDLER1;
    }

    void processRequest(const Request& req) override {
        cout << "Handle1 is handle request: " << req.getDescription() << endl;
    }
};

class Handle2 : public ChainHandler {
protected:
    bool canHandleRequest(const Request& req) override {
        return req.getReqType() == RequestType::REQ_HANDLER2;
    }

    void processRequest(const Request& req) override {
        cout << "Handle2 is handle request: " << req.getDescription() << endl;
    }
};

class Handle3 : public ChainHandler {
protected:
    bool canHandleRequest(const Request& req) override {
        return req.getReqType() == RequestType::REQ_HANDLER3;
    }

    void processRequest(const Request& req) override {
        cout << "Handle3 is handle request: " << req.getDescription() << endl;
    }
};

int main() {
    Handle1 h1;
    Handle2 h2;
    Handle3 h3;
    h1.setNextChain(&h2);
    h2.setNextChain(&h3);

    Request req("process task ...", RequestType::REQ_HANDLER3);
    h1.handle(req);
    return 0;
}
