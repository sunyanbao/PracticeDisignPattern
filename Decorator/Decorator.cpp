// 装饰模式
#include <iostream>
#include <string>


using namespace std;

class Person {
public:
    Person() = default;
    virtual ~Person() = default;

    void showName()
    {
        cout << m_name;
    }

    virtual void show()
    {
        showName();
        cout << "person" << endl;
    }

private:
    string m_name;
};

class Decorator :public Person {
public:
    void setPerson(Person* per)
    {
        m_per = per;
    }

    void show() override
    {
        m_per->show();
    }

protected:
    Person* m_per;
};

class DecoratorA :public Decorator {
public:
    void show() override
    {
        m_per->show();
        funcA();
    }

    void funcA()
    {
        cout << "funcA" << endl;
    }
};

class DecoratorB :public Decorator {
public:
    void show() override
    {
        m_per->show();
        funcB();
    }

    void funcB()
    {
        cout << "funcB" << endl;
    }
};

// 装饰模式用于动态地给类添加更多功能，而不用修改原有类。把核心功能和装饰功能分开了。
// 当需要给类添加一些非核心、可有可无的功能时，可以考虑装饰模式。
// 被装饰的Person也可以抽象AbstractPerson, 此时Decorator要继承自AbstractPerson。如果Decorator不需要扩展，可以不抽象，
// ConcrateDecorator直接继承Person也可以。
int main()
{
    Person per;
    DecoratorA decA;
    DecoratorB decB;
    decA.setPerson(&per);
    decA.show();

    decB.setPerson(&decA);
    decB.show();
}
