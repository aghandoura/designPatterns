//This examples shows how Builder facets are used to incrementally build
// an object
//Note: there is a bug in VS 2013 compiler with friend class access
#include <iostream>

#include "person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

#include "../Header.h"


int Facets_test()
{
    Person p =Person::create()
		.lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
		.works().at("PragmaSoft").as_a("Consultant").earning(60000);

	std::cout << p
		<< std::endl;

	return 0;
}