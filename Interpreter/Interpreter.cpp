// 解释器模式
// 对发生频率比较高的问题进行解释，应用解释器模式的好处是易于扩展

#include <iostream>

using namespace std;

class Context {

};

class Expresion {
public:
    virtual void interpret(Context*) = 0;
};

class ExpresionA : public Expresion {
public:
    void interpret(Context* c) override
    {
        cout << "ExpresionA" << endl;
    }
};

class ExpresionB : public Expresion {
public:
    void interpret(Context* c) override
    {
        cout << "ExpresionB" << endl;
    }
};

int main()
{

}
