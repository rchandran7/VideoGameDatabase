#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__

#include "collection.hpp"
#include <iostream>
#include <sstream>

/**
 	* @brief: This class is the strategy for searching
 	* 
	*/

class Searcher{
        public:
        /**
  	 * @brief: destructor of the Searcher class
  	 * 
  	 * @param: None
  	 * @return: Searcher object
  	 */
        ~Searcher(){}
        /**
  	 * @brief: virtual searcher function
  	 * 
  	 * @param: gal: pointer to Collection object, s: string object
  	 * @return: pointer to a VideoGame object
  	 */
        virtual VideoGame* search(Collection* gal,string s)=0;
};

#endif // __SEARCH_HPP__

