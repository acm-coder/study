#include <string>
#include <vector>
#include <algorithm>

class IProgress {
public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress() {}
};

class FileSplitter {
    std::string m_filePath;
    int m_fileNumber;

    std::vector<IProgress*> m_iprogressVector; // 抽象通知机制，支持多个观察者

public:
    FileSplitter(const std::string& filePath, int fileNumber) :
        m_filePath(filePath), m_fileNumber(fileNumber) {}

    void addIProgress(IProgress* iprogress) {
        m_iprogressVector.push_back(iprogress);
    }

    void removeIProgress(IProgress* iprogress) {
        m_iprogressVector.erase(std::find(m_iprogressVector.begin(),
                m_iprogressVector.end(), iprogress));
    }

    void split() {
        // 1. 读取文件

        // 2. 分批次向小文件中写入

        for (int i = 0; i < m_fileNumber; ++ i) {
            // ...
            float progressValue = m_fileNumber;
            progressValue = (i + 1) / progressValue;
            onProgress(progressValue);
        }
    }

protected:
    virtual void onProgress(float value) {
        for (auto& iprogress : m_iprogressVector)
            iprogress->DoProgress(value);
    }

};