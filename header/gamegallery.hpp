#ifndef GAMEGALLERY_HPP
#define GAMEGALLERY_HPP
#include "collection.hpp"
#include "fileManip.hpp"
#include "search_name.hpp"
#include "sort_name.hpp"

/**
	 * @brief: This class has all the main functionality for any desirable action to be ran on the videoGame database
	 * 
	 */
class GameGallery {
    private:
    Collection* gallery;
    fileManip* file;
    Searcher* how_search;
    Sorter* how_sort;

    public:
    /**
	 * @brief: basic constructor of the GameGallery class
	 * 
	 * @param: None
	 * @return: GameGallery Object
	 */
    GameGallery() : gallery(new Collection()), file(new fileManip()), how_search(new SearchName()), how_sort(new Sort_Name()) {}
    /**
	 * @brief: constructor of the GameGallery class that initializes with passed in objects
	 * 
	 * @param: gal : Collection object, file_in: string, search: Searcher object, sort: Sorter object
	 * @return: GameGallery Object
	 */
    //might change filemanip based on how its done later
    GameGallery(Collection* gal, string file_in, Searcher* search, Sorter* sort) : gallery(gal), file(new fileManip(file_in,gal)),
     how_search(search), how_sort(sort) {}
     /**
	 * @brief: destructor of the GameGallery class
	 * 
	 * @param: None
	 * @return: GameGallery Object
	 */
    ~GameGallery();
     /**
         * @brief: saves the current database to a file using Filemanip
         *
         * @param: string new_file for name of file
         * @return: None
         */

     void newFile(string new_file);
    /**
	 * @brief: saves the current database to a file using Filemanip
	 * 
	 * @param: string save_file for name of file to save to
	 * @return: None
	 */
    void save(string save_file);
    /**
	 * @brief: loads the file to the database using Filemanip
	 * 
	 * @param: string load_file for name of file to load from
	 * @return: None
	 */
    void load(string load_file);
    /**
	 * @brief: sets the type of searching to be performed on the collection of VideoGame objects
	 * 
	 * @param: Searcher object that has method for searching with a particular field
	 * @return: None
	 */
    void setSearch(Searcher* search);
    /**
	 * @brief: sets the type of sorting to be performed on the collection of VideoGame objects
	 * 
	 * @param: Sorter object that has method for sorting with a particular field
	 * @return: None
	 */
    void setSort(Sorter* sort);
    /**
	 * @brief: finds the VideoGame wanted by calling the particular run-time implementation of searching selected
	 * 
	 * @param: None
	 * @return: VideoGame object
	 */
    VideoGame* search(string key) const;
    /**
	 * @brief: Sorts the VideoGame Collection by calling the particular run-time implementation of sorting selected
	 * 
	 * @param: None
	 * @return: None
	 */
    void sort();
    /**
	 * @brief: lets the user add a VideoGame into the database
	 * 
	 * @param: VideoGame object that is going to be added
	 * @return: None
	 */
    void addGame(VideoGame*);
    /**
	 * @brief: lets the user delete a VideoGame currently in the database
	 * 
	 * @param: VideoGame object
	 * @return: None
	 */
    void delGame(VideoGame*);
    /**
	 * @brief: prints every videogame in the colleciton of VideoGame
	 * 
	 * @param: None
	 * @return: None
	 */
    void print() const;
};

#endif //GAMEGALLERY_HPP
