#include "../header/fileManip.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;
using json = nlohmann::json;

int main(){

        vector<VideoGame*> vidGames;
        Collection* gal = new Collection(vidGames);
	VideoGame* vid = new VideoGame("Pac-Man", 2000, "NAMACO", "Genesis", "puzzle", 'T', "2 GB", 40, 2);
	VideoGame* vidTwo = new VideoGame("Minecraft", 2011, "Mojang", "PC, PS, Xbox", "adventure", 'E', "1 GB", 27, 1);
	string s=vid->getjsonstring();
	gal->add(vid);
	gal->add(vidTwo);
        fileManip* file=new fileManip("n2",gal);
        json j=file->newJSON();
        file->save(j);
	json l=file->load();
	cout << l.dump()<<endl;
	//remove ("n2");
	delete gal;
	delete file;

return 0;
}
