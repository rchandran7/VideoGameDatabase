#ifndef _SORT_GENRE_
#define _SORT_GENRE_
#include "sorter.hpp"
#include "collection.hpp"

/**
 	* @brief: This class sorts the Collection by genre
 	*
 	*/
class Sort_Genre: public Sorter {
   public:
	/**
	 * @brief: basic constructor that initializes a Sort_Genre
	 *
	 * @param: None
	 * @return: Sort_Genre object
	 */
        Sort_Genre() {}
	/**
 	 * @brief: Sort_Genre destructor
 	 *
 	 * @param: None
 	 * @return: None
 	 */
	~Sort_Genre() {}
        /**
 	 * @brief: sorts passed in collection by genre
 	 * 
 	 * @param: pointer to Collection object to be sorted
 	 * @return: none
 	 */
        virtual void sort(Collection* gallery);
};

#endif
