#include "test.h"
#include "decorator.h"

double add(double a, double b)
{
	return a + b;
}

TEST(decorator_variadic, addLogger)
{
	//auto logger = make_logger_templ( []() { std::cout << "hello in function code" << std::endl; }, "printHelloFunc" );

	//auto logger2 = make_logger_templ( myFunc, "myFunc" );
	//logger();
	//logger2();
	auto logged_add = make_Logger_variadic( add, "addFunc" );
	EXPECT_DOUBLE_EQ(logged_add(4.5, 3.2), 7.7);

}
