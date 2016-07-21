// Dependency inversion principle:

// High level module (reporting Module) should not depend on low level module (console logger)
// both should depend on abstraction (Logger Interface):
// Dependency on interface and supertype is better than dependency
// on concrete types
// Inversion of control: creating abstraction in order to replace dependencies
// Dependency injection: use of sw framework (exmp: boost) to ensure components' dependencies
//from boost github: https://github.com/boost-experimental/di
// Do I need Dependency Injection?
// DI provides loosely coupled code (separation of business logic and object creation)
// DI provides easier to maintain code (different objects might be easily injected)
// DI provides easier to test code (fakes objects might be injected)

// in commented code we have explicitly created an engine when we need dependency to be automatically
// handled
// di is used to fix that

//NOTE: to build this di from boost should be included (it requires c++14 support)

#include "stdafx.h"
#include "di.hpp"
#include <iostream>
#include <ostream>
#include <memory>

struct ILogger
{
	virtual ~ILogger(){}
	virtual void Log(const std::string& s) = 0;
};

struct ConsoleLogger : ILogger
{
	void Log(const std::string& s) override
	{
		std::cout << "Log " << s.c_str() << std::endl;
	}
};

struct Engine
{
	float volume = 5.0;
	int horse_power = 100;

	friend std::ostream& operator<<(std::ostream& os, const Engine& obj)
	{
		return os
			<< "volume: " << obj.volume
			<< " horse_power: " << obj.horse_power;
	}
};

struct Car
{
	std::shared_ptr<Engine> engine;

	//Ilogger is used instead of logger so logging mechanism can be changed painlessly:
	std::shared_ptr<ILogger> logger;

	Car(const std::shared_ptr<Engine>& e, const std::shared_ptr<ILogger>& l)
	:engine{ e }, logger{l}
	{
		logger->Log("Created a Car");
	}

	friend std::ostream& operator<<(std::ostream& os, const Car& obj)
	{
		return os
			<< "Car with engine: " << *obj.engine;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
#if 0 //dependency
	auto e = std::make_shared<Engine>();
	auto c = std::make_shared<Car>(e);
#endif

	using namespace boost;

	auto injector = di::make_injector(
		di::bind<ILogger>().to<ConsoleLogger>()
		);

	auto c = injector.create<std::shared_ptr<Car>>();

	std::cout << *c << std::endl;

	getchar();
	return 0;
}