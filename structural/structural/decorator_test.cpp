#include "test.h"
#include "decorator.h"
#include "shape_decorator.h"

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

using namespace shd;
TEST(shape_decorator, tranparency_and_color)
{
	ColoredShape<Circle> red_circle {RED, 5.0f};

	EXPECT_DOUBLE_EQ(red_circle.radius, 5.0);
	EXPECT_EQ(red_circle.color, RED);

	//note args order
	TranspShape<ColoredShape<Rectangle>> green_transp_rectangele{120, GREEN, 9.4f};

	EXPECT_EQ(green_transp_rectangele.transparency, 120) << green_transp_rectangele.str();
	EXPECT_EQ(green_transp_rectangele.color, GREEN);
	EXPECT_FLOAT_EQ(green_transp_rectangele.side, 9.4f);
}
