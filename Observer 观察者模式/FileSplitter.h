#include <string>

class FileSplitter {
    std::string m_filePath;
    int m_fileNumber;

    ProgressBar* m_progressBar; // 变动

public:
    FileSplitter(const std::string& filePath, int fileNumber,
        ProGressBar* progressBar // 变动
        ) :
        m_filePath(filePath), m_fileNumber(fileNumber), m_progressBar(progressBar) {}
    
    void split() {
        // 1. 读取文件

        // 2. 分批次向小文件中写入

        for (int i = 0; i < m_fileNumber; ++ i) {
            // ...
            if (m_progressBar) // 变动
                m_progressBar->setValue((i + 1) / m_fileNumber); // 更新进度条
        }
    }
};