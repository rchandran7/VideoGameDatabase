#ifndef _SORT_NAME_
#define _SORT_NAME_
#include "sorter.hpp"
#include "collection.hpp"

/**
 	* @brief: This class sorts the Collection by name
 	*
 	*/
class Sort_Name: public Sorter {
   public:
	/**
	 * @brief: basic constructor that initializes a Sort_Name
	 *
	 * @param: None
	 * @return: Sort_Name object
	 */
	Sort_Name() {}
	/**
	 * @brief: Sort_Name destructor
	 *
	 * @param: None
	 * @return: None
	 */
	~Sort_Name() {}
	/**
 	* @brief: sorts passed in collection by name
 	*
 	* @param: pointer to collection object to be sorted
 	* @return: None
 	*/
	virtual void sort(Collection* gallery);
};

#endif
