#pragma once
#include "HotDrink.h"
#include "HotDrinkFactory.h"
#include "CoffeeFactory.h"
#include "TeaFactory.h"
#include <functional>


class HotDrink;
class DrinkFactory
{
	std::map<std::string, std::unique_ptr<HotDrinkFactory>> factories;
public:
	DrinkFactory()
	{
		factories["coffee"] = std::make_unique<CoffeeFactory>();
		factories["tea"] = std::make_unique<TeaFactory>();
	}

	std::unique_ptr<HotDrink> make_drink(const std::string& name)
	{
		auto drink = factories[name]->make();
		drink->prepare(200); //oops did not account for volume
		return drink;
	}
};

class DrinkFuncFactory
{
	std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;
public:
	DrinkFuncFactory()
	{
		factories["tea"] = []{
			auto tea = std::make_unique<Tea>();
			tea->prepare(50);
			return tea;
		};

		factories["coffee"] = []{
			auto coffee =  std::make_unique<Coffee>();
			coffee->prepare(50);
			return coffee;
		};
	}

	std::unique_ptr<HotDrink> make_drink(const std::string& name)
	{
		return factories[name]();
	}

};