#ifndef _SORT_PUB_
#define _SORT_PUB_
#include "sorter.hpp"
#include "collection.hpp"

/**
 	* @brief: This class sorts the Collection by publisher
 	*
 	*/
class Sort_Pub: public Sorter {
   public:
	/**
	 * @brief: basic constructor that initializes a Sort_Pub
	 *
	 * @param: None
	 * @return: Sort_Pub object
	 */
        Sort_Pub() {}
	/**
	 * @brief: Sort_Pub destructor
	 *
	 * @param: None
	 * @return: None
	 */
	~Sort_Pub() {}
	/**
	 * @brief: sorts passed in collection by publisher
	 *
	 * @param: pointer to Collection object to be sorted
	 * @return: none
	 */
        virtual void sort(Collection* gallery);
};

#endif
