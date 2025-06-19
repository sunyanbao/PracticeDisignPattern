// 访问者模式
//

// 访问者模式适用于被访问的类或数据结构类型相对稳定，使得数据结构和针对数据结构的操作解耦。
// 访问者要针对不同的被访问元素实现不同接口，因此如果被访者元素类型经常扩展，那么访问者就要修改添加新的访问接口，
// 所以这个情况不适用于这个模式。
// 例如下面的例子被访问的人类只分为男人女人，数据结构稳定，适用于这个模式。
// 使用双分派技术（互相传递基类指针），不同的访问者和不同的被访问者，最终的表现不同。

#include <iostream>
#include <string>

using namespace std;

class Action;
class Human {
public:
    virtual void accept(Action* act) = 0;
    virtual string type() = 0;
};

class Action {
public:
    virtual void visitMan(Human*) = 0;
    virtual void visitWoman(Human*) = 0;
};

class Man :public Human {
public:
    void accept(Action* act) override
    {
        act->visitMan(this);
    }

    string type() override
    {
        return "man";
    }
};

class Woman :public Human {
public:
    void accept(Action* act) override
    {
        act->visitWoman(this);
    }

    string type() override
    {
        return "woman";
    }
};

class SucessAction :public Action{
public:
    void visitMan(Human* human) override
    {
        cout << human->type() << ":";
        cout << "背后有一个强大的女人" << endl;
    }

    void visitWoman(Human* human) override
    {
        cout << human->type() << ":";
        cout << "背后有一个强大的男人" << endl;
    }
};

int main()
{
    SucessAction sa;
    Man m;
    Woman mm;
    m.accept(&sa);
    mm.accept(&sa);
}
