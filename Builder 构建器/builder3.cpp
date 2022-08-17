
class House {
    // ...
};

class HouseBuilder {
public:
    House* GetResult() {
        return pHouse;
    }

    virtual ~HouseBuilder() {}

    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual bool BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;

protected:
    House* pHouse;
};

class StoneHouse : public House {
// ...
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

class HouseDirectory {
public:
    HouseDirectory(HouseBuilder* houseBuilder) : pHouseBuilder(houseBuilder) {}
    House* Construct() {
        pHouseBuilder->BuildPart1();
        for (int i = 0; i < 4; ++ i) pHouseBuilder->BuildPart2();
        bool flag = pHouseBuilder->BuildPart3();
        if (flag) pHouseBuilder->BuildPart4();
        pHouseBuilder->BuildPart5();
        return pHouseBuilder->GetResult();
    }

private:
    HouseBuilder* pHouseBuilder;
};

int main() {
    HouseBuilder* house_builder = new StoneHouseBuilder;
    House* house = HouseDirectory(house_builder).Construct();
    return 0;
}

