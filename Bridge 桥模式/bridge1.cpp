#include <string>

class Message {
public:
    virtual void Login(std::string user_name, std::string password) = 0;
    virtual void SendMessage(std::string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~Message() {}
};

// 平台实现

class PCMessageBase : public Message {
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

class MobileMessageBase : public Message {
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


class PCMessageLite : public PCMessageBase {
public:
    virtual void Login(std::string username, std::string password) {
        PCMessageBase::Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        PCMessageBase::WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        PCMessageBase::DrawShape();
        // ...
    }
};

class PCMessageLite : public PCMessageBase {
public:
    virtual void Login(std::string username, std::string password) {
        PCMessageBase::Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        PCMessageBase::WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        PCMessageBase::DrawShape();
        // ...
    }
};

class PCMessagePerfect : public PCMessageBase {
public:
    virtual void Login(std::string username, std::string password) {
        PCMessageBase::PlaySound();
        // ...
        PCMessageBase::Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        PCMessageBase::PlaySound();
        // ...
        PCMessageBase::WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        PCMessageBase::PlaySound();
        // ...
        PCMessageBase::DrawShape();
        // ...
    }
};

class MobileMessageLite : public MobileMessageBase {
public:
    virtual void Login(std::string username, std::string password) {
        MobileMessageBase::Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        MobileMessageBase::WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        MobileMessageBase::DrawShape();
        // ...
    }
};

class MobileMessagePerfect : public MobileMessageBase {
public:
    virtual void Login(std::string username, std::string password) {
        MobileMessageBase::PlaySound();
        // ...
        MobileMessageBase::Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        MobileMessageBase::PlaySound();
        // ...
        MobileMessageBase::WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        MobileMessageBase::PlaySound();
        // ...
        MobileMessageBase::DrawShape();
        // ...
    }
};


void Process() {
    // 编译时装配
    Message* msg = new MobileMessagePerfect();
}
