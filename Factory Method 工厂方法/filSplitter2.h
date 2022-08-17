
class ISplitter {
public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

class SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() = 0;
    virtual ~SplitterFactory() {}
};

class BinarySplitter : public ISplitter {

};

class TxtSplitter : public ISplitter {

};

class PictureSplitter : public ISplitter {

};

class VideoSplitter : public ISplitter {

};

class BinarySplitterFacory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() {
        return new BinarySplitter;
    }
};

class TxtSplitterFacory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() {
        return new TxtSplitter;
    }
};

class PictureSplitterFacory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() {
        return new PictureSplitter;
    }
};

class VideoSplitterFacory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() {
        return new VideoSplitter;
    }
};
