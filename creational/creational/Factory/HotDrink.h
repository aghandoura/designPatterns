#pragma once
#include <memory>
#include <map>
#include <string>
#include <iostream>

class HotDrink
{
public:
	virtual void prepare(const float volume) = 0;
	virtual ~HotDrink(){};
};

class Tea:public HotDrink
{
public:
	void prepare(const float volume) override
	{
		std::cout << "Take tea bag Boil " << volume << "ml" << " water then add tea" <<std::endl;
	}
	virtual ~Tea(){};
};

class Coffee:public HotDrink
{
public:
	void prepare(const float volume) override
	{
		std::cout << "Grind some beans Add Coffee then Boil " << volume << "ml" << " water" <<std::endl;
	}
	virtual ~Coffee(){};
};
