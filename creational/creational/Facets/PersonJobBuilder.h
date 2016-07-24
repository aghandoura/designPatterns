#pragma once
#include "PersonBuilder.h"


class PersonJobBuilder : public PersonBuilder
{
	typedef PersonJobBuilder Self;

public:
	explicit PersonJobBuilder(Person& p)
		:PersonBuilder(p)
	{}

	Self& at(const std::string comp)
	{
		person.company_name = comp;
		return *this;
	}

    Self& as_a(const std::string pos)
	{
		person.position= pos;
		return *this;
	}

    Self& earning(const int income)
	{
		person.income = income ;
		return *this;
	}
};