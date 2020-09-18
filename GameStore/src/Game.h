// just take BST.h, Game.h, Game.cpp, games.txt, and
// BSTAndGamesUITest.cpp
// that's all you need to run
// ignore the rest

//Game.h

#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <ostream>
using namespace std;

class Game {
private:
    string name;
    string publisher; //developer
    string genre;
    string description;
    char rating;
    double price;
    int quantity;

public:

/**Constructors*/
    Game(); //Default constructor
    Game(string name, string publisher, string genre, char rating, double price, string description, int quantity); //Constructor
    ~Game(); //Destructor

    /**Access Functions*/
    string getName() const; //Getter for name
    string getPublisher() const; //Getter for publisher
    string getGenre() const; //Getter for genre
    string getDescription() const; //Getter for description
    char getRating() const; //Getter for rating
    double getPrice() const; //Getter for price
    int getQuantity() const; //Getter for quantity

    /**Manipulation Procedures*/
    void setName(string name); //Setter for name
    void setPublisher(string publisher); //Setter for publisher
    void setGenre(string genre); //Setter for genre
    void setDescription(string description); //Setter for description
    void setRating(char rating); //Setter for rating
    void setPrice(double price); //Setter for price
    void setQuantity(int quantity); //Setter for quantity

/**Additional Functions*/

    void printAllGameInfo(ostream& os) const;
    //Prints everything about the game
    //Called when user selects game from list and wants to see more information
    //Prints in the following format:
    //<name> by <publisher>
    //<genre>
    //Rated <rating> for <long form of rating, ex: "Everyone" if rating is set to 'E'>
    //$<price>
    //<blank line>
    //Description: <description>

    friend ostream& operator<<(ostream& os, const Game& game);
    //prints out a game to the designated stream in the following format:
    //<name> by <publisher>
    //<genre>
    //Rating: <rating>
    //$<price>
    //note that the << is required to be a friend function, not a member function
    //note2: do not print out the <> as part of the output
    //note3: publisher and description will be printed out if user wants to know more about game

    bool operator==(const Game& game);
    //compares two games (by name) to determine if they are the same game

    bool operator<(const Game& game);
    //compares two games to determine if one comes before the other
    //alphabetically by name
    //returns false if the two games are the same

    bool operator>(const Game& game);
        //compares two games to determine if one comes after the other
        //alphabetically by name
        //returns false if the two games are the same

    bool operator>=(const Game& game);
    //compares two games to determine if one comes after (or is the same as) the other
    //alphabetically by name
    //returns false if the two games are the same
};

#endif /* GAME_H_ */
