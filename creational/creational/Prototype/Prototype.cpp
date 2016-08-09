// A very simple example showing the prototype pattern and its usage 
#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "../Header.h"
#include <utility>

using namespace std;

struct Address
{
	string street;
	string city;
	int suite;

	friend ostream& operator<<(ostream& os, const Address& ad)
	{
		os <<
			" street: " << ad.street <<
			" city:   " << ad.city <<
			" suite:  " << ad.suite <<
			endl;
		return os;
	}
};

struct Contact
{
	string  name;
	Address *work_address;

	friend ostream& operator<< (ostream& oss, const Contact& cont)
	{
		oss <<
			" name: " << cont.name <<
			"Address:" << *cont.work_address
			<< endl;
		return oss;
	}

	Contact(const string n, Address* addr)
	{
		name = n;
		work_address = new Address{};
		work_address->city  = addr->city;
		work_address->street= addr->street;
		work_address->suite = addr->suite;
	}
	//copy constructor
	Contact(const Contact& other)
	{
		name = other.name;
		work_address = new Address{};
		work_address->city  = other.work_address->city;
		work_address->street= other.work_address->street;
		work_address->suite = other.work_address->suite;
	}

	~Contact()
	{
//		delete work_address;
	}

	friend class EmployeeFactory;
};

class EmployeeFactory
{
	static Contact Main, Aux;
	static unique_ptr<Contact> NewMainOfficeEmployee(const string name, const int suite)
	{
		return newEmployee(name, suite, Main);
	}

	static unique_ptr<Contact> NewAuxOfficeEmployee(const string name, const int suite)
	{
		return newEmployee(name, suite, Aux);
	}

private:
	static unique_ptr<Contact> newEmployee(const string name, const int suite, Contact& proto)
	{
		auto result = make_unique<Contact>(proto);
		result->name = name;
		result->work_address->suite = suite;
		return result;
	}
	
};
Contact EmployeeFactory::Main{ "", new Address{ "123 Liberty Road", "New York", 0 }};
Contact EmployeeFactory::Aux{ "", new Address{ "1 evergreen ", "London", 0 }};

int Prototype_test()
{
#if 0 //ideally smart pointer are used
	Address* addr = new Address{ "23, liberty road", "New York", 123 }; //prototype
	Contact john( "John Doe	", addr);
	john.work_address->suite = 1;
	Contact jane{ "Jane Doe	", addr };
	jane.work_address->suite = 2;

	Contact Jill{ jane };
	Jill.name = "Jill cox";
	Jill.work_address->suite = 3;

	cout << john << endl;
	cout << jane << endl;
	cout << Jill << endl;
	delete addr;
#endif //other approach
#if 0 //with memory lead
	Contact employee = Contact("", new Address{"123 Liberty Road", "New York", 0});//prototype with memory leak=>need a factory
	
	Contact Jane{ employee };
	Jane.name = "Jane";
	Jane.work_address->suite = 3;
#endif
//	auto John = EmployeeFactory::NewMainOfficeEmployee("John", 1); //wont compile with my VS compiler (issue with friend class)
	//...

	return 0;
}