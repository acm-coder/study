#include <string>

class MessageImp {
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessageImp() {}
};

class Message {
public:
    Message(MessageImp* msgimpl) : msgImp(msgimpl) {}
    virtual void Login(std::string user_name, std::string password) = 0;
    virtual void SendMessage(std::string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual ~Message() {}

protected:
    MessageImp* msgImp; // new *MessageImp
};

// 平台实现

class PCMessageImp : public MessageImp {
public:
    virtual void PlaySound() {
        // ...
    }

    virtual void DrawShape() {
        // ...
    }

    virtual void WriteText() {
        // ...
    }

    virtual void Connect() {
        // ...
    }
};

class MobileMessageImp : public MessageImp {
public:
    virtual void PlaySound() {
        // ...
    }

    virtual void DrawShape() {
        // ...
    }

    virtual void WriteText() {
        // ...
    }

    virtual void Connect() {
        // ...
    }
};

class MessageLite : public Message {
public:
    MessageLite(MessageImp* impl) : Message(impl) {}

    virtual void Login(std::string username, std::string password) {
        msgImp->Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        msgImp->WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        msgImp->DrawShape();
        // ...
    }
};

class MessagePerfect : public Message {
public:
    MessagePerfect(MessageImp* impl) : Message(impl) {}

    virtual void Login(std::string username, std::string password) {
        msgImp->PlaySound();
        // ...
        msgImp->Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        msgImp->PlaySound();
        // ...
        msgImp->WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        msgImp->PlaySound();
        // ...
        msgImp->DrawShape();
        // ...
    }
};

void Process() {
    // 编译时装配
    // Message* msg = new MobileMessagePerfect();

    // 运行时装配
    MessageImp* impl = new PCMessageImp;
    Message* lite = new MessageLite(impl);
    Message* perfect = new MessagePerfect(impl);
}
