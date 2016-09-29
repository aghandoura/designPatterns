#include "test.h"

int main(int argc, char **argv)
{

	testing::InitGoogleTest(&argc, argv);
	auto status = RUN_ALL_TESTS();

	//getchar(); //commented to be able to run unit tests individually
	return status;
}
