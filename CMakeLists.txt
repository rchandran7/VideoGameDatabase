CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

SET(JSON_BuildTests OFF CACHE INTERNAL "")

ADD_SUBDIRECTORY(googletest)

ADD_SUBDIRECTORY(json)

ADD_LIBRARY(header
			header/fileManip.hpp
			src/filemanip.cpp
			tests/fileManipTests.hpp
			)

ADD_EXECUTABLE(test
			tests/test.cpp
			src/videogame.cpp
			src/filemanip.cpp
      src/collection.cpp
			src/sort_name.cpp
			src/sort_year.cpp
			src/sort_genre.cpp
			src/sort_pub.cpp
			)

ADD_EXECUTABLE(game
			src/main.cpp
			src/sort_name.cpp
			src/sort_year.cpp
			src/sort_genre.cpp
			src/sort_pub.cpp
			src/videogame.cpp
			src/filemanip.cpp
			src/collection.cpp
			header/search_name.hpp
			header/search_year.hpp
			header/search_genre.hpp
			header/search_pub.hpp
			src/gamegallery.cpp
			)

TARGET_LINK_LIBRARIES(game PRIVATE nlohmann_json::nlohmann_json)

TARGET_LINK_LIBRARIES(header PRIVATE nlohmann_json::nlohmann_json)

TARGET_LINK_LIBRARIES(test PRIVATE nlohmann_json::nlohmann_json)

TARGET_LINK_LIBRARIES(test gtest)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
