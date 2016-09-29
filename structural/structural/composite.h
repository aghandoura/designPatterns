#pragma once
#include <memory>
#include <vector>

//2+(3+4)
struct Expression
{
    virtual double eval() = 0;
    //visitor pattern to collect all literal of expression
    virtual void collect(std::vector<double>& ) = 0;
};

struct Literal : Expression
{
    double value;

    explicit Literal(const double &val)
        :value{val}
    {
    }

    double eval() override
    {
        return value;
    }

    void collect(std::vector<double> &v) override
    {
        v.push_back(value);
    }

};

struct AdditionExper : Expression
{
    std::shared_ptr<Expression> left, right;


    AdditionExper(const std::shared_ptr<Expression>& expression, const std::shared_ptr<Expression>& expression1)
        : left(expression),
          right(expression1)
    {
    }


    double eval() override
    {
        return left->eval() + right->eval();
    }

    //not thread safe
    void collect(std::vector<double>& v) override
    {
        left->collect(v);
        right->collect(v);
    }
};
