// 工厂方法模式（抽象工厂）
//

#include <iostream>

using namespace std;

class Operation {
public:
    virtual double getResult() = 0;

    void setParam(double lhs, double rhs)
    {
        m_lhs = lhs;
        m_rhs = rhs;
    }

protected:
    double m_lhs;
    double m_rhs;
};

class Add :public Operation
{
public:
    double getResult() override
    {
        return m_lhs + m_rhs;
    }
};

class Sub :public Operation {
public:
    double getResult() override
    {
        return m_lhs - m_rhs;
    }
};

class Factory {
public:
    virtual Operation* createOperation() = 0;
};

class AddFactory :public Factory {
public:
    Operation* createOperation() override
    {
        return new Add;
    }
};

class SubFactory :public Factory {
public:
    Operation* createOperation() override
    {
        return new Sub;
    }
};

int main()
{
    AddFactory af;
    Operation* ao = af.createOperation();
    ao->setParam(1, 2);
    cout << ao->getResult() << endl;

    SubFactory sf;
    Operation* so = sf.createOperation();
    so->setParam(5, 2);
    cout << so->getResult() << endl;
}
