#ifndef COLLECTIONTESTS_HPP
#define COLLECTIONTESTS_HPP
#include "../header/collection.hpp"
#include "../header/videogame.hpp"

TEST(CollectionTest, AddConstructorTest) {
   vector<VideoGame*> vidGames;
   VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
   Collection* gallery = new Collection(vidGames);
   gallery->add(vid);
   EXPECT_EQ(gallery->getVideoGame(0)->getName(), "Pac-Man");
   delete gallery;
}

TEST(CollectionTest, RemoveTest) {
   vector<VideoGame*> vidGames;
   VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
   VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
   Collection* gallery = new Collection(vidGames);
   gallery->add(vid);
   gallery->add(vidTwo);
   gallery->eliminate(vid);
   EXPECT_EQ(gallery->getVideoGame(0)->getName(), "Minecraft");
   delete gallery;
}

TEST(CollectionTest, EmptyConstructorTest) {
   Collection gallery;
   EXPECT_EQ(gallery.getCollectionSize(), 0);
}

//Test for print function using ostream
//TEST(CollectionTest, PrintTest) {
//   vector<VideoGame*> vidGames;
//   VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", 'T', "2 GB", 40, 2);
//   VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", 'E', "1 GB", 27, 1);
//   Collection* gallery = new Collection(vidGames);
//   gallery->add(vid);
//   gallery->add(vidTwo);
//   ostringstream output;
//   gallery->print(output);
//   EXPECT_EQ(output.str(), "Collection: \nID: 6 Name: Pac-Man Year: 2000 Publisher: NAMACO System: Genesis Genre: puzzle Rating: T Size: 2 GB Cost: 40 Player: 2\n\nID: 7 Name: Minecraft Year: 2011 Publisher: Mojang System: PC, PS, Xbox Genre: adventure Rating: E Size: 1 GB Cost: 27 Player: 1\n\n");   
//   delete gallery;
//}

#endif  
