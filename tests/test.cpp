#include "gtest/gtest.h"
//#include "../header/videogame.hpp"
#include "videogametests.hpp"
#include "fileManipTests.hpp"
#include "nlohmann/json.hpp"
#include "searchtest.hpp"
#include "collectiontests.hpp"
#include "sortertests.hpp"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
