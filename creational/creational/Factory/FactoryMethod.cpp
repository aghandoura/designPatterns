#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <sstream>
#include "../Header.h"

//Factory is mainly used to solve the following problems:
//object creation can become too convoluted (complicated)
//constructor name can be imposed by the container so it will be less 
// descriptive
//
// Factory types:
//Object created can be outsourced to:
//a seperate function (Factory method)
//a seperate class (a factory)
//a heierarcie of classes (abstract factory)

//Here an example not using factory
//where costructor is not descriptive

#if 0
enum class PointType
{
	cartesian,
	polar
};

class Point
{
public:
	float x, y;
	Point(const float a, const float b, PointType t = PointType::cartesian)
	{
		if (t == PointType::cartesian)
		{
			x = a;
			y = b;
		}else //polar
		{
			x = a * cos(b);
			y = a * sin(b);
		}
	}
};
#else //using factory method

class Point
{
private:
	Point(const float a, const float b)
	: x{a},
	  y{b}
	{
	}

public:
	static Point NewCartesian(const float x, const float y)
	{
		return { x, y };
	}

	static Point NewPolar(const float r, const float theta)
	{
		return { r * cos(theta), r * sin (theta) };
	}

	friend std::ostream& operator<< (std::ostream& os, const Point& p)
	{
		return os <<
     			" x: " << p.x <<
	    		" y: " << p.y 
	    		<< std::endl;
	}


	float x, y;
};

int FactoryMethod_test()
{
	auto c = Point::NewCartesian(1, 2);
	std::cout << c<< std::endl;
	auto p = Point::NewPolar(5, M_PI_4);

	std::cout << p<< std::endl;
	return 0;
}

#endif