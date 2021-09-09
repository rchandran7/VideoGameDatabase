#include "../header/fileManip.hpp"

TEST(filemanipTest, newJSON){
	fileManip* file=new fileManip("n1");
	json j=file->newJSON();
	j["test"]= "hello world";
	file->save(j);
	EXPECT_EQ("{\"test\":\"hello world\"}",j.dump());
	delete file;
	remove("n1");
}

TEST(filemanipTest, loadtest){
	fileManip* file=new fileManip("n1");
	json j=file->newJSON();
	j["test"]= "hello world";
        file->save(j);
	json y=file->load();
	EXPECT_EQ("{\"test\":\"hello world\"}",j.dump());
        delete file;
	remove("n1");
}

TEST(filemanipTest, savetest){
	fileManip* file=new fileManip("n1");
	json j=file->newJSON();	
	j["test"]= "hello";
	file->save(j);
	EXPECT_EQ("{\"test\":\"hello\"}",j.dump());
        delete file;
	remove("n1");
}

TEST(filemanipTest, emptyGalleryTest){
	Collection* gal=new Collection();
	fileManip* file=new fileManip("n2",gal);
        json j=file->newJSON();
        file->save(j);
	EXPECT_EQ("null",j.dump());
	delete file;
	delete gal;
	remove("n2");
}

TEST(filemanipTest, GalleryTest){
        vector<VideoGame*> vidGames;
	VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
	Collection* gallery = new Collection(vidGames);
	gallery->add(vid);
        fileManip* file=new fileManip("n2",gallery);
        json j=file->newJSON();
        file->save(j);
	json t=file->load();
        EXPECT_EQ(t[0]["Name"],vid->getName());
	//EXPECT_EQ("[{\"Cost\":40,\"Genre\":\"puzzle\",\"Id\":3,\"Name\":\"Pac-Man\",\"Player\":2,\"Publisher\":\"NAMACO\",\"Rating\":84,\"Size\":\"2 GB\",\"System\":\"Genesis\",\"Year\":2000}]",t.dump());
        delete file;
        delete gallery;
        remove("n2");
           }
TEST(filemanipTest, readFileTest){
        vector<VideoGame*> vidGames;
        VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
	//VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
        Collection* gallery = new Collection(vidGames);
        gallery->add(vid);
	//gallery->add(vidTwo);
        fileManip* file=new fileManip("n3",gallery);
	json j=file->newJSON();
	file->save(j);
	json k=file->load();
	Collection test=file->fileRead(k);
	EXPECT_EQ(test.getCollection()[0]->getName(),gallery->getCollection()[0]->getName());
	//remove("n3");
	delete gallery;
	delete file;
	}
TEST(filemanipTest, addingAfterfileRead){
        vector<VideoGame*> vidGames;
        VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
        Collection* gallery = new Collection(vidGames);
        gallery->add(vid);
        fileManip* file=new fileManip("n2",gallery);
        json j=file->newJSON();
        file->save(j);
        json k=file->load();
        Collection test=file->fileRead(k);
	vector<VideoGame*> testgames;
	vector<VideoGame*> file1=test.getCollection();
	VideoGame* vidnew = new VideoGame(file1[0]->getName(),file1[0]->getYear(),file1[0]->getPub(),file1[0]->getSystem(),file1[0]->getGenre(),file1[0]->getRating(),file1[0]->getSize(),file1[0]->getCost(),file1[0]->getPlayer());
	VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
	
	Collection* gal = new Collection(testgames);
	gal->add(vidnew);
	gal->add(vidTwo);

        EXPECT_EQ(gal->getCollection()[1]->getName(),vidTwo->getName());
        remove("n2");
	delete gal;
      	delete gallery;
        delete file;
        }
	
TEST(filemanipTest, readFileMultiVideoGameTest){
        vector<VideoGame*> vidGames;
        VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", "T", "2 GB", 40, 2);
        VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", "E", "1 GB", 27, 1);
	Collection* gallery = new Collection(vidGames);
        gallery->add(vid);
	gallery->add(vidTwo);
        fileManip* file=new fileManip("n2",gallery);
        json j=file->newJSON();
        file->save(j);
        json k=file->load();
	Collection test=file->fileRead(k);
        EXPECT_EQ(test.getCollection()[1]->getName(),gallery->getCollection()[1]->getName());
        remove("n2");
        delete gallery;
        delete file;
	
}

