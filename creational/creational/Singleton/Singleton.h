#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <boost/lexical_cast.hpp>
#include <vector>

class Database
{
public:
	virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase : public Database
{
private:
	SingletonDatabase()
	{
		std::cout << "initialising Database" << std::endl;
		std::ifstream ifs("capitals.txt");

		if (!ifs.is_open())
		{
			std::cout << "error opening file" << std::endl;
			return;
			
		}

		std::string s, s2;
		while (std::getline(ifs, s))
		{
     		getline(ifs, s2);
			auto pop = boost::lexical_cast<int>(s2);
			capitals[s] = pop;
			std::cout << "filling: " << s << " : " << pop << std::endl;
		}
		instance_count++;

	}
	std::map<std::string, int> capitals;
	//static SingletonDatabase* instance;
public:
	static int instance_count;
	SingletonDatabase(SingletonDatabase const&) = delete;
	SingletonDatabase& operator=(SingletonDatabase const&) = delete;

	static SingletonDatabase& get()
	{
		static SingletonDatabase db;
		return db;
	}

	int get_population(const std::string& name) override
	{
		std::cout << "getting population of " << name << " : " << capitals.at(name)<<std::endl;

//		return capitals[name]; //no errors handling
		return capitals.at(name);
	}

	/*
	static SingletonDatabase* get_instance()
	{
		if (!instance)
			instance = new SingletonDatabase; //free atexit
		return instance;
	}
	*/

};
class DummyDatabase : public Database
{
	std::map<std::string, int> capitals;
	
public:
	DummyDatabase()
	{
		capitals["alpha"] = 1;
		capitals["beta"]  = 2;
		capitals["gamma"] = 3;
	}

	int get_population(const std::string& name) override
	{
		return capitals[name];
	}

	
};
struct SingletonRecordFinder
{
	int total_population(std::vector<std::string> names)
	{
		auto result = 0;

		for (auto& name : names)
			result += SingletonDatabase::get().get_population(name);
		
		return result;
	}
};

struct ConfigurableRecordFinder
{
	explicit ConfigurableRecordFinder(Database& db)
		:db{db}
	{
		
	}

	int total_population(std::vector<std::string> names)
	{
		auto result = 0;

		for (auto& name : names)
			result += db.get_population(name);
		
		return result;
	}

	Database& db;
};

