//An example not using Builder pattern
//generate a tag from text

#include "Header.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>


using namespace std;
int noBuilder_test()
{
	//<p>hello</p>
	auto text = "hello";
	string output;
	output +="<p>";
	output += text;
	output +="</p>";

	cout << output << endl;
	//using printf
	printf("<p>%s</p\n", text);
	//<ul><li>Hello</li><li>World</li></ul>

	string words[] = { "Hello", "World" };
	ostringstream oss;

	oss << "<ul>";
	for (auto w : words)
	{
		oss << "<li>" << w << "</li>";
	}
	oss << "</ul>";

	printf(oss.str().c_str());

	return 0;
}

