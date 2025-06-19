// 中介者模式
// 当有多个对象需要进行多对多复杂交互时，可以用中介者模式
// 符合迪米特法则（最少知道原则）：如果两个对象不必直接通信，就不应该发生直接调用,可以通过第三者转发调用
// 优点：对象间的交互进行解耦
// 缺点：中介者需要与所有对象交互，复杂度高，难以扩展

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Mediator;
class Trader {
public:
    virtual void trade() = 0;
    virtual void onNotify(Trader* tra, string message) = 0;
    void setMediator(Mediator* media);

protected:
    Mediator* m_mediator = nullptr;
};

class Mediator {
public:
    void addTrader(Trader* tra)
    {
        m_traders.push_back(tra);
    }

    virtual void trade(Trader* tra, string message) = 0;

protected:
    vector<Trader*> m_traders;
};

void Trader::setMediator(Mediator* media)
{
    m_mediator = media;
    m_mediator->addTrader(this);
}

class HouseAgent : public Mediator
{
public:
    void trade(Trader* tra, string message) override
    {
        for (auto&& t : m_traders)
        {
            if (t == tra)
            {
                continue;
            }
            t->onNotify(tra, message);
        }
    }
};

class HouseSeller : public Trader
{
public:
    void trade() override
    {
        m_mediator->trade(this, "I want to sell a house");
    }

    void onNotify(Trader* tra, string message) override
    {
        cout << "House seller get message: " << message << endl;
    }
};

class HouseBuyer : public Trader {
public:
    void trade() override
    {
        m_mediator->trade(this, "I want to buy a house");
    }

    void onNotify(Trader* tra, string message) override
    {
        cout << "House buyer get message: " << message << endl;
    }
};

int main()
{
    Trader* seller = new HouseSeller;
    Trader* buyer = new HouseBuyer;
    Mediator* mediator = new HouseAgent;
    seller->setMediator(mediator);
    buyer->setMediator(mediator);
    seller->trade();
    buyer->trade();
}
