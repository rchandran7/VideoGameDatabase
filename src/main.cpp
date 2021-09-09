#include "../header/gamegallery.hpp"
#include "../header/collection.hpp"
#include "nlohmann/json.hpp"
#include "../header/fileManip.hpp"
#include "../header/sort_name.hpp"
#include "../header/sort_pub.hpp"
#include "../header/sort_genre.hpp"
#include "../header/sort_year.hpp"
#include "../header/search_year.hpp"
#include "../header/search_name.hpp"
#include "../header/search_pub.hpp"
#include "../header/search_genre.hpp"
#include <sstream>
#include <string>

int main() {
    char choice = '5';
    char type = '1';
    bool exit = false;
    bool made = false;
    string input;
    string name;
	unsigned int year = 2000;
	string publisher;
	string system;
	string genre;
	string rating = "E";
	string size;
	unsigned int cost = 60;
	unsigned int players = 2;
    stringstream ss;
    VideoGame* newGame;
    GameGallery* gall=new GameGallery();	
        
	while (!made) {
    cout << "Welcome to GameGallery!\n\n Please select the operation to perform on your file\n"
	 << "1. Load file. \n"
	 << "2. New File. \n\n";
    getline(cin, input);
    choice = input[0];
    switch(choice){
        case '1': cout << "Input file name.\n\n";
	getline(cin, name);
	gall->load(name);
    made = true;
    break;
    case '2': cout << "Input desired file name.\n\n";
	getline(cin, name);
	gall->newFile(name);
    made = true;
    break;
    default: cout << "That is not a valid option.\n\n";
    break;
    }
    }
    
    choice = '5';

    do { 

    cout << "Please select the operation to perform on your Video Games\n"
         << "1. add a video game.\n"
         << "2. delete a video game.\n"
         << "3. search for a video game.\n"
         << "4. sort your video games.\n"
         << "5. print your video games.\n"
         << "6. save your games.\n"
         << "7. exit.\n\n";

    getline(cin, input);
    choice = input[0];

    switch (choice) {
        case '1': try {
        cout <<"Enter info to add a video game.\nName: ";
        getline(cin, name);
        cout << "Year: ";
        getline(cin, input);
        //ss << input;
        ss = stringstream(input);
        ss >> year;
        ss.flush();
        cout << "Publisher: ";
        getline(cin, publisher);
        cout << "System: ";
        getline(cin, system);
        cout << "Genre: ";
        getline(cin, genre);
        cout << "Rating: ";
        getline(cin, rating);
        cout << "Size: ";
        getline(cin, size);
        cout << "Cost: ";
        getline(cin, input);
        //ss << input;
        ss = stringstream(input);
        ss >> cost;
        ss.flush();
        cout << "Players: ";
        getline(cin, input);
       // ss << input;
       ss = stringstream(input);
        ss >> players;
        ss.flush();
        newGame = new VideoGame(name, year, publisher, system, genre, rating, size, cost, players);
        newGame->print();
        gall->addGame(newGame);
        break;
        }
        catch (...) {
            cout << "INVALID INPUT>>>TRY AGAIN\n\n ";
            break;
        }
        case '2': cout << "How would you like to delete a video game?\n"
                        << "1. Name\n"
                        << "2. Year\n"
                        << "3. Publisher\n"
                        << "4. Genre\n";
        getline(cin, input);
        type = input[0];
        switch (type) {
            case '1': 
            gall->setSearch(new SearchName);
            cout <<"Enter the name of the Video Game\nName: ";
            getline(cin, name);
            newGame = gall->search(name);
            if (newGame != nullptr) {
            gall->delGame(newGame);
            cout << "Game was successfully deleted.\n\n";
            }
            else {
                cout << "Video Game asked to be deleted was not found\n\n";
            }
            break;
            case '2':
            gall->setSearch(new SearchYear);
            cout <<"Enter the year of the Video Game\nYear: ";
            getline(cin, input);
            newGame = gall->search(input);
            if (newGame != nullptr) {
            gall->delGame(newGame);
            cout << "Game was successfully deleted.\n\n";
            }
            else {
                cout << "Video Game asked to be deleted was not found\n\n";
            }
            break;
            case '3':
            gall->setSearch(new SearchPub);
            cout <<"Enter the publisher of the Video Game\nName: ";
            getline(cin, publisher);
            newGame = gall->search(publisher);
            if (newGame != nullptr) {
            gall->delGame(newGame);
            cout << "Game was successfully deleted.\n\n";
            }
            else {
                cout << "Video Game asked to be deleted was not found\n\n";
            }
            break;
            case '4':
            gall->setSearch(new SearchGenre);
            cout <<"Enter the genre of the Video Game\nName: ";
            getline(cin, genre);
            newGame = gall->search(genre);
            if (newGame != nullptr) {
            gall->delGame(newGame);
            cout << "Game was successfully deleted.\n\n";
            }
            else {
                cout << "Video Game asked to be deleted was not found\n\n";
            }
            break;
            default: cout << "That is not a valid option\n\n";
            break;
        }
        break;
        case '3': 
        cout << "How would you like to search for a video game?\n"
                        << "1. Name\n"
                        << "2. Year\n"
                        << "3. Publisher\n"
                        << "4. Genre\n";
        getline(cin, input);
        type = input[0];
        switch (type) {
            case '1': 
            gall->setSearch(new SearchName);
            cout <<"Enter the name of the Video Game\nName: ";
            getline(cin, name);
            newGame = gall->search(name);
            if (newGame != nullptr) {
            newGame->print();
            }
            else {
                cout << "Video Game could not be found\n\n";
            }
            break;
            case '2':
            gall->setSearch(new SearchYear);
            cout <<"Enter the year of the Video Game\nYear: ";
            getline(cin, input);
            newGame = gall->search(input);
            if (newGame != nullptr) {
            newGame->print();
            }
            else {
                cout << "Video Game could not be found\n\n";
            }
            break;
            case '3':
            gall->setSearch(new SearchPub);
            cout <<"Enter the publisher of the Video Game\nName: ";
            getline(cin, publisher);
            newGame = gall->search(publisher);
            if (newGame != nullptr) {
            newGame->print();
            }
            else {
                cout << "Video Game could not be found\n\n";
            }
            break;
            case '4':
            gall->setSearch(new SearchGenre);
            cout <<"Enter the genre of the Video Game\nName: ";
            getline(cin, genre);
            newGame = gall->search(genre);
            if (newGame != nullptr) {
            newGame->print();
            }
            else {
                cout << "Video Game could not be found\n\n";
            }
            break;
            default: cout << "That is not a valid option\n\n";
            break;
        }
        break;
        case '4':
        cout << "How would you like to sort the video games?\n"
                        << "1. Name\n"
                        << "2. Year\n"
                        << "3. Publisher\n"
                        << "4. Genre\n";
        getline(cin, input);
        type = input[0];

        if (type == '1' ) {
            gall->setSort(new Sort_Name);
            gall->sort();
            cout << "The collection was sorted alphabetically by name\n\n";
        }
        else if (type == '2') {
            gall->setSort(new Sort_Year);
            gall->sort();
            cout << "The collection was sorted numerically by year\n\n";
        }
        else if (type == '3') {
            gall->setSort(new Sort_Pub);
            gall->sort();
            cout << "The collection was sorted alphabetically by publisher\n\n";
        }
        else if (type == '4') {
            gall->setSort(new Sort_Genre);
            gall->sort();
            cout << "The collection was sorted alphabetically by genre\n\n";
        }
        else {
            cout << "That is not a valid choice.\n\n";
        }
        break;
        case '5': gall->print();
        break;
        case '6': gall->save(name);
        cout << "Gallery was saved to the file.\n\n";
        break;
        case '7': exit = true;
        break;
        default: cout << "That is not a valid option, please try again...\n\n";
        break;
    }

    } while (!exit);

    cout << "Thanks for using Game Gallery!\n\n";

    gall->save(name);

    delete gall;
    gall = nullptr;

    return 0;
}
