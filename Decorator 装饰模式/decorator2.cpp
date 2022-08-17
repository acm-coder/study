// 业务操作
class Stream {
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

// 主体类
class FileStream : public Stream {
public:
    virtual char Read(int number) {
        // 读文件流
    }

    virtual void Seek(int position) {
        // 定位文件流
    }

    virtual void Write(char data) {
        // 写文件流
    }
};

class NetworkStream : public Stream {
public:
    virtual char Read(int number) {
        // 读网络流
    }

    virtual void Seek(int position) {
        // 定位网络流
    }

    virtual void Write(char data) {
        // 写网络流
    }
};

class MemoryStream : public Stream {
public:
    virtual char Read(int number) {
        // 读内存流
    }

    virtual void Seek(int position) {
        // 定位内存流
    }

    virtual void Write(char data) {
        // 写内存流
    }
};

// 扩展操作

class CryptoStream : public Stream {
    Stream* stream; // ...
public:
    CryptoStream(Stream* s) : stream(s) {}

    virtual char Read(int number) {
        // 额外的加密操作
        stream->Read(number);
    }

    virtual void Seek(int position) {
        // 额外的加密操作
        stream->Seek(position);
        // 额外的加密操作
    }

    virtual void Write(char data) {
        // 额外的加密操作
        stream->:Write(data);
        // 额外的加密操作
    }
};


// class CryptoFileStream {
//     Stream* stream; // new FileStream();
// public:
//     virtual char Read(int number) {
//         // 额外的加密操作
//         stream->Read(number);
//     }

//     virtual void Seek(int position) {
//         // 额外的加密操作
//         stream->Seek(position);
//         // 额外的加密操作
//     }

//     virtual void Write(char data) {
//         // 额外的加密操作
//         stream->:Write(data);
//         // 额外的加密操作
//     }
// };

// class CryptoNetworkStream {
//     Stream* stream; // new NetworkStream();
// public:
//     virtual char Read(int number) {
//         // 额外的加密操作
//         stream->Seek(number);
//     }

//     virtual void Seek(int position) {
//         // 额外的加密操作
//         stream->Seek(position);
//         // 额外的加密操作
//     }

//     virtual void Write(char data) {
//         // 额外的加密操作
//         stream->Seek(data);
//         // 额外的加密操作
//     }
// };

// class CryptoMemoryStream {
//     Stream* stream; // new MemoryStream();
// public:
//     virtual char Read(int number) {
//         // 额外的加密操作
//         stream->Read(number);
//     }

//     virtual void Seek(int position) {
//         // 额外的加密操作
//         stream->Seek(position);
//         // 额外的加密操作
//     }

//     virtual void Write(char data) {
//         // 额外的加密操作
//         stream->Write(data);
//         // 额外的加密操作
//     }
// };

class BufferedStream : public Stream {
    Stream* stream;
    // ...
public:
    BufferedStream(Stream* s) : stream(s) {}
};

// class BufferedFileStream : public FileStream {
//     // ...
// };

// class BufferedNetworkStream : public NetworkStream {
//     // ...
// };

// class BufferedMemoryStream : public MemoryStream {
//     // ...
// };

// class CryptoBufferedFileStream : public FileStream {
// public:
//     virtual char Read(int number) {
//         // 额外的加密操作...
//         // 额外的缓冲操作...
//         FileStream::Read(number);
//     }
    
//     virtual void Seek(int position) {
//         // 额外的加密操作...
//         // 额外的缓冲操作...
//         FileStream::Seek(position);
//         // 额外的加密操作...
//         // 额外的缓冲操作...
//     }

//     virtual void Write(char data) {
//         // 额外的加密操作...
//         // 额外的缓冲操作...
//         FileStream::Write(data);
//         // 额外的加密操作...
//         // 额外的缓冲操作...
//     }
// };

void Process() {
    // 编译时装配
    // CryptoFileStream *fs1 = new CryptoFileStream;
    // BufferedFileStream *fs2 = new BufferedFileStream;
    // CryptoBufferedFileStream *fs3 = new CryptoBufferedFileStream;
    // 运行时装配
    FileStream* fs = new FileStream;
    CryptoStream* fs1 = new CryptoStream(fs);
    BufferedStream* fs2 = new BufferedStream(fs);
    // CryptoBufferedFileStream *fs3 = new CryptoBufferedFileStream();
    BufferedStream* fs4 = new BufferedStream(fs1);
}
