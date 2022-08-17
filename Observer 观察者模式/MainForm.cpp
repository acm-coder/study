#include "FileSplitter.h"

class TextBox;

class MainForm : public Form {
    TextBox* txtFilePath;
    TextBox* txtFileNumber;

    ProGressBar* progressBar;

public:
    void Button1_Click() {
        std::string filePath = txtFilePath->getText();
        int number = std::atoi(txtFileNumber->getText().data());

        FileSplitter splitter(filePath, number, progressBar);
        splitter.split();
    }
};
