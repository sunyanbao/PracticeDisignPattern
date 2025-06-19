// 观察者模式
//

#include <iostream>
#include <set>

using namespace std;

class Subject {
public:
    virtual void updateA() = 0;
    virtual void updateB() = 0;
};

class SubA :public Subject {
public:
    void updateA() override
    {
        cout << "suba update a" << endl;
    }
    void updateB() override
    {
        cout << "suba update b" << endl;

    }
};

class SubB :public Subject {
public:
    void updateA() override
    {
        cout << "subb update a" << endl;

    }
    void updateB() override
    {
        cout << "subb update b" << endl;

    }
};

class Observer {
public:
    void attach(Subject* s)
    {
        m_subs.insert(s);
    }
    void detach(Subject* s)
    {
        m_subs.erase(s);
    }
    virtual void notify() = 0;

protected:
    set<Subject*> m_subs;
};

class OberverA :public Observer {
public:
    void notify() override
    {
        for (auto&& sub : m_subs)
        {
            sub->updateA();
        }
    }
};

class OberverB :public Observer {
public:
    void notify() override
    {
        for (auto&& sub : m_subs)
        {
            sub->updateB();
        }
    }
};

int main()
{
    OberverA oa;
    SubA sa1;
    SubA sa2;
    SubB sb1;
    oa.attach(&sa1);
    oa.attach(&sa2);
    oa.attach(&sb1);
    oa.notify();
}
