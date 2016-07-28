#define _USE_MATH_DEFINES

#include "math.h"
#include "iostream"
#include "../Header.h"
class Point
{
private:
	Point(const float a, const float b)
	: x{a},
	  y{b}
	{
	}

	class PointFactory
	{
	public:
		static Point NewCartesian(const float x, const float y)
		{
			return { x, y };
		}

		static Point NewPolar(const float r, const float theta)
		{
			return { r * cos(theta), r * sin (theta) };
		}
	};
public:

	friend std::ostream& operator<< (std::ostream& os, const Point& p)
	{
		return os <<
     			" x: " << p.x <<
	    		" y: " << p.y 
	    		<< std::endl;
	}


	float x, y;
	static class PointFactory factory;
};


int InnerFactory_test()
{

	//if we want to expose Pointfactory move it to public
	//auto p = Point::PointFactory::NewCartesian(1, 2);

	auto p = Point::factory.NewCartesian(1, 2);


	std::cout << p<< std::endl;
	return 0;
}
