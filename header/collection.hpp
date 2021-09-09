#ifndef COLLECTION_HPP
#define COLLECTION_HPP
#include "videogame.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
	* @brief: This class has all the data related to Collection in the database.
	* 
	*/
class Collection {
   private:
	vector<VideoGame*> games;
   public:
	/**
	 * @brief: basic constructor that initializes an empty collection
	 *
	 * @param: None
	 * @return: Collection Object
	 */
	Collection() {}
	/**
	 * @brief: constructor that initializes a collection with passed in arguments
	 *
	 * @param: game: vector<VideoGame*>
	 * @return: Collection Object
	 */
	Collection(vector<VideoGame*> game);
	/**
	 * @brief: Collection destructor
	 *
	 * @param: None
	 * @return: None
	 */
	~Collection();
	/**
 	 * @brief: returns the vector of VideoGame pointers in the Collection
 	 *
 	 * @param: none
 	 * @return: vector of VideoGame object pointers
 	 */
	vector<VideoGame*> getCollection(){return games;};
  
	/**
	 * @brief: adds passed in VideoGame object to the collection
	 *
	 * @param: VideoGame object pointer to  be added
	 * @return: None
   */
	void add(VideoGame*);
	/**
	 * @brief: removes passed in VideoGame object from the collection
	 *
	 * @param: VideoGame object pointer to be removed
	 * @return: None
	 */
	void eliminate(VideoGame*);
	/**
	 * @brief: print function that prints out the entire collection and each video game's data
	 *
	 * @param: None
	 * @return: None
	 */
	void print() const;
	/**
	 * @brief: returns VideoGame at a certain index
	 *
	 * @param: index of VideoGame to be returned
	 * @return: VideoGame object pointer
	 */
	VideoGame* getVideoGame(int index);
	/**
	 * @brief: returns the size of the collection
	 *
	 * @param: None
	 * @return: Number of video games in the collection
	 */
	int getCollectionSize();
	/**
	 * @brief: swaps VideoGames in the games vector at the given indexes
	 *
	 * @param: indexes of VideoGames to be swapped
	 * @return: None
	 */
	void swapGames(int i, int j);
};

#endif
