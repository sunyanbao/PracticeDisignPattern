// 原型模式
// 使用场景：对象需要频繁创建，并且初始化信息不变

#include <iostream>
#include <string>

using namespace std;

class Resume {
public:
    void setName(const string& name)
    {

    }

    void setAge()
    {

    }

    void setExperirence()
    {

    }

    virtual Resume* clone() = 0;

    Resume() = default;
    virtual ~Resume() = default;
};

class EngineerResume :public Resume
{
public:
    Resume* clone() override
    {
        return new EngineerResume(*this);
    }
};

int main()
{
    Resume* res1 = new EngineerResume;
    res1->setName("Bob");
    Resume* res2 = res1->clone();
    res2->setName("Tony");

    delete res1;
    delete res2;
}