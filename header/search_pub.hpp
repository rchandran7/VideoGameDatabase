#ifndef __SEARCH_PUB_HPP__
#define __SEARCH_PUB_HPP__

#include "collection.hpp"
#include "search.hpp"
#include <iostream>
/**
 	* @brief: This class is one of the concrete strategies for searching
 	* 
	*/
class SearchPub: public Searcher{
        public:
	/**
  	 * @brief: constructor of the SearchPub class
  	 * 
  	 * @param: None
  	 * @return: SearchPub object
  	 */
	SearchPub(){}
	/**
  	 * @brief: destructor of the SearchGenre class
  	 * 
  	 * @param: None
  	 * @return: SearchGenre object
  	 */
	~SearchPub(){}
	/**
  	 * @brief: virtual searcher function
  	 * 
  	 * @param: gal: pointer to Collection object, s: string object
  	 * @return: pointer to a VideoGame object
  	 */
        VideoGame* search(Collection* gal, std::string searchTerm){

                for(int i=0;i<gal->getCollection().size();++i){
                        if(gal->getCollection()[i]->getPub()==searchTerm){
                        return gal->getCollection()[i];
                        }
                }
                return nullptr;
        }

};

#endif // __SEARCH_PUB_HPP__


