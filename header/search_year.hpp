#ifndef __SEARCH_YEAR_HPP__
#define __SEARCH_YEAR_HPP__

#include "collection.hpp"
#include "search.hpp"
#include <iostream>
/**
 	* @brief: This class is one of the concrete strategies for searching
 	* 
	*/
class SearchYear: public Searcher{
        public:
	/**
  	 * @brief: constructor of the SearchYear class
  	 * 
  	 * @param: None
  	 * @return: SearchYear object
  	 */
	SearchYear(){}
	/**
  	 * @brief: destructor of the SearchYear class
  	 * 
  	 * @param: None
  	 * @return: SearchYear object
  	 */
	~SearchYear(){}
	/**
  	 * @brief: virtual searcher function
  	 * 
  	 * @param: gal: pointer to Collection object, s: string object
  	 * @return: pointer to a VideoGame object
  	 */
        VideoGame* search(Collection* gal, std::string searchTerm){
                for(int i=0;i<gal->getCollection().size();++i){
                        if(to_string(gal->getCollection()[i]->getYear())==searchTerm){
                        return gal->getCollection()[i];
                        }
                }
                return nullptr;
        }

};

#endif // __SEARCH_YEAR_HPP__


