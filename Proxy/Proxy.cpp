// 代理模式
//

#include <iostream>


using namespace std;
class Businese
{
public:
    virtual void sell() = 0;
};

class BusinessCompany :public Businese {
public:
    void sell() override
    {
        cout << "sell something" << endl;
    }
};

class BusinessProxy : public Businese {
public:
    void setBusinessPartner(Businese* bu)
    {
        m_bu = bu;
    }

    void sell() override
    {
        m_bu->sell();
    }

private:
    Businese* m_bu;
};

int main()
{
    BusinessCompany bc;
    BusinessProxy bp;
    bp.setBusinessPartner(&bc);
    bp.sell();
}
