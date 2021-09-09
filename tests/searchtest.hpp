#ifndef SEARCH_TEST_HPP
#define SEARCH_TEST_HPP

#include "../header/search.hpp"
#include "../header/search_name.hpp"
#include "../header/search_genre.hpp"
#include "../header/search_pub.hpp"
#include "../header/search_year.hpp"
#include "../header/collection.hpp"
#include "../header/videogame.hpp"

TEST(SearcherTest, SearchName) {
   	vector<VideoGame*> vidGames;
   	VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
	VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
	Collection* gallery = new Collection(vidGames);
	gallery->add(vid);
 	gallery->add(vidTwo);
	SearchName* test=new SearchName();
	string s="Pac-Man";
	VideoGame* t1=test->search(gallery,s);
	EXPECT_EQ(t1,vid);
	delete test;
	delete gallery;
}	

TEST(SearcherTest, SearchPub) {
        vector<VideoGame*> vidGames;
        VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
        VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
        Collection* gallery = new Collection(vidGames);
        gallery->add(vid);
        gallery->add(vidTwo);
        SearchPub* test=new SearchPub();
        string s="Mojang";
        VideoGame* t1=test->search(gallery,s);
        EXPECT_EQ(t1,vidTwo);
        delete test;
        delete gallery;
}
TEST(SearcherTest, SearchYear) {
        vector<VideoGame*> vidGames;
        VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
        VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
        Collection* gallery = new Collection(vidGames);
        gallery->add(vid);
        gallery->add(vidTwo);
        SearchYear* test=new SearchYear();
        string s="2000";
        VideoGame* t1=test->search(gallery,s);
        EXPECT_EQ(t1,vid);
        delete test;
        delete gallery;
}
TEST(SearcherTest, SearchGenre) {
        vector<VideoGame*> vidGames;
        VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
        VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
        Collection* gallery = new Collection(vidGames);
        gallery->add(vid);
        gallery->add(vidTwo);
        SearchGenre* test=new SearchGenre();
        string s="adventure";
        VideoGame* t1=test->search(gallery,s);
        EXPECT_EQ(t1,vidTwo);
        delete test;
        delete gallery;
}




#endif
