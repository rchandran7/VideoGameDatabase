#include "../header/collection.hpp"

Collection::Collection(vector<VideoGame*> game) {
   games = game;
}

Collection::~Collection() {
   for (int i = 0; i < games.size(); i++) {
	delete games[i];
   }
}

void Collection::add(VideoGame* game) {
   games.push_back(game);
}

void Collection::eliminate(VideoGame* game) {
   games.erase(remove(games.begin(), games.end(), game), games.end());
   delete game;
}

void Collection::print() const {
   cout << "Collection: " << endl;
   for (int i = 0; i < games.size(); i++) {
	games.at(i)->print();
   }
}

VideoGame* Collection::getVideoGame(int index) {
   return games.at(index);
}

int Collection::getCollectionSize() {
   return games.size();
}

void Collection::swapGames(int i, int j) {
   VideoGame* temp = games.at(i);
   games.at(i) = games.at(j);
   games.at(j) = temp;
}
