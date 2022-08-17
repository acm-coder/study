#include "FileSplitter2.h"

class TextBox;

class MainForm : public Form, public IProgress {
    TextBox* txtFilePath;
    TextBox* txtFileNumber;

    ProGressBar* progressBar;

public:
    void Button1_Click() {
        std::string filePath = txtFilePath->getText();
        int number = std::atoi(txtFileNumber->getText().data());

        FileSplitter splitter(filePath, number, this);
        splitter.split();
    }

    virtual void DoProgress(float value) {
        progressBar->setValue(value);
    }
};
