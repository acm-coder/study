#include "FileSplitter3.h"

class TextBox;

class ConsoleNotifier : public IProgress {
public:
    virtual void DoProgress(float value) {
        cout << ".";
    }
};

class MainForm : public Form, public IProgress {
    TextBox* txtFilePath;
    TextBox* txtFileNumber;

    ProGressBar* progressBar;

public:
    void Button1_Click() {
        std::string filePath = txtFilePath->getText();
        int number = std::atoi(txtFileNumber->getText().data());

        ConsoleNotifier cn;

        FileSplitter splitter(filePath, number);

        splitter.addIProgress(this);
        splitter.addIProgress(&cn);

        splitter.split();

        splitter.removeIProgress(this);
    }

    virtual void DoProgress(float value) {
        progressBar->setValue(value);
    }
};
