//BSTAndGamesUI.cpp
/*

#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

//Inputs information from file into game inventory
void fileInputForInventory(string& file, ifstream& fin, string& empty, string& name, string& publisher,
	 string& genre, string& description, char& rating, double& price, BST<Game>& games, BST<Game>& gamesP);

//View the inventory of games unsorted (Customer and Employee)
void viewUnsortedInventory(BST<Game>& games);

//View the inventory of games sorted by name (Customer and Employee)
void viewInventorySortedByName(BST<Game>& games);

//View the inventory of games sorted by publisher (Customer and Employee)
void viewInventorySortedByPublisher(BST<Game>& gamesP);

//Remove a game from the inventory (Employee)
void removeAGame(string& name, string& publisher, BST<Game>& games, BST<Game>& gamesP);

//Add a game to the inventory (Employee)
void addAGame(string& name, string& publisher, string& genre, string& description, char& rating, double& price,
	 BST<Game>& games, BST<Game>& gamesP);

//Search inventory of games by name (Customer)
void searchInventoryByName(string& name, BST<Game>& games);

//Search inventory of games by publisher (Customer)
void searchInventoryByPublisher(string& publisher, BST<Game>& gamesP, BST<Game>& games);

//Edit a game (Employee)
void editAGame(string& name, string& publisher, string& genre, string& description, char& rating,
	 double& price, BST<Game>& games, BST<Game>& gamesP, char& input, int& count);

//File output for inventory
void fileOutputForInventory(string& file, ofstream& fout, BST<Game>& games);

int main() {

	string file = "games.txt"; //stores file name where all game input is
	ifstream fin;
	ofstream fout;

	string empty = ""; //stores empty line of input from file
	string name = "";
	string publisher = "";
	string genre = "";
	string description = "";
	char rating = ' ';
	double price = 0;

	BST<Game> games; //sort by name
	BST<Game> gamesP; //sort by publisher

	char input = ' '; //stores user input key
	int count = 0; //counts iteration number of while loop


	cout << "Welcome!\n\n";


	//File input for game inventory
	fileInputForInventory(file, fin, empty, name, publisher, genre, description, rating, price, games, gamesP);


	//View an unsorted inventory of games (customer and employee)
	viewUnsortedInventory(games);


	//View the inventory of games, sorted by name (customer and employee)
	viewInventorySortedByName(games);


	//View the inventory of games, sorted by publisher (customer and employee)
	viewInventorySortedByPublisher(gamesP);


	//Remove a game (employee)
	removeAGame(name, publisher, games, gamesP);


	//Add a game (employee)
	addAGame(name, publisher, genre, description, rating, price, games, gamesP);


	//Search inventory by name (customer)
	searchInventoryByName(name, games);


	//Search inventory by publisher (customer)
	searchInventoryByPublisher(publisher, gamesP, games);


	//Edit a game (employee)
	editAGame(name, publisher, genre, description, rating, price, games, gamesP, input, count);


	//Output data to file
	fileOutputForInventory(file, fout, games);


	cout << "\n*End of this test program*\n";

	return 0;
}

void fileInputForInventory(string& file, ifstream& fin, string& empty, string& name, string& publisher,
	 string& genre, string& description, char& rating, double& price, BST<Game>& games, BST<Game>& gamesP) {
	ofstream fout;

	fin.open(file);
	while (fin.fail()) {
		cout << "File could not be opened.\n\n";
		cout << "Please enter the name of your file with the game inventory: ";
		cin >> file;
		fin.open(file);
	}

	while (fin) {
		getline(fin, name);
		getline(fin, publisher);
		getline(fin, genre);
		fin >> rating;
		fin >> price;
		fin >> ws;
		getline(fin, description);
		getline(fin, empty);

		Game g(name, publisher, genre, rating, price, description, 0);
		games.insertByName(g);
		gamesP.insertByPublisher(g);
	}
	fout.open(file);
	fin.close();
	fout.close();
	cout << endl;
}

void viewUnsortedInventory(BST<Game>& games) {
	cout << "----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our unsorted inventory of " << games.size() << " games:\n";
	games.postOrderPrint(cout);
}

void viewInventorySortedByName(BST<Game>& games) {
	cout << "----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our inventory of " << games.size() << " games, sorted alphabetically by name:\n";
	games.inOrderPrint(cout);
}

void viewInventorySortedByPublisher(BST<Game>& gamesP) {
	cout << "----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our inventory of " << gamesP.size() << " games, sorted alphabetically by publisher:\n";
	gamesP.inOrderPrint(cout);
}

void removeAGame(string& name, string& publisher, BST<Game>& games, BST<Game>& gamesP) {
	cout << "----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	games.inOrderPrint(cout);

	cout << "Enter the information about a game you wish to remove.\n";
	cout << "Name: ";
	cin >> ws;
	getline(cin, name);
	cout << "Publisher: ";
	getline(cin, publisher);
	Game g3;
	g3.setName(name);
	g3.setPublisher(publisher);
	while ((games.empty() && gamesP.empty()) || (!games.searchByName(g3) && !gamesP.searchByPublisher(g3))) {
		if (games.empty() && gamesP.empty())
			cout << "\n(No game could be removed because the game inventory is empty.)\n";
		else {
			cout << "\nSorry. " << name << " by " << publisher << " could not be found.\n";
			cout << "Please re-enter the information about a game you wish to remove:\n";
			cout << "Name: ";
			getline(cin, name);
			cout << "Publisher: ";
			getline(cin, publisher);
			g3.setName(name);
			g3.setPublisher(publisher);
		}
	}
	gamesP.removeByPublisher(g3);
	games.removeByName(g3);

	cout << name << " by " << publisher << " has been removed.\n\n";

	cout << "Here is our updated inventory of " << games.size() << " games:\n";
	games.inOrderPrint(cout);
}

void addAGame(string& name, string& publisher, string& genre, string& description, char& rating, double& price,
	 BST<Game>& games, BST<Game>& gamesP) {
	cout << "----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	games.inOrderPrint(cout);

	cout << "Enter the information about a game you wish to add.\n";
	cout << "Name: ";
	cin >> ws;
	getline(cin, name);
	cout << "Publisher: ";
	getline(cin, publisher);
	cout << "Genre: ";
	getline(cin, genre);
	cout << "Rating: ";
	cin >> rating;
	cout << "Price: ";
	cin >> price;
	cout << "Description: ";
	cin >> ws;
	getline(cin, description);

	Game g4;
	g4.setName(name);
	g4.setPublisher(publisher);
	g4.setGenre(genre);
	g4.setRating(rating);
	g4.setPrice(price);
	g4.setDescription(description);

	gamesP.insertByPublisher(g4);
	games.insertByName(g4);

	cout << "\nHere is the game to be inserted:\n";
	g4.printAllGameInfo(cout);

	cout << "\nHere is our updated inventory of " << games.size() << " games:\n";
	games.inOrderPrint(cout);
}

void searchInventoryByName(string& name, BST<Game>& games) {
	cout << "----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	games.inOrderPrint(cout);

	cout << "Enter the name of a game you wish to search for.\n";
	cout << "Name: ";
	cin >> ws;
	getline(cin, name);
	Game g5;
	g5.setName(name);
	cout << "\nFound the following:\n";
	games.searchAndPrintByName(cout, g5);
	cout << endl << endl;
}

void searchInventoryByPublisher(string& publisher, BST<Game>& gamesP, BST<Game>& games) {
	cout << "----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	games.inOrderPrint(cout);

	Game g6;
	cout << "Enter the publisher of a game you wish to search for.\n";
	cout << "Publisher: ";
	cin >> ws;
	getline(cin, publisher);
	g6.setPublisher(publisher);
	cout << "\nFound the following:\n";
	gamesP.searchAndPrintByPublisher(cout, g6);
	cout << endl << endl;
}

void editAGame(string& name, string& publisher, string& genre, string& description, char& rating,
	 double& price, BST<Game>& games, BST<Game>& gamesP, char& input, int& count) {
	cout << "----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	games.inOrderPrint(cout);

	cout << "Enter the information about a game you wish to edit:\n";
	cout << "Name: ";
	cin >> ws;
	getline(cin, name);
	Game g1;
	g1.setName(name);
	cout << "Publisher: ";
	getline(cin, publisher);
	g1.setPublisher(publisher);
	while (games.empty() || !games.searchByName(g1)) {
		if (games.empty())
			cout << "\n(No game can be edited because the game inventory is empty.)\n";
		else {
			cout << "\nSorry. " << name << " by " << publisher << " could not be found.\n";
			cout << "Please re-enter the information about a game you wish to edit:\n";
			cout << "Name: ";
			cin >> ws;
			getline(cin, name);
			g1.setName(name);
			cout << "Publisher: ";
			getline(cin, publisher);
			g1.setPublisher(publisher);
		}
	}

	Game g2 = games.returnData(g1);
	games.removeByName(g2);
	gamesP.removeByPublisher(g2);
	count = 1;
	do {
		cout << "\nWhat ";
		if (count != 1) {
			cout << "else ";
			games.removeByName(g2);
			gamesP.removeByPublisher(g2);
		}
		cout << "would you like to edit about this game?\n";
		cout << "[N - Name] [P - Publisher] [G - Genre] [R - Rating] [$ - Price] [D - Description] [Q - Quit This Operation]\nEnter Key: ";
		cin >> input;

		if (input == 'N') {
			cout << "Enter another name for " << name << ": ";
			cin >> ws;
			getline(cin, name);
			g2.setName(name);
		} else if (input == 'P') {
			cout << "Enter another publisher for " << name << ": ";
			cin >> ws;
			getline(cin, publisher);
			g2.setPublisher(publisher);
		} else if (input == 'G') {
			cout << "Enter another genre for " << name << ": ";
			cin >> ws;
			getline(cin, genre);
			g2.setGenre(genre);
		} else if (input == 'R') {
			cout << "Enter another rating for " << name << ": ";
			cin >> rating;
			g2.setRating(rating);
		} else if (input == '$') {
			cout << "Enter another price for " << name << ": ";
			cin >> price;
			g2.setPrice(price);
		} else if (input == 'D') {
			cout << "Enter another description for " << name << ": ";
			cin >> ws;
			getline(cin, description);
			g2.setDescription(description);
		}
		count++;

		cout << endl << name << " by " << publisher << " has been removed.\n";

		cout << "\nHere is the updated game:\n";
		g2.printAllGameInfo(cout);
		cout << "\nHere is the updated inventory of games:\n";
		games.insertByName(g2);
		gamesP.insertByPublisher(g2);
		games.inOrderPrint(cout);
	} while (input == 'N' || input == 'P' || input == 'G' || input == 'R'
			|| input == '$' || input == 'D');
}

void fileOutputForInventory(string& file, ofstream& fout, BST<Game>& games) {
	cout << "----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";

	fout.open(file);
	games.outputAllData(fout);

	cout << "(The updated data of the inventory of games is now written to the file " << file << ".)" << endl;
	fout.close();
}

*/
