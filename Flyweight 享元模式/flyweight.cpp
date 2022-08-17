#include <map>
#include <string>

class Font {
private:
    // unique object key
    std::string key;

    // object state
    // ...

public:
    Font(const std::string& key) {
        // ...
    }
};

class FontFacotry {
private:
    std::map<std::string, Font*> fontPool;

public:
    Font* GetFont(const std::string& key) {
        if (fontPool.find(key) == fontPool.end()) {
            fontPool[key] = new Font(key);
        }
        return fontPool[key];
    }

    void clear() {
        // ...
    }
};
