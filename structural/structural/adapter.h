// structural.h : Defines the entry point for the console application.
//

#pragma once

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<boost/algorithm/string.hpp>

using namespace std;
//string adaptor
class String
{
	
	string s;
public:
	String(string s) : s{ s }
	{
	}

	String to_lower() const
	{
		string ss{ s };
		boost::to_lower(ss);
		return{ ss };
	}

	vector<string> split(const string& delim = " ") const
	{
		vector<string> parts;
	    boost::split(parts, s , boost::is_any_of(delim), boost::token_compress_on);
		return parts;
	}

	const char* c_str()
	{
		return s.c_str();
	}
};
