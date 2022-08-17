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

class MessageLite {
    Message* msg; // new *MessageBase 纯虚基类
public:
    virtual void Login(std::string username, std::string password) {
        msg->Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        msg->WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        msg->DrawShape();
        // ...
    }
};

class MessagePerfect {
    Message* msg;
public:
    virtual void Login(std::string username, std::string password) {
        msg->PlaySound();
        // ...
        msg->Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        msg->PlaySound();
        // ...
        msg->WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        msg->PlaySound();
        // ...
        msg->DrawShape();
        // ...
    }
};

// class PCMessageLite {
//     Message* msg;
// public:
//     virtual void Login(std::string username, std::string password) {
//         msg->Connect();
//         // ...
//     }

//     virtual void SendMessage(std::string message) {
//         msg->WriteText();
//         // ...
//     }

//     virtual void SendPicture(Image image) {
//         msg->DrawShape();
//         // ...
//     }
// };

// class PCMessagePerfect {
//     Message* msg;
// public:
//     virtual void Login(std::string username, std::string password) {
//         msg->PlaySound();
//         // ...
//         msg->Connect();
//         // ...
//     }

//     virtual void SendMessage(std::string message) {
//         msg->PlaySound();
//         // ...
//         msg->WriteText();
//         // ...
//     }

//     virtual void SendPicture(Image image) {
//         msg->PlaySound();
//         // ...
//         msg->DrawShape();
//         // ...
//     }
// };

// class MobileMessageLite {
//     Message* msg;
// public:
//     virtual void Login(std::string username, std::string password) {
//         msg->Connect();
//         // ...
//     }

//     virtual void SendMessage(std::string message) {
//         msg->WriteText();
//         // ...
//     }

//     virtual void SendPicture(Image image) {
//         msg->DrawShape();
//         // ...
//     }
// };

// class MobileMessagePerfect {
//     Message* msg;
// public:
//     virtual void Login(std::string username, std::string password) {
//         msg->PlaySound();
//         // ...
//         msg->Connect();
//         // ...
//     }

//     virtual void SendMessage(std::string message) {
//         msg->PlaySound();
//         // ...
//         msg->WriteText();
//         // ...
//     }

//     virtual void SendPicture(Image image) {
//         msg->PlaySound();
//         // ...
//         msg->DrawShape();
//         // ...
//     }
// };


void Process() {
    // 编译时装配
    Message* msg = new MobileMessagePerfect();
}
