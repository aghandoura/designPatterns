#pragma once
#include "composite.h"
#include "test.h"




//a + (b + c)
//this can be optimized using google test framework
//todo look it up
struct addition_test_3
{
    AdditionExper expr;
    addition_test_3(const double &a, const double &b, const double &c)
        :expr{
            std::make_shared<Literal>(Literal(a)),
            std::make_shared<AdditionExper>(
                std::make_shared<Literal>(b),
                std::make_shared<Literal>(c))
    }
    {}
    
};

TEST(composition_test, eval)
{
    addition_test_3 sum3(1, 2, 3);

    EXPECT_DOUBLE_EQ(sum3.expr.eval(), 6);
}

TEST(composition_test, collect)
{
    addition_test_3 sum3(1.3, 2.3, 3);

    std::vector<double> v;

    sum3.expr.collect(v);

    EXPECT_DOUBLE_EQ(v[0], 1.3);
    EXPECT_DOUBLE_EQ(v[1], 2.3);
    EXPECT_DOUBLE_EQ(v[2], 3);
}
