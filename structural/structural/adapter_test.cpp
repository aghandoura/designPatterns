#include "adapter.h"
#include "test.h"

TEST(adapter_test, to_lower_test)
{
	String s{ "HelLo World" };

	auto lower = s.to_lower();

	ASSERT_STREQ("hello world", lower.c_str());

}

TEST(adapter_test, split_test)
{
	String s{ "Hello world" };

	auto splitted = s.split();

	ASSERT_STREQ("Hello", splitted[0].c_str());
	ASSERT_STREQ("world", splitted[1].c_str());
}
