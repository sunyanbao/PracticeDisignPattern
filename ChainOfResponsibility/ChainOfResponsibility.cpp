// 职责链模式
// 使多个对象都有机会处理请求，避免请求发送者和请求接收者的耦合关系。将请求接收对象连成一条链，沿着这条链传递
// 请求，知道请求被处理。

#include <iostream>

using namespace std;

class Request {
public:
    virtual void req() = 0;
    virtual int level() const = 0;
};

class ImproveSalary : public Request {
public:
    void req() override
    {
        cout << "request improve salary" << endl;
    }

    int level() const override
    {
        return 2;
    }
};

class Manager {
public:
    virtual void handleReq(Request* req) = 0;
    void setSuperior(Manager* man)
    {
        m_superior = man;
    }

    Manager* superior() const
    {
        return m_superior;
    }

protected:
    Manager* m_superior = nullptr;
};

class CommonManager :public Manager {
public:
    void handleReq(Request* req) override
    {
        if (req->level() < 1)
        {
            req->req();
            cout << "Common manager handle" << endl;
        }
        else
        {
            if (m_superior)
            {
                m_superior->handleReq(req);
            }
        }
    }
};

class ChiefManager :public Manager {
public:
    void handleReq(Request* req) override
    {
        if (req->level() < 2)
        {
            req->req();
            cout << "Chief manager handle" << endl;
        }
        else
        {
            if (m_superior)
            {
                m_superior->handleReq(req);
            }
        }
    }
};

class GeneralManager :public Manager {
public:
    void handleReq(Request* req) override
    {
        if (req->level() < 3)
        {
            req->req();
            cout << "General manager handle" << endl;
        }
        else
        {
            if (m_superior)
            {
                m_superior->handleReq(req);
            }
        }
    }
};

int main()
{
    CommonManager common;
    ChiefManager chief;
    GeneralManager gm;
    common.setSuperior(&chief);
    chief.setSuperior(&gm);
    Request* req = new ImproveSalary;
    common.handleReq(req);
}

