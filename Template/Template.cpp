// 模板模式
// 把重复逻辑提取到父类，不重复部分实现延迟到子类

#include <iostream>

using namespace std;

class TestPaper {
public:
    void question1()
    {
        cout << "qeustion1:" << endl;
        getAnswer1();
    }

    void question2()
    {
        cout << "qeustion1:" << endl;
        getAnswer2();
    }

protected:
    virtual void getAnswer1() = 0;
    virtual void getAnswer2() = 0;
};

class WritePaper1 : public TestPaper {
protected:
    void getAnswer1() override
    {
        cout << "s1 answer qeustion1:" << endl;

    }

    void getAnswer2() override
    {
        cout << "s1 answer qeustion2:" << endl;

    }
};

class WritePaper2 : public TestPaper {
protected:
    void getAnswer1() override
    {
        cout << "s2 answer qeustion1:" << endl;

    }

    void getAnswer2() override
    {
        cout << "s2 answer qeustion2:" << endl;

    }
};

int main()
{
    TestPaper* t1 = new WritePaper1;
    TestPaper* t2 = new WritePaper2;
    t1->question1();
    t1->question2();

    t2->question1();
    t2->question2();
}
