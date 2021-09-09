#ifndef VIDEOGAME_HPP
#define VIDEOGAME_HPP
#include <iostream>
using namespace std;

static unsigned int newID = 1;

/**
	 * @brief: the class that has all the data related to VideoGames in the database
	 * 
	 */
class VideoGame {
	private:
		string name;
		unsigned int year;
		string publisher;
		string system;
		string genre;
		string rating;
		string size;
		unsigned int cost;
		unsigned int players;
		unsigned int id;
	public:
	/**
	 * @brief: basic constructor that initializes a basic videogame
	 * 
	 * @param: None
	 * @return: VideoGame Object
	 */
		VideoGame() : name("Galaga"), year(1999), publisher("ATARI"), system("Arcade Machine"), 
		genre("shooter"), rating("E"), size("2.5 GB"), cost(35), players(1) { id = newID++; }
		/**
	 * @brief: constructor that initializes a basic videogame with passed in arguments
	 * 
	 * @param: nam: string, yr: int, sys: string, gen: string, rat: string, mem: string, value: int, play: int
	 * @return: VideoGame Object
	 */
		VideoGame(string nam, int yr, string pub, string sys, string gen, string rat, string mem,
		 int value, int play) : name(nam), year(yr), publisher(pub), system(sys), genre(gen), 
		 rating(rat), size(mem), cost(value), players(play) { id = newID++;}

/**
	 * @brief: VideoGame destructor
	 * 
	 * @param: None
	 * @return: None
	 */
		~VideoGame() {newID--;}
		/**
	 * @brief: basic print function that prints out all the video game data
	 * 
	 * @param: None
	 * @return: None
	 */
		string getjsonstring();
		
		void print() const;
		/**
	 * @brief: returns VideoGame id
	 * 
	 * @param: None
	 * @return: int id of the VideoGame class
	 */
		int getId() const;
		/**
	 * @brief: returns VideoGame name
	 * 
	 * @param: None
	 * @return: string name of the VideoGame class
	 */
		string getName() const;
		/**
	 * @brief: returns VideoGame year
	 * 
	 * @param: None
	 * @return: int year of the VideoGame class
	 */
		int getYear() const;
		/**
	 * @brief: returns VideoGame publisher
	 * 
	 * @param: None
	 * @return: string publisher of the VideoGame class
	 */
		string getPub() const;
		/**
	 * @brief: returns VideoGame system
	 * 
	 * @param: None
	 * @return: string system of the VideoGame class
	 */
		string getSystem() const;
		/**
	 * @brief: returns VideoGame genre
	 * 
	 * @param: None
	 * @return: string genre of the VideoGame class
	 */
		string getGenre() const;
		/**
	 * @brief: returns VideoGame rating
	 * 
	 * @param: None
	 * @return: string rating of the VideoGame class
	 */
		string getRating() const;
		/**
	 * @brief: returns VideoGame size
	 * 
	 * @param: None
	 * @return: string size of the VideoGame class
	 */
		string getSize() const;
		/**
	 * @brief: returns VideoGame cost
	 * 
	 * @param: None
	 * @return: int cost of the VideoGame class
	 */
		int getCost() const;
		/**
	 * @brief: returns VideoGame players
	 * 
	 * @param: None
	 * @return: int players of the VideoGame class
	 */
		int getPlayer() const;
		/**
	 * @brief: sets VideoGame name
	 * 
	 * @param: string representing name of the VideoGame
	 * @return: None
	 */
		void setName(string);
		/**
	 * @brief: sets VideoGame year
	 * 
	 * @param: string representing year of the VideoGame
	 * @return: None
	 */
		void setYear(int);
		/**
	 * @brief: sets VideoGame publisher
	 * 
	 * @param: string representing publisher of the VideoGame
	 * @return: None
	 */
		void setPub(string);
		/**
	 * @brief: sets VideoGame system
	 * 
	 * @param: string representing system of the VideoGame
	 * @return: None
	 */
		void setSystem(string);
		/**
	 * @brief: sets VideoGame genre
	 * 
	 * @param: string representing genre of the VideoGame
	 * @return: None
	 */
		void setGenre(string);
		/**
	 * @brief: sets VideoGame rating
	 * 
	 * @param: string representing rating of the VideoGame
	 * @return: None
	 */
		void setRating(string);
		/**
	 * @brief: sets VideoGame size
	 * 
	 * @param: string representing size of the VideoGame
	 * @return: None
	 */
		void setSize(string);
		/**
	 * @brief: sets VideoGame cost
	 * 
	 * @param: string representing cost of the VideoGame
	 * @return: None
	 */
		void setCost(int);
		/**
	 * @brief: sets VideoGame players
	 * 
	 * @param: string representing players of the VideoGame
	 * @return: None
	 */
		void setPlayer(int);
};
		
#endif //VIDEOGAME_HPP
