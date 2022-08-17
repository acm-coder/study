#include <string>
#include "filSplitter1.h"

class TextBox;
class ProGressBar;

class MainForm : public Form {
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
    ProGressBar* progressBar;

public:
    void Button1_click() {
        std::string filePath = txtFilePath->getText();
        int number = std::atoi(txtFileNumber->getText().data());

        ISplitter* splitter = new BinarySplitter;

        splitter->split();
    }
};
