#pragma once

#include <memory>

#include "Operation.h"

class OperationFactory {
public:
    static OperationFactory& getInstance()
    {
        static OperationFactory ins;
        return ins;
    }

    static std::shared_ptr<Operation> createOperate(char op)
    {
        switch (op)
        {
        case '+':
        {
            return std::make_shared<Add>();
        }
        case '-':
        {
            return std::make_shared<Sub>();
        }
        case 'x':
        {
            return std::make_shared<Mul>();
        }
        case '/':
        {
            return std::make_shared<Div>();
        }
        default:
            break;
        }
    }
};