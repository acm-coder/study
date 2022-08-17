
class House {
    // ...
};

class HouseBuilder {
public:
    House* GetResult() {
        return pHouse;
    }

    void Init() {
        this->BuildPart1();
        for (int i = 0; i < 4; ++ i) this->BuildPart2();
        bool flag = this->BuildPart3();
        if (flag) this->BuildPart4();
        this->BuildPart5();
    }

    virtual ~HouseBuilder() {}

protected:
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual bool BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;

protected:
    House* pHouse;
};

class StoneHouseBuilder : public HouseBuilder {
protected:
    virtual void BuildPart1() {
        // pHouse->Part1 = ...;
    }

    virtual void BuildPart2() {

    }

    virtual bool BuildPart3() {

    }

    virtual void BuildPart4() {

    }

    virtual void BuildPart5() {

    }
};

int main() {
    HouseBuilder* house_builder = new StoneHouseBuilder;
    house_builder->Init();
    House* house = house_builder->GetResult();
    return 0;
}

