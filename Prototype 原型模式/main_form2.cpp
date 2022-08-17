#include <string>
#include "filSplitter2.h"

class TextBox;
class ProGressBar;

class MainForm : public Form {
    ISplitter* prototype;

public:
    MainForm(ISplitter* splitter) : prototype(splitter) {}

    void Button1_click() {

        ISplitter* splitter = prototype->clone(); // 克隆原型
        splitter->split();
    }
};
