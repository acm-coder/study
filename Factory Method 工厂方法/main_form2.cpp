#include <string>
#include "filSplitter2.h"

class TextBox;
class ProGressBar;

class MainForm : public Form {
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
    ProGressBar* progressBar;
    SplitterFactory* factory;

public:
    MainForm(SplitterFactory* fc) : factory(fc) {}

    void Button1_click() {
        std::string filePath = txtFilePath->getText();
        int number = std::atoi(txtFileNumber->getText().data());

        ISplitter* splitter = factory->CreateSplitter(); // 多态new
        splitter->split();
    }
};
