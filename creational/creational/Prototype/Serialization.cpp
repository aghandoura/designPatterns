#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <sstream>

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "../Header.h"

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
private:
	friend class boost::serialization::access;
	template<class Ar> void serialize(Ar& ar, const unsigned int version)
	{
		ar & street;
		ar & city;
		ar & suite;

	}
};

struct Contact
{
	string  name;
	Address* work_address;

	friend ostream& operator<< (ostream& oss, const Contact& cont)
	{
		oss <<
			" name: " << cont.name <<
			"Address:" << *cont.work_address
			<< endl;
		return oss;
	}
private:
	friend class boost::serialization::access;
	template<class Ar> void serialize(Ar& ar, const unsigned int version)
	{
		ar & name;
		ar & work_address;
	}
};

int Serialization_test()
{
	Contact John;
	John.name = "John";
	John.work_address = new Address{ "134 Liberty street", "New York", 1 };
	auto clone = [](Contact c)
	{
		ostringstream oss;
		boost::archive::text_oarchive oa(oss);
		oa << c;
		string debug_string = oss.str();

		Contact result;
		istringstream iss(debug_string);
		boost::archive::text_iarchive ia(iss);
		ia >> result;
		return result;
	};

	Contact Jane = clone(John);
	Jane.name = "Jane";
	Jane.work_address = new Address{ "134 Liberty street", "New York", 2 };

	cout << Jane << John << endl;

	return 0;
}