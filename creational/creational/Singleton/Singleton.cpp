#include "../Header.h"
#include "Singleton.h"
#include <gtest/gtest.h>


int SingletonDatabase::instance_count = 0;

TEST(DatabaseTest, isSingletonTest)
{
	auto& db = SingletonDatabase::get();
	auto& db2 = SingletonDatabase::get();

	ASSERT_EQ(1, db.instance_count);
	ASSERT_EQ(1, db.instance_count);

}

TEST(RecordFinderTest, SingletonTotalPopulationTest)
{
	SingletonRecordFinder rf;
	std::vector<std::string> names{"Seoul", "Tokyo"};
	auto tp = rf.total_population(names);
	EXPECT_EQ(17500000 + 33200000, tp);
}

int Singleton_test(int argc, char* av[])
{
	//we need to disallow those:
	//SingletonDatabase db;
	//auto df(...);
	//auto db = ...;

	testing::InitGoogleTest(&argc, av);
	return RUN_ALL_TESTS();
}


