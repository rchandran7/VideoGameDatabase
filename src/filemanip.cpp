#include "../header/fileManip.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
	
using namespace std;
using json = nlohmann::json;
	
	fileManip::fileManip(string name){
	filename=name;
	gallery=nullptr;
	jsontrack=0;
	}
	
	fileManip::fileManip(string name,Collection* gal){
	filename=name;
	gallery=gal;
	jsontrack=0;
	}

	void fileManip::save(json j){
		ofstream o;
		o.open(filename);
		string s;
		json sj;

		if(gallery!=nullptr&&gallery->getCollection().size()!=0){
			for(int i=0;i<gallery->getCollection().size();++i){
		sj[i+jsontrack]={ {"Id",gallery->getCollection()[i]->getId()}, {"Name",gallery->getCollection()[i]->getName()},
		 {"Year",gallery->getCollection()[i]->getYear()}, {"Publisher",gallery->getCollection()[i]->getPub()}, 
		 {"System",gallery->getCollection()[i]->getSystem()}, {"Genre",gallery->getCollection()[i]->getGenre()},
		 {"Rating",gallery->getCollection()[i]->getRating()}, {"Size",gallery->getCollection()[i]->getSize()},
		 {"Cost",gallery->getCollection()[i]->getCost()}, {"Player",gallery->getCollection()[i]->getPlayer()}};
			
			//made a json initializer instead of string to json initializer but format did not look goo but kept it incase client wants it in that format	
			//sj[i]=games[i]->getjsonstring();
			}
		}
		else{
		sj=s;
		}
	
		o << sj;
		o.close();

	}

	json fileManip::load(){
		ifstream f(filename);
		json j;
		f >> j;
		jsontrack=0;
		int i=0;
		if(gallery!=nullptr){
			while(j[i].dump()!="null"){
			++jsontrack;
			++i;
			}
		}
		return j;
	}
	
	json fileManip::newJSON(){
		ofstream nj(filename);
		json j;
		nj.close();
		return j;
	}
	
	Collection fileManip::fileRead(json j){
		string name;
		unsigned int year;
		string pub;
		string system;
		string genre;
		string rating;
		string size;
		unsigned int cost;
		unsigned int player;

		Collection gallery;
		for(int i=0;i<jsontrack;++i){
		//while(j[i].dump()!="null"){
		//	++i;
			if(j[i].dump()!="null"){
			name=j[i]["Name"];
			year=j[i]["Year"];
			pub=j[i]["Publisher"];
			system=j[i]["System"];
			genre=j[i]["Genre"];
			rating=j[i]["Rating"];
			size=j[i]["Size"];
			cost=j[i]["Cost"];
			player=j[i]["Player"];
			gallery.add(new VideoGame(name,year,pub,system,genre,rating,size,cost,player));
		//VideoGame* vid = new VideoGame(j[0]["Name"],j[0]["Year"],j[0]["Publisher"],j[0]["System"],j[0]["Genre"],j[0]["Size"],j[0]["Cost"],j[0]["Player"]); 
			}
		}	
		return gallery;
	}

void fileManip::setFilename(std::string newName) {
		filename = newName;
	}

void fileManip::setGallery(Collection* gall) {
	gallery = gall;
	}

std::string fileManip::getFilename() const {
	return filename;
	}

Collection* fileManip::getGallery() const {
	return gallery;
	}
