#ifndef __SEARCH_NAME_HPP__
#define __SEARCH_NAME_HPP__

#include "collection.hpp"
#include "search.hpp"
#include <iostream>
/**
 	* @brief: This class is one of the concrete strategies for searching
 	* 
	*/
class SearchName: public Searcher{
        public:
	/**
  	 * @brief: constructor of the SearchName class
  	 * 
  	 * @param: None
  	 * @return: SearchName object
  	 */
	SearchName(){}
	/**
  	 * @brief: destructor of the SearchName class
  	 * 
  	 * @param: None
  	 * @return: SearchName object
  	 */
	~SearchName(){}
	/**
  	 * @brief: virtual searcher function
  	 * 
  	 * @param: gal: pointer to Collection object, s: string object
  	 * @return: pointer to a VideoGame object
  	 */
        VideoGame* search(Collection* gal, std::string searchTerm){
		
		for(int i=0;i<gal->getCollection().size();++i){
			if(gal->getCollection()[i]->getName()==searchTerm){
			return gal->getCollection()[i];
			}
		}
		return nullptr;
	}

};

#endif // __SEARCH_NAME_HPP__

