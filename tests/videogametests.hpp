#include "../header/videogame.hpp"

TEST(basicConstructorTest, sameValues) {
	    VideoGame vid;
	    EXPECT_EQ("Galaga", vid.getName());
        EXPECT_EQ(1999, vid.getYear());
        EXPECT_EQ("ATARI", vid.getPub());
        EXPECT_EQ("Arcade Machine", vid.getSystem());
        EXPECT_EQ("shooter", vid.getGenre());
        EXPECT_EQ("E", vid.getRating());
        EXPECT_EQ("2.5 GB", vid.getSize());
        EXPECT_EQ(35, vid.getCost());
        EXPECT_EQ(1, vid.getPlayer());
        EXPECT_EQ(1, vid.getId());
        
	}

TEST(actualConstructorTest, samePassedInValues) {
	    VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", 
        "T", "2 GB", 40, 2);
	    EXPECT_EQ("Pac-Man", vid->getName());
        EXPECT_EQ(2000, vid->getYear());
        EXPECT_EQ("NAMACO", vid->getPub());
        EXPECT_EQ("Genesis", vid->getSystem());
        EXPECT_EQ("puzzle", vid->getGenre());
        EXPECT_EQ("T", vid->getRating());
        EXPECT_EQ("2 GB", vid->getSize());
        EXPECT_EQ(40, vid->getCost());
        EXPECT_EQ(2, vid->getPlayer());
        EXPECT_EQ(1, vid->getId());
        
        delete vid;
	}
