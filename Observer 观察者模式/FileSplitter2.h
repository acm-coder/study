#include <string>

class IProgress {
public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress() {}
};

class FileSplitter {
    std::string m_filePath;
    int m_fileNumber;

    IProgress* m_iprogress; // 变动

public:
    FileSplitter(const std::string& filePath, int fileNumber,
        IProgress* iprogress // 变动
        ) :
        m_filePath(filePath), m_fileNumber(fileNumber), m_iprogress(iprogress) {}
    
    void split() {
        // 1. 读取文件

        // 2. 分批次向小文件中写入

        for (int i = 0; i < m_fileNumber; ++ i) {
            // ...
            if (m_iprogress) {
                float progressValue = m_fileNumber;
                progressValue = (i + 1) / progressValue;
                m_iprogress->DoProgress(progressValue); // 更新进度条
            }
        }
    }
};