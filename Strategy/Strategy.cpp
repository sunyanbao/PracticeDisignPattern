
#include <iostream>

using namespace std;

class StrategyBase {
public:
    virtual void execute() = 0;
};

class StrategyA :public StrategyBase {
public:
    void execute() override
    {
        cout << "a" << endl;
    }
};

class StrategyB :public StrategyBase {
public:
    void execute() override
    {
        cout << "b" << endl;
    }
};

class Context {
public:
    Context() = default;
    ~Context()
    {
        if (m_strategy)
        {
            delete m_strategy;
            m_strategy = nullptr;
        }
    }

    void createStrategy(int type)
    {
        switch (type)
        {
        case 1:
        {
            m_strategy = new StrategyA;
            break;
        }
        case 2:
        {
            m_strategy = new StrategyB;
            break;
        }
        }
    }

    void exe()
    {
        m_strategy->execute();
    }

private:
    StrategyBase* m_strategy = nullptr;
};

int main()
{
    Context ctx;
    ctx.createStrategy(1);
    ctx.exe();
}
