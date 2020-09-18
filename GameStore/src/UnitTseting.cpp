//UnitTesting.cpp
/*
#include <iostream>
#include <fstream>
#include "BST.h"
#include "Game.h"
using namespace std;

int main() {

	string name;
	string publisher;
	string genre;
	string description;
	char rating;
	double price;

	string file;
	ifstream fin;
	ofstream fout;

	string empty; //stores empty line of input from file
	string response;

	cout << "Welcome to the Best Games App!\n\n";
	cout << "Enter the name of the file for your game collection: ";
	cin >> file;
	fin.open(file);
	while (file != "games.txt" || fin.fail()) {
		cout << "Invalid file name!\n\n";
		cout << "Please enter the name of your file: ";
		cin >> file;
		fin.open(file);
	}

	BST<Game> games; //sort by name
	BST<Game> gamesP; //sort by publisher
	while (fin) {

		getline(fin, name);
		getline(fin, publisher);
		getline(fin, genre);
		fin >> rating;
		fin >> price;
		fin >> ws;
		getline(fin, description);
		getline(fin, empty);

		Game g(name, publisher, genre, rating, price, description);
		games.insertData(g);
		gamesP.insertPublisher(g);
	}

	cout << "The number of books in the game collection is: " << games.size()
			<< endl;
	cout << "The height of the game collection is: " << games.height() << endl
			<< endl;

	cout << "The first game in this collection is:\n" << games.minimum()
			<< endl;
	cout << "The last game in this collection is:\n" << games.maximum() << endl;

	cout << "Here is the entire collection of games: \n";
	games.inOrderPrint(cout);

	cout << "Which game would you like to view more information about?\n";
	cout << "Please enter its name: ";
	cin >> ws;
	getline(cin, name);
	Game g;
	g.setName(name);
	while (!games.search(g)) {
		cout << "Sorry, " << name << " is not in this collection!\n\n";

		cout
				<< "Please re-enter the name of a game you want to view more information about: ";
		getline(cin, name);
		//cout << "Publisher: ";
		//getline(cin, publisher);

		g.setName(name);
		//g.setPublisher(publisher);
	}
	cout << "\nHere is detailed information about " << name << ":\n";
	g = games.returnData(g);
	g.printAllGameInfo(cout);

	cout << "\nEnter the information about the game you wish to remove.\n";
	cout << "Name: ";
	getline(cin, name);
	cout << "Publisher: ";
	getline(cin, publisher);

	Game g1;
	g1.setName(name);
	g1.setPublisher(publisher);

	while (!games.search(g1)) {
		cout << "Sorry, " << name << " is not in this collection!\n\n";

		cout << "Enter the name of a game you wish to remove: ";
		getline(cin, name);
		cout << "Publisher: ";
		getline(cin, publisher);

		g1.setName(name);
		g1.setPublisher(publisher);
	}

	games.removeData(g1);
	cout << name << " has been removed!\n\n";

	cout << "The number of games in the collection is now: " << games.size()
			<< endl << endl;

	cout << "The games contained in this tree are now:\n\n";
	games.inOrderPrint(cout);

	cout << "Enter the name of a game you wish to insert: ";
	getline(cin, name);
	cout << "Enter the publisher of the game: ";
	getline(cin, publisher);
	cout << "Enter the genre of the game: ";
	getline(cin, genre);
	cout << "Enter the rating of the game: ";
	cin >> rating;
	cout << "Enter the price of the game: ";
	cin >> price;
	cout << "Enter the description of the game: ";
	cin >> ws;
	getline(cin, description);

	Game g2(name, publisher, genre, rating, price, description);
	games.insertData(g2);
	gamesP.insertPublisher(g2);
	cout << endl;

	cout << "The number of games in the collection is now: " << games.size()
			<< endl << endl;

	cout << "The books contained in this collection are now:\n\n";
	games.inOrderPrint(cout);

	cout << "Would you like to write this collection to a file? (yes/no): ";
	cin >> response;

	if (response == "Yes" || response == "yes" || response == "Y"
			|| response == "y") {
		cout << "Enter the file name: ";
		cin >> file;

		fout.open(file);
		games.preOrderPrint(fout);

		cout << "The data is now written to the file " << file << endl;
	}

	cout << endl << "Thank you! Goodbye!\n";

	fin.close();
	fout.close();

	return 0;

}
*/
