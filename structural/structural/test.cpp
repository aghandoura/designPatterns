#include "test.h"

int main(int argc, char **argv)
{

	testing::InitGoogleTest(&argc, argv);
	auto status = RUN_ALL_TESTS();

//	getchar();
	return status;
}
