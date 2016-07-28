#include <iostream>
#include <memory>
#include <map>

#include "../Header.h"
#include "HotDrink.h"


//this will be ugly if we add more Hot drinks
#if 0

static std::unique_ptr<HotDrink> make_drink(const std::string type)
{
	std::unique_ptr<HotDrink> drink;

	if (type == "tea")
	{
		drink = std::make_unique<Tea>();
		drink->prepare(200);
	} else if (type == "coffee")
	{
		drink = std::make_unique<Coffee>();
		drink->prepare(200);
	}
	else
	{
		std::cout << "use tea or coffee " << std::endl;
	}
	return drink;
	
}

#else
#endif
#include "DrinkFactory.h"

int AbstractFactory_test()
{
	//auto d = make_drink("coffee");
	DrinkFactory df;
	df.make_drink("tea");
	DrinkFuncFactory dff;
	dff.make_drink("coffee");

	return 0;
}
