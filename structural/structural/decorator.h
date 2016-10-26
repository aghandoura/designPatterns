#pragma once
#include <functional>
#include <iostream>
#include <string>

//functional decorator (like in python)

struct Logger
{
	std::function<void()> func;
	std::string name;

	Logger(const std::function<void()>& func, const std::string& name)
		: func{func},
		  name{name}
	{
	}

	void operator()() const
	{
		std::cout << "entering: " << name << std::endl;
		func();
		std::cout << "exiting: "  << name << std::endl;
	}
};

template <typename Func>
auto make_logger_templ(Func func, std::string name)
{
	return Logger_templ<Func>(func, name);
}

template <typename Func>
struct Logger_templ
{
	Func func;
	std::string name;

	Logger_templ(const Func& func, const std::string& name)
		: func{func},
		  name{name}
	{
	}

	void operator()() const
	{
		std::cout << "entering: " << name << std::endl;
		func();
		std::cout << "exiting: "  << name << std::endl;
	}
};

//partial specialization
template<typename> struct Logger_variadic;

template<typename R, typename ...Args>
struct Logger_variadic<R(Args...)>
{
	std::function<R(Args...)> func;
	std::string name;

	Logger_variadic(const std::function<R(Args...)>& func, const std::string& name)
		: func(func),
		  name(name)
	{
	}

	R operator() (Args ...args)
	{
		std::cout << "entering: " << name << std::endl;
		R result = func(args...);
		std::cout << "exiting: "  << name << std::endl;
		return result;
	}
};

template <typename R, typename ...Args>
auto
make_Logger_variadic(R (*func)(Args...), std::string name)
{
	return Logger_variadic<R(Args...)>{
		std::function<R(Args...)>(func), name };
};
