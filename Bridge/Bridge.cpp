// 桥接模式
// 场景：当系统需要进行多角度分类，并且每个角度都需要独立变化时，使用桥接模式减少耦合。
// 桥接模式使用了聚合组合的思想，避免继承的强耦合

#include <iostream>

using namespace std;

class Soft {
public:
    virtual void run() = 0;
};

class Phone {
public:
    virtual void run() = 0;
    void setSoft(Soft* s)
    {
        m_soft = s;
    }

    Soft* soft() const
    {
        return m_soft;
    }

protected:
    Soft* m_soft = nullptr;
};

class IPhone :public Phone
{
public:
    void run() override
    {
        cout << "iphone:" << endl;
        m_soft->run();
    }
};

class HuaweiPhone : public Phone {
public:
    void run() override
    {
        cout << "huawei:" << endl;
        m_soft->run();
    }
};

class Game : public Soft {
public:
    void run() override
    {
        cout << "game" << endl;
    }
};

class Notebook : public Soft {
public:
    void run() override
    {
        cout << "notebook" << endl;
    }
};

int main()
{
    Phone* p = new IPhone;
    Soft* s = new Game;
    p->setSoft(s);
    p->run();
}
