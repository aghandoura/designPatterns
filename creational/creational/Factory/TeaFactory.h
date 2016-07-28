#pragma once
#include "HotDrinkFactory.h"

class HotDrink;
class TeaFactory : public HotDrinkFactory
{
public:
	std::unique_ptr<HotDrink> make() override
	{
		return std::make_unique<Tea>();
	}
};
