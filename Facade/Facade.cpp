// 外观模式
// 为一个复杂子系统的一堆接口，提供一个统一的高层接口，使得这个子系统更容易使用。

#include <iostream>

using namespace std;

class SubFacade1 {
public:
    void fun1()
    {

    }
};

class SubFacade2 {
public:
    void fun2()
    {

    }
};

class SubFacade3 {
public:
    void fun3()
    {

    }
};

class Facade {
public:
    void fun()
    {
        m_f1.fun1();
        m_f2.fun2();
        m_f3.fun3();
    }

private:
    SubFacade1 m_f1;
    SubFacade2 m_f2;
    SubFacade3 m_f3;
};

int main()
{
    Facade f;
    f.fun();
}