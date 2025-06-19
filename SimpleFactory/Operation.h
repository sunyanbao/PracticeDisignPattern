#pragma once

#include <float.h>

class Operation {
public:
    void setLhs(double val)
    {
        m_lhs = val;
    }

    double getLhs() const
    {
        return m_lhs;
    }

    void setRhs(double val)
    {
        m_rhs = val;
    }

    double getRhs() const
    {
        return m_rhs;
    }

    virtual double getRes() = 0;

protected:
    double m_lhs = 0.0;
    double m_rhs = 0.0;
};

class Add : public Operation {
public:
    double getRes() override
    {
        return m_lhs + m_rhs;
    }
};

class Sub : public Operation {
public:
    double getRes() override
    {
        return m_lhs - m_rhs;
    }
};

class Mul :public Operation {
public:
    double getRes() override
    {
        return m_lhs * m_rhs;
    }
};

class Div :public Operation {
public:
    double getRes() override
    {
        if (m_rhs < DBL_EPSILON)
        {
            return 0;
        }
        return m_lhs / m_rhs;
    }
};