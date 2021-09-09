# Video Game Gallery
 
 > Authors: 
 [Matthew Hunt](https://github.com/coding-cat-cosmo),
 [Cody Phu](https://github.com/codyphu),
 [Rohit Chandran](https://github.com/rchandran7)

## Project Description
Video Games have a large presence in todays’ society so having a database for them with all the information at a user’s fingertips could save a lot of searching and backlogging to get specific data about each game.

The language we will be implementing this database with is C++.
* Tools/Technology:
  * [Doxygen](https://www.doxygen.nl/index.html) for standardized documentation across different classes
  * [JSON](https://github.com/nlohmann/json) for storage of data for video games within the database
  * [GitHub](https://github.com/) for code repository and to share code with each person
  * [Google Tests](https://github.com/google/googletest) for testing classes/units/funtions/etc.
  * [Valgrind](https://valgrind.org/) for testing classes/units/functions for memory leaks

The input should be data about the video game such as title, genre, system, etc.
The output should be data about the game selected by the user.


Composite and Strategy are the design patterns we will be using.

Composite- We picked composite in order to create a tree for our database as it is the most applicable design pattern for this idea. There will be issues with structure and organization of where video games will be placed. Using composite will organize and simplify how the data is arranged and managed. This is a good solution because it will treat the video games as collections of leaf nodes rather than individual data.

Strategy- We chose strategy in order to extend the allow the client to choose the appropriate	function for what they need. There will be different sets of data within the database and there will be a need for differentiation for unique features for specific data of video games. Strategy will allow us to create more features with less code redundancy. This is a good solution because strategy will reduce the amount of code required for necessary functions and overcome limitations from just inheritance.

Using these two design patterns together makes it a lot easier to create our database. By using the Composite pattern we make sure that each video game is much more easy to manage then if we tried one by one. Additionally, adding the Strategy pattern allows us to switch between different ways to search or sort the database so that the user can use different keywords or algorithms to easily find or organize their collection. Putting it all together will help make the database as responsive as possible for the user.


## Class Diagram

The Client will interact with the program by selecting which sorting or selecting method they want. The Client will also be able to add and delete video games from the collection. They will also be able to print the entire database or data about a videogame they searched for.
The base class, GameGallery, has multiple aggregations with objects for file manipulation, strategies for sorting and finding different video games, and a composite for individually managing all of the video games in the library.

There are multiple strategies used to create different types of algorithms with inheritance for searching and sorting the collection of video games. In the GameGallery class there is a pointer to the abstract base class that then uses polymorphism to select the right algorithm. The search can be done by name, publisher, genre, or year it came out. The same goes for the sorting of the collection. The classes implement an abstract base class which means they all have either the same sort function, or the same search function.

The actual manipulation (like adding and deleting video games) of the data from the video games is done by the composite Collection and VideoGame. Collection is managing VideoGame in order to create the composite. The composite is taking on the role of encapsulating all of the Video Game information within its functionality.

 File manipulation is done in its own class to avoid having too heavy of a load on the base class. The class itself will work directly with a JSON file. 
 
 ![Class Diagram](https://github.com/cs100/final-project-mhunt023-cphu003-rchan121/blob/master/Class%20Diagram%20(5).png)
 
 ## Screenshots
 ![NewFileandAdd](https://github.com/cs100/final-project-mhunt023-cphu003-rchan121/blob/master/cs100projectNewFile%26Add.png)
 ![PrintandExit](https://github.com/cs100/final-project-mhunt023-cphu003-rchan121/blob/master/cs100projectPrint%26Exit.png)
 ![LoadFileandSearch](https://github.com/cs100/final-project-mhunt023-cphu003-rchan121/blob/master/cs100projectLoadFile%26Search.png)
 ![Sort](https://github.com/cs100/final-project-mhunt023-cphu003-rchan121/blob/master/cs100projectSort.png)
 ![Delete](https://github.com/cs100/final-project-mhunt023-cphu003-rchan121/blob/master/cs100projectDelete.png)
 ![FinalFile](https://github.com/cs100/final-project-mhunt023-cphu003-rchan121/blob/master/cs100projectfile.png)
 ## Installation/Usage
Run cmake to make the tests and the executable itself where you can load save and create a gamegallery, and ./game is the executable.
You can enter in a new file with a name or load an old file by name and add, delete, search, sort, or print your video games. 
Prompts are given on what to enter for each operation you perform on the database. 
Doxygen requires flex, bison, libiconv, GNU, Python 2.7 and higher and CMake 3.3 or later.
 ## Testing
 Our project was tested using googletest which works well since we made it exclusively using C++ as well as using valgrind for memory leaks and JSON for file storing. 
 We unit tested each class before adding it together into the master branch and then after adding fixed up the interface and operations for the database.
 
