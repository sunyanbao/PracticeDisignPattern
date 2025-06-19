// 建造者模式
// 当一个复杂对象的构建逻辑固定，构建细节变化时，可以使用建造者模式，把构建逻辑抽离出来。

#include <iostream>

using namespace std;

class Person {
public:
    virtual void buildHead() = 0;
    virtual void buildArm() = 0;
    virtual void buildBody() = 0;
    virtual void buildLeg() = 0;
};

class FatPerson :public Person
{
public:
    void buildHead() override
    {

    }
    void buildArm() override
    {

    }
    void buildBody() override
    {

    }
    void buildLeg() override
    {
        
    }
};

class ThinPerson :public Person
{
public:
    void buildHead() override
    {

    }
    void buildArm() override
    {

    }
    void buildBody() override
    {

    }
    void buildLeg() override
    {

    }
};

class Builder {
public:
    Person* buildPerson(int type)
    {
        Person* per = nullptr;
        if (type == 0)
        {
             per = new FatPerson;
        }
        else
        {
            per = new ThinPerson;
        }

        per->buildHead();
        per->buildBody();
        per->buildArm();
        per->buildLeg();
        return per;
    }
};

int main()
{
    Builder bui;
    bui.buildPerson(0);
}
