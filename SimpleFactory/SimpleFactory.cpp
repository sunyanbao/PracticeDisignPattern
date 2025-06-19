
#include <iostream>
#include "OperationFactory.h"

using namespace std;
int main()
{
    char op = '+';
    auto oper = OperationFactory::getInstance().createOperate(op);
    oper->setLhs(1.2);
    oper->setRhs(5.0);
    auto res = oper->getRes();
    cout << res << endl;
}

