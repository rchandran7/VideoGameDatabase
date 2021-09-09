#ifndef SORTERTESTS_HPP
#define SORTERTESTS_HPP

#include "../header/sort_year.hpp"
#include "../header/sort_name.hpp"
#include "../header/sort_genre.hpp"
#include "../header/sort_pub.hpp"

TEST(SorterTest, SortName) {
   vector<VideoGame*> vidGames;
   VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
   VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
   VideoGame* vidThree = new VideoGame("Tetris", 1989, "Nintendo", "NES", "puzzle", "E", "22 MB", 20, 1);
   Collection* gallery = new Collection(vidGames);
   gallery->add(vid);
   gallery->add(vidTwo);
   gallery->add(vidThree);
   Sort_Name* testSort = new Sort_Name();
   testSort->sort(gallery);
   EXPECT_EQ(gallery->getVideoGame(0)->getName(), "Minecraft");
   delete gallery;
   delete testSort;
}

TEST(SorterTest, SortYear) {
   vector<VideoGame*> vidGames;
   VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
   VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
   VideoGame* vidThree = new VideoGame("Tetris", 1989, "Nintendo", "NES", "puzzle", "E", "22 MB", 20, 1);
   Collection* gallery = new Collection(vidGames);
   gallery->add(vid);
   gallery->add(vidTwo);
   gallery->add(vidThree);
   Sort_Year* testSort = new Sort_Year();
   testSort->sort(gallery);
   EXPECT_EQ(gallery->getVideoGame(1)->getYear(), 2000);
   delete gallery;
   delete testSort;
}

TEST(SorterTest, SortGenre) {
   vector<VideoGame*> vidGames;
   VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
   VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
   VideoGame* vidThree = new VideoGame("Tetris", 1989, "Nintendo", "NES", "puzzle", "E", "22 MB", 20, 1);
   Collection* gallery = new Collection(vidGames);
   gallery->add(vid);
   gallery->add(vidTwo);
   gallery->add(vidThree);
   Sort_Genre* testSort = new Sort_Genre();
   testSort->sort(gallery);
   EXPECT_EQ(gallery->getVideoGame(0)->getGenre(), "adventure");
   delete gallery;
   delete testSort;
}

TEST(SorterTest, SortPub) {
   vector<VideoGame*> vidGames;
   VideoGame* vid = new VideoGame("Pac-Man", 2000, "Namaco", "Genesis", "puzzle", "T", "2 GB", 40, 2);
   VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
   VideoGame* vidThree = new VideoGame("Tetris", 1989, "Nintendo", "NES", "puzzle", "E", "22 MB", 20, 1);
   Collection* gallery = new Collection(vidGames);
   gallery->add(vid);
   gallery->add(vidTwo);
   gallery->add(vidThree);
   Sort_Pub* testSort = new Sort_Pub();
   testSort->sort(gallery);
   EXPECT_EQ(gallery->getVideoGame(2)->getPub(), "Nintendo");
   delete gallery;
   delete testSort;
}

#endif
