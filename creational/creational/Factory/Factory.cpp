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

public:

	friend std::ostream& operator<< (std::ostream& os, const Point& p)
	{
		return os <<
     			" x: " << p.x <<
	    		" y: " << p.y 
	    		<< std::endl;
	}


	float x, y;
	friend class PointFactory;
};

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

int Factory_test()
{
	auto c = PointFactory::NewCartesian(1, 2);
	std::cout << c<< std::endl;
	auto p = PointFactory::NewPolar(5, M_PI_4);

	std::cout << p<< std::endl;
	return 0;
}

