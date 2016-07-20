// Liskov principle:

// objects in a program should be replaceable with instance of theire subtypes
// without altering the correctness of the program

// this example breaks the principle
// in process square is not replaceable by rectangle
// using inheritance to define square is the wrong way to go
// (Factory should solve this)

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

class Rectangle
{
protected:
	int width, height;
public:
	Rectangle(int w, int h)
		:width{ w }, height{ h }{}

	virtual	int getWidth()
	{
		return width;
	};

	virtual	int getHeight()
	{
		return height;
	}

	virtual void setWidth(const int w)
	{
		width = w;
	}

	virtual void setHeight(const int h)
	{
		height = h;
	}
	int area() const{ return width * height; }
};

void process(Rectangle& r)
{
	int w = r.getWidth();
	r.setHeight(10);

	std::cout << "expected area: " << w * 10 << " got: " << r.area() << std::endl;
}

class Square : public Rectangle
{
public:
	Square(int size) : Rectangle(size, size){}

	void setWidth(const int s)
	{
		width = height = s;
	}

	void setHeight(const int s)
	{
		width = height = s;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Rectangle r { 5, 5};
	process(r);

	Square s {5};
	process(s);
	
	getchar();
	return 0;
}

