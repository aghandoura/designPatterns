#pragma once
#include "composite.h"
#include "test.h"




//a + (b + c)
//this can be optimized using google test framework
//todo look it up
AdditionExper build_addition_test_3(const double &a, const double &b, const double &c)
{
    return{ std::make_shared<Literal>(Literal(a)),
            std::make_shared<AdditionExper>(
               std::make_shared<Literal>(b),
               std::make_shared<Literal>(c))
    };
};

TEST(composition_test, eval)
{
    auto sum3 = build_addition_test_3(1, 2, 3);

    EXPECT_DOUBLE_EQ(sum3.eval(), 6);
}

TEST(composition_test, collect)
{
    auto sum3 = build_addition_test_3(1.3, 2.3, 3);

    std::vector<double> v;

    sum3.collect(v);

    EXPECT_DOUBLE_EQ(v[0], 1.3);
    EXPECT_DOUBLE_EQ(v[1], 2.3);
    EXPECT_DOUBLE_EQ(v[2], 3);
}
