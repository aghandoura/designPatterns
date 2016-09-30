#include "test.h"

TEST(adapter_test, to_lower_test)
{
	String s{ "HelLo World" };

	auto lower = s.to_lower().str();

	//ASSERT_STREQ("hello world", lower.c_str());
	EXPECT_EQ("hello world", lower);

}

TEST(adapter_test, split_test)
{
	String s{ "Hello world" };

	auto splitted = s.split();

	EXPECT_EQ("Hello", splitted[0]);
	EXPECT_EQ("world", splitted[1]);
}

TEST(adapter_test, split_test_delim)
{
	String s{ "Hello,world" };

	auto splitted = s.split(",");

	EXPECT_EQ("Hello", splitted[0]);
	EXPECT_EQ("world", splitted[1]);
}

int main(int argc, char **argv)
{

	testing::InitGoogleTest(&argc, argv);
	auto status = RUN_ALL_TESTS();

	//getchar(); //commented to be able to run unit tests individually
	return status;
}
