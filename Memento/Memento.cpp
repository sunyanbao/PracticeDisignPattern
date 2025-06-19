// 备忘录模式
// 使用场景：当一个类的一部分状态需要被保存和恢复时。如果类的全部属性都要被保存，可以直接保存clone（原型模式）对象。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CharatorMemento {
public:
    void setHealth(int h)
    {
        m_health = h;
    }

    int health() const
    {
        return m_health;
    }

    void setMagic(int m)
    {
        m_magic = m;
    }

    int magic() const
    {
        return m_magic;
    }

private:
    int m_health = 0;
    int m_magic = 0;
};

class GameCharactor {
public:
    shared_ptr<CharatorMemento> createMemmento()
    {
        shared_ptr<CharatorMemento> memento = make_shared<CharatorMemento>();
        memento->setHealth(m_health);
        memento->setMagic(m_magic);
        return memento;
    }

    void setMemmento(shared_ptr<CharatorMemento> mem)
    {
        cout << "load memento!" << endl;
        m_health = mem->health();
        m_magic = mem->magic();
    }

    void display()
    {
        cout << "health:" << m_health << endl;
        cout << "magic:" << m_magic << endl;
    }

    void fight()
    {
        cout << "fight!" << endl;
        m_health = 1;
        m_magic = 1;
    }

    GameCharactor()
    {
        m_health = 10;
        m_magic = 10;
    }

private:
    int m_health = 0;
    int m_magic = 0;
    string m_name;
    string m_apperance;
};

class MementoManager {
public:
    void addMemento(shared_ptr<CharatorMemento> mem)
    {
        m_mementoList.push_back(mem);
    }

    shared_ptr<CharatorMemento> getLastMemento()
    {
        return m_mementoList.back();
    }

private:
    vector<shared_ptr<CharatorMemento>> m_mementoList;
};

int main()
{
    GameCharactor cha;
    cha.display();
    MementoManager manager;
    manager.addMemento(cha.createMemmento());
    cha.fight();
    cha.display();
    cha.setMemmento(manager.getLastMemento());
    cha.display();
}
