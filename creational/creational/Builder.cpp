#include "Header.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

struct HtmlBuilder;

struct HtmlElement
{
	string name;
	string text;
	vector<HtmlElement> elements;
	const size_t indent_size = 2;

	HtmlElement(){}
	HtmlElement(const string& n, const string& t)
		: name( n ),
		text( t )
	{
	}
	string str(int indent = 0) const
	{
		ostringstream oss;
		string i(indent_size * indent, ' ');
		oss << i << "<" << name << ">" << endl;

		if (text.size() >0)
		{
			oss << string(indent_size * (indent + 1), ' ') << text << endl;
		}

		for (auto& e:elements)
		{
			oss << e.str(indent + 1);
		}

		oss << i << "</" << name << ">" << endl;

		return oss.str();
	}
	static HtmlBuilder build(string root_name);
};


struct HtmlBuilder
{
	HtmlElement root;

	HtmlBuilder(string name)
	{
		root.name = name;
	}

	// string add_child(string name, string text)
	// fluent builder: return a reference to elem 
	// instread of string to be able to chain 
	// calls see add_child usage
	HtmlBuilder& add_child(string name, string text)
	{
		//Html_Element e{ name , text }
		root.elements.emplace_back( name, text );
		return *this;
	}

	string str() const
	{
		return root.str();
	}


	// this will allow something like HtmlElement e =  Builder
	// but what is better is that it allow the implementation\
	// build method in HtmlElement
	operator HtmlElement() { return root; }

};

HtmlBuilder
HtmlElement::build(string root_name)
{
	return HtmlBuilder{ root_name };
}

int Builder_test()
{
	HtmlBuilder builder("ul");
	builder.add_child("li", "Hello")
	.add_child("li", "World");

	cout << builder.str() << endl;

	HtmlElement e = HtmlElement::build("ul").add_child("li", "Hello")
		.add_child("li", "World");

	cout << e.str() << endl;

	return 0;
}