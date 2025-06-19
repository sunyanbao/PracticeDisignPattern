// 状态模式
// 使用场景：对象的行为取决于他的状态，并且在运行时根据状态动态改变行为
// 划分state类，context类管理当前state

#include <iostream>

using namespace std;

class Customer {
public:
    enum Command {
        kOrder, // 订单
        kCancelOrder // 退单
    };

    void setCommand(Command s)
    {
        m_command = s;
    }

    Command command() const
    {
        return m_command;
    }

private:
    Command m_command = kOrder;
};

class CustomerOrder;
class State {
public:
    State(CustomerOrder* r, Customer* cus) : m_r(r), m_cus(cus)
    {

    }

    virtual ~State() = default;
    virtual void run() = 0;

protected:
    CustomerOrder* m_r = nullptr;
    Customer* m_cus = nullptr;
};

class CustomerOrder {
public:
    CustomerOrder(Customer* cus) : m_cus(cus)
    {
    }

    void setState(State* s)
    {
        m_state = s;
    }

    State* state() const
    {
        return m_state;
    }

    void exe()
    {
        if (m_state)
        {
            m_state->run();
        }
    }

private:
    State* m_state = nullptr;
    Customer* m_cus = nullptr;
};

class ServingState :public State
{
public:
    using State::State;
    void run() override
    {
        cout << "serving" << endl;
        cout << "order finish" << endl;
    }
};

class CookState : public State
{
public:
    using State::State;

    void run() override
    {
        cout << "cook" << endl;
        if (m_cus->command() == Customer::kCancelOrder)
        {
            cout << "cancel order" << endl;
        }
        else
        {
            ServingState* state = new ServingState(m_r, m_cus);
            m_r->setState(state);
        }
    }
};

class MakeOrderState :public State {
public:
    using State::State;

    void run() override
    {
        cout << "make order" << endl;
        if (m_cus->command() == Customer::kCancelOrder)
        {
            cout << "cancel order" << endl;
        }
        else
        {
            CookState* state = new CookState(m_r, m_cus);
            m_r->setState(state);
        }
    }
};

int main()
{
    Customer cus;
    CustomerOrder co(&cus);
    MakeOrderState* state = new MakeOrderState(&co, &cus);
    co.setState(state);
    co.exe();
    cus.setCommand(Customer::Command::kCancelOrder);
    co.exe();
}
