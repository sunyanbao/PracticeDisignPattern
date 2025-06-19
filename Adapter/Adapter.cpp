// 适配器模式
// 使用场景：两个类做的事情相同或相似，但接口不同时。只有当双方都不容易修改的时候才考虑使用，应该尽量在设计之初就
// 避免接口不同。
// 当考虑使用第三方库时，也可以在设计时就考虑适配器模式。

#include <iostream>

using namespace std;

class RenderSystem {
public:
    virtual void render() = 0;

    RenderSystem() = default;
    virtual ~RenderSystem() = default;
};

class CustomSystem : public RenderSystem
{
public:
    void render() override
    {
        cout << "custom draw" << endl;
    }
};

class UESystem
{
public:
    void renderUE()
    {
        cout << "UE draw" << endl;
    }
};

class UEAdapter :public RenderSystem {
public:
    UEAdapter(UESystem* ue) : m_ue(ue)
    {

    }

    void render() override
    {
        if (m_ue)
        {
            m_ue->renderUE();
        }
    }

private:
    UESystem* m_ue = nullptr;
};

int main()
{
    UESystem ue;
    int type = 0;
    RenderSystem* rs = nullptr;
    switch (type)
    {
    case 0:
    {
        rs = new UEAdapter(&ue);
        break;
    }
    case 1:
    {
        rs = new CustomSystem();
        break;
    }
    default:
        break;
    }
    if (rs)
    {
        rs->render();
    }
}

