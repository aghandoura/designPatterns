#pragma once
#include <ostream>
#include <string>
#include <sstream>


namespace shd //shape decorator
{
enum Color
{
	RED, BLUE, GREEN, WHITE, BLACK
};

inline std::ostream& operator<<(std::ostream& os, Color color)
{
	switch (color)
	{
		case RED:   return os <<"red ";
		case BLUE:  return os <<"blue ";
		case GREEN: return os <<"green ";
		case WHITE: return os <<"white ";
		case BLACK: return os <<"black ";
		default: return os << "";
	}
}

struct Shape
{
	virtual std::string str() = 0;
};

struct Circle : Shape
{
	float radius;

	std::string str() override
	{
		std::ostringstream oss;
		oss << "circle with radius " << radius;
		return oss.str();
	};

	Circle(const float &radius)
		:radius{radius}
	{}
};

struct Rectangle : Shape
{
	float side;

	std::string str() override
	{
		std::ostringstream oss;
		oss << " rectangle with side " << side;
		return oss.str();
	};

	Rectangle(const float& side)
		:side{side}
	{}
};
	
//decorator is used to extend shapes without changing its code
template<typename T>
struct ColoredShape : T
{
	Color color;

	//argument unpacked and forwarded T:T{args...}
	template<typename ...Args>
	ColoredShape(const Color& color, Args ...args)
		:T::T{args...},
		color{color}
	{}

	std::string str() override
	{
		std::ostringstream oss;
		oss << T::str();
		oss << " has color ";
		oss << color;
		return oss.str();
	}
};

template<typename T>
struct TranspShape : T
{
	uint8_t transparency;

	template<typename ...Args>
	TranspShape(const uint8_t& transp, Args ...args)
		:T::T{args...},
		transparency{transp}
	{}

	std::string str() override
	{
		std::ostringstream oss;
		oss << T::str();
		oss << " has transparency ";
		oss << ((transparency / 255.f) * 100.f);
		oss << " % ";
		return oss.str();
	}
};
}
