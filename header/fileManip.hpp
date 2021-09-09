#ifndef FILEMANIP_HPP
#define FILEMANIP_HPP

#include <string>
#include "nlohmann/json.hpp"
#include <iostream>
#include "collection.hpp"
#include "videogame.hpp"

// for convenience
using json = nlohmann::json;

/**
 	* @brief: This class has all the main functionality for any desirable action on files
 	* 
	*/

class fileManip{
	private:
	std::string filename;
	Collection* gallery;

	public:
	int jsontrack;
	fileManip(){}
        fileManip(std::string name);
	/**
	 * @brief: constructor of the fileManip class that initializes with passed in objects
	 * 
	 * @param: string for file name to access and Collection* for the collection of video games to access
	 * @return: fileManip Object
	 */
	fileManip(std::string name, Collection* gal);
	/**
  	 * @brief: destructor of the fileManip class
  	 * 
  	 * @param: None
  	 * @return: fileManip Object
  	 */
	~fileManip(){}
	/**
 	 * @brief: saves the file to the database
  	 * 
  	 * @param: Json object to save to file 
  	 * @return: None
  	 */
	void save(json j);
        /**
         * @brief: load the file from the database
         *            
         * @param: None
         * @return: retunrs a JSON object
         */

	json load();
        /**           
  	 * @brief: creates a new JSON file into the database
  	 *
  	 * @param: None
  	 * @return: returns a JSON object
         */

	json newJSON();
	/**
 	 * @brief: creates a new JSON file into the database
 	 *
 	 * @param: Json object to access what is inside the file
	 * @return: returns a Collection object
	*/
	Collection fileRead(json j);

	 /**           
  	 * @brief: sets new file name
  	 *
  	 * @param: newName string for the file
  	 * @return: None
         */

	void setFilename(std::string newName);

	/**           
  	 * @brief: sets new gallery collection
  	 *
  	 * @param: Collection gall pointer
  	 * @return: None
         */

	void setGallery(Collection* gall);
	
	/**           
  	 * @brief: gets filename
  	 *
  	 * @param: None
  	 * @return: string filename
         */
	std::string getFilename() const;
	/**           
  	 * @brief: gets gallery collection
  	 *
  	 * @param: None
  	 * @return: Collection gallery
         */

	Collection* getGallery() const;
};


#endif
