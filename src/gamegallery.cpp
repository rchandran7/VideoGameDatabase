#include "../header/gamegallery.hpp"
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"
using namespace std;

    GameGallery::~GameGallery() {
        delete gallery;
        delete file;
        delete how_search;
        delete how_sort;
    }

    void GameGallery::save(string save_file) {
	json j=file->newJSON();
        file->save(j);
        cout << "the Video Game data has been saved.\n\n ";
    }
    void GameGallery::newFile(string new_file){
	file->setFilename(new_file);
	file->setGallery(gallery);
	json j=file->newJSON();
	cout << "the new file has been created.\n\n ";	
	}

    void GameGallery::load(string load_file) {
        file->setFilename(load_file);
	file->setGallery(gallery);
        json j=file->load();
	Collection m=file->fileRead(j);
	vector<VideoGame*> t1;
	Collection* gal= new Collection(t1);
	for(int i=0;i<m.getCollection().size();++i){
	gal->add(new VideoGame(m.getCollection()[i]->getName(),m.getCollection()[i]->getYear(),m.getCollection()[i]->getPub(),m.getCollection()[i]->getSystem(),
	m.getCollection()[i]->getGenre(),m.getCollection()[i]->getRating(),m.getCollection()[i]->getSize(),
	m.getCollection()[i]->getCost(),m.getCollection()[i]->getPlayer()));
	}
	delete gallery;
	this->gallery=gal;
	file->setGallery(gallery);
	file->save(j);
	j=file->load();
        cout << "the Video Game data has been loaded.\n\n ";
    }

    void GameGallery::setSearch(Searcher* search) {
        delete how_search;
        how_search = search;
    }

    void GameGallery::setSort(Sorter* sort) {
        delete how_sort;
        how_sort = sort;
    }

    VideoGame* GameGallery::search(string key) const {
        return how_search->search(gallery, key);
    }

    void GameGallery::sort() {
        how_sort->sort(gallery);
    }

    void GameGallery::addGame(VideoGame* newGame) {
        gallery->add(newGame);
    }

    void GameGallery::delGame(VideoGame* badGame) {
        gallery->eliminate(badGame);
    }

    void GameGallery::print() const {
         gallery->print();
         cout << "file name:\n" << file->getFilename() << endl << endl;
    }
