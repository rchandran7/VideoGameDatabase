#ifndef _SORT_YEAR_
#define _SORT_YEAR_
#include "sorter.hpp"
#include "collection.hpp"

/**
 	* @brief: This class sorts the Collection by year
 	*
 	*/
class Sort_Year: public Sorter {
   public:
	/**
 	 * @brief: basic constructor that initializes a Sort_Year
 	 *
 	 * @param: None
 	 * @return: Sort_Year object
 	 */
        Sort_Year() {}
	/**
 	 * @brief: Sort_Year destructor
 	 *
 	 * @param: None
 	 * @return: None
 	 */
	~Sort_Year() {}
	/**
	 * @brief: sorts passed in collection by year
	 *
	 * @param: pointer to Collection object to be sorted
	 * @return: none
	 */
        virtual void sort(Collection* gallery);
};

#endif
