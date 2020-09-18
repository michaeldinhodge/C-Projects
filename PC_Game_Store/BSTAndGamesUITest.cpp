//BSTAndGamesUITest.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BST.h"
using namespace std;

//Recursively guides Customer through app using Customer input
void guideCustomer(string& file, ifstream& fin, ofstream& fout, string& empty, string& name, string& publisher,
	 string& genre, string& description, char& rating, double& price, BST<Game>& games, BST<Game>& gamesP,
	 char& input, int& count, int& numIteration);

//Recursively guides Employee through app using Employee input
void guideEmployee(string& file, ifstream& fin, ofstream& fout, string& empty, string& name, string& publisher,
	 string& genre, string& description, char& rating, double& price, BST<Game>& games, BST<Game>& gamesP,
	 char& input, int& count, int& numIteration);

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

	BST<Game> games; //sorted by name
	BST<Game> gamesP; //sorted by publisher

	char input = ' '; //stores user input key
	int count = 0; //counts iteration number of while loop
	int numIteration = 0; //keeps track of recursive iteration for guidesUser function

	cout << "Welcome to the Online Game Store!";

	fileInputForInventory(file, fin, empty, name, publisher, genre, description, rating, price, games, gamesP);

	cout << "\nPlease indicate whether you are a customer or an employee.\n";
	cout << "[C - Customer] [E - Employee] [Q - Quit this App]\n";
	cout << "Enter key: ";
	cin >> input;
	while (input != 'C' && input != 'E' && input != 'Q') {
		cout << "Please enter either C, E, or Q in order to select one of the above options: ";
		cin >> input;
	}
	if (input == 'C')
		guideCustomer(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
	else if (input == 'E')
		guideEmployee(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
	else {
		fileOutputForInventory(file, fout, games);
		cout << "\nThank you! Goodbye!\n";
	}

	return 0;
}

void guideCustomer(string& file, ifstream& fin, ofstream& fout, string& empty, string& name, string& publisher,
	 string& genre, string& description, char& rating, double& price, BST<Game>& games, BST<Game>& gamesP,
	 char& input, int& count, int& numIteration) {

	if (numIteration == 0)
		cout << "\nWhat would you like to do first?\n";
	else
		cout << "\nWhat would you like to do next?\n";
	cout << "[L - View the List of Games in Store] [S - Search for a Game] [Q - Quit the App]\n";
	cout << "Enter key: ";
	cin >> input;
	while (input != 'L' && input != 'S' && input != 'Q') {
		cout << "Please enter either L, S, or Q in order to select one of the above options: ";
		cin >> input;
	}

	if (input == 'L') {
		cout << "\nWould you like to:\n";
		cout << "[U - View an Unsorted List of Games] [N - View the List of Games Sorted by Name] [P - View the List of Games Sorted by Publisher] [Q - Quit this Operation]\n";
		cout << "Enter key: ";
		cin >> input;
		while (input != 'U' && input != 'N' && input != 'P' && input != 'Q') {
			cout << "Please enter either U, N, P, or Q in order to select one of the above options: ";
			cin >> input;
		}

		if (input == 'U') {
			viewUnsortedInventory(games);
			numIteration++;
			guideCustomer(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
		} else if (input == 'N') {
			viewInventorySortedByName(games);
			numIteration++;
			guideCustomer(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
		} else if (input == 'P') {
			viewInventorySortedByPublisher(gamesP);
			numIteration++;
			guideCustomer(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
		} //input is Q
		numIteration++;
		guideCustomer(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
				  input, count, numIteration);
	}
	else if (input == 'S') {
		cout << "\nWould you like to:\n";
		cout << "[N - Search for a Game by Name] [P - Search for a Game by Publisher] [Q - Quit this Operation]\n";
		cout << "Enter key: ";
		cin >> input;
		while (input != 'N' && input != 'P' && input != 'Q') {
			cout << "Please enter either N, P, or Q in order to select one of the above options: ";
			cin >> input;
		}

		if (input == 'N') {
			searchInventoryByName(name, games);
			numIteration++;
			guideCustomer(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
		} else if (input == 'P') {
			searchInventoryByPublisher(publisher, gamesP, games);
			numIteration++;
			guideCustomer(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
		} //input is Q
		numIteration++;
		guideCustomer(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
				  input, count, numIteration);
	}
	//If user enters 'Q' to quit the app
	cout << "\nAre you sure you want to quit the application?\n";
	cout << "[Y - Yes] [N - No]\n";
	cout << "Enter key: ";
	cin >> input;
	while (input != 'Y' && input != 'N') {
		cout << "Please enter either Y or N in order to select one of the above options: ";
		cin >> input;
	}

	if (input == 'N') {
		numIteration++;
		guideCustomer(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
				  input, count, numIteration);
	}
	else { //input is Y
		fileOutputForInventory(file, fout, games);
		cout << "\nThank you for visiting the Online Game Store!\n";
		exit(0);
	}
}

void guideEmployee(string& file, ifstream& fin, ofstream& fout, string& empty, string& name, string& publisher,
	 string& genre, string& description, char& rating, double& price, BST<Game>& games, BST<Game>& gamesP,
	 char& input, int& count, int& numIteration) {

	if (numIteration == 0)
		cout << "\nWhat would you like to do first?\n";
	else
		cout << "\nWhat would you like to do next?\n";
	cout << "[L - View the List of Games in Store] [A - Add a New Game] [D - Delete an Existing Game] [E - Edit a Game] [Q - Quit the App]\n";
	cout << "Enter key: ";
	cin >> input;
	while (input != 'L' && input != 'A' && input != 'D' && input != 'E' && input != 'Q') {
		cout << "Please enter either L, A, D, E, or Q in order to select one of the above options: ";
		cin >> input;
	}

	if (input == 'L') {
		cout << "\nWould you like to:\n";
		cout << "[U - View an Unsorted List of Games] [N - View the List of Games Sorted by Name] [P - View the List of Games Sorted by Publisher] [Q - Quit this Operation]\n";
		cout << "Enter key: ";
		cin >> input;
		while (input != 'U' && input != 'N' && input != 'P' && input != 'Q') {
			cout << "Please enter either U, N, P, or Q in order to select one of the above options: ";
			cin >> input;
		}

		if (input == 'U') {
			viewUnsortedInventory(games);
			numIteration++;
			guideEmployee(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
		} else if (input == 'N') {
			viewInventorySortedByName(games);
			numIteration++;
			guideEmployee(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
		} else if (input == 'P') {
			viewInventorySortedByPublisher(gamesP);
			numIteration++;
			guideEmployee(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
					  input, count, numIteration);
		} //input is Q
		numIteration++;
		guideEmployee(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
				  input, count, numIteration);
	}
	else if (input == 'D') {
		removeAGame(name, publisher, games, gamesP);
		numIteration++;
		guideEmployee(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
				  input, count, numIteration);
	}
	else if (input == 'A') {
		addAGame(name, publisher, genre, description, rating, price, games, gamesP);
		numIteration++;
		guideEmployee(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
				  input, count, numIteration);
	}
	else if (input == 'E') {
		editAGame(name, publisher, genre, description, rating, price, games, gamesP, input, count);
		numIteration++;
		guideEmployee(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
				  input, count, numIteration);
	}
	//If user enters 'Q' to quit the app
	cout << "\nAre you sure you want to quit the application?\n";
	cout << "[Y - Yes] [N - No]\n";
	cout << "Enter key: ";
	cin >> input;
	while (input != 'Y' && input != 'N') {
		cout << "Please enter either Y or N in order to select one of the above options: ";
		cin >> input;
	}

	if (input == 'N') {
		numIteration++;
		guideEmployee(file, fin, fout, empty, name, publisher, genre, description, rating, price, games, gamesP,
				  input, count, numIteration);
	}
	else { //input is Y
		fileOutputForInventory(file, fout, games);
		cout << "\nThank you for your time at the Online Game Store!\n";
		exit(0);
	}
}

void fileInputForInventory(string& file, ifstream& fin, string& empty, string& name, string& publisher,
	 string& genre, string& description, char& rating, double& price, BST<Game>& games, BST<Game>& gamesP) {

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

		if (name != "") {
			Game g(name, publisher, genre, rating, price, description, 0);
			games.insertByName(g);
			gamesP.insertByPublisher(g);
		}
	}
	fin.close();
	cout << endl;
}

void viewUnsortedInventory(BST<Game>& games) {
	cout << "\n----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our unsorted inventory of " << games.size() << " games:\n";
	if (!games.empty())
		games.postOrderPrint(cout);
	else
		cout << "Sorry, there are no games in the inventory to display unsorted.\n";
}

void viewInventorySortedByName(BST<Game>& games) {
	cout << "\n----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our inventory of " << games.size() << " games, sorted alphabetically by name:\n";
	if (!games.empty())
		games.inOrderPrint(cout);
	else
		cout << "Sorry, there are no games in the inventory to display, sorted by name.\n";
}

void viewInventorySortedByPublisher(BST<Game>& gamesP) {
	cout << "\n----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our inventory of " << gamesP.size() << " games, sorted alphabetically by publisher:\n";
	if (!gamesP.empty())
		gamesP.inOrderPrint(cout);
	else
		cout << "Sorry, there are no games in the inventory to display, sorted by publisher.\n";
}

void removeAGame(string& name, string& publisher, BST<Game>& games, BST<Game>& gamesP) {
	cout << "\n----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	if (!games.empty()) {
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
			cout << "\nSorry. " << name << " by " << publisher << " could not be found.\n";
			cout << "Please re-enter the information about a game you wish to remove:\n";
			cout << "Name: ";
			getline(cin, name);
			cout << "Publisher: ";
			getline(cin, publisher);
			g3.setName(name);
			g3.setPublisher(publisher);
		}
		gamesP.removeByPublisher(g3);
		games.removeByName(g3);

		cout << name << " by " << publisher << " has been removed.\n\n";

		cout << "Here is our updated inventory of " << games.size() << " games:\n";
		games.inOrderPrint(cout);
	}
	else
		cout << "Sorry, no game can be removed because there are no games in the inventory right now.\n";
}

void addAGame(string& name, string& publisher, string& genre, string& description, char& rating, double& price,
	 BST<Game>& games, BST<Game>& gamesP) {
	cout << "\n----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	if (!games.empty())
		games.inOrderPrint(cout);
	else
		cout << "Sorry, there are no games in the inventory to display right now.\n\n";

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
	cout << "\n----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	if (!games.empty()) {
		games.inOrderPrint(cout);

		cout << "Enter the name of a game you wish to search for.\n";
		cout << "Name: ";
		cin >> ws;
		getline(cin, name);
		Game g5;
		g5.setName(name);
		cout << "\nFound the following:\n";
		games.searchAndPrintByName(cout, g5);
		cout << endl;
	}
	else
		cout << "Sorry, no game can be searched for by name because there are no games in the inventory right now.\n";
}

void searchInventoryByPublisher(string& publisher, BST<Game>& gamesP, BST<Game>& games) {
	cout << "\n----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	if (!games.empty()) {
		games.inOrderPrint(cout);

		Game g6;
		cout << "Enter the publisher of a game you wish to search for.\n";
		cout << "Publisher: ";
		cin >> ws;
		getline(cin, publisher);
		g6.setPublisher(publisher);
		cout << "\nFound the following:\n";
		gamesP.searchAndPrintByPublisher(cout, g6);
		cout << endl;
	}
	else
		cout << "Sorry, no game can be searched for by publisher because there are no games in the inventory right now.\n";
}

void editAGame(string& name, string& publisher, string& genre, string& description, char& rating,
	 double& price, BST<Game>& games, BST<Game>& gamesP, char& input, int& count) {
	cout << "\n----------------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Here is our current inventory of " << games.size() << " games:\n";
	if (!games.empty()) {
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
			cout << "[N - Name] [P - Publisher] [G - Genre] [R - Rating] [$ - Price] [D - Description] [Q - Quit this Operation]\nEnter Key: ";
			cin >> input;
			while (input != 'N' && input != 'P' && input != 'G' && input != 'R'
				   && input != '$' && input != 'D' && input != 'Q') {
				cout << "Pleaes enter either N, P, G, R, $, D, or Q to select one of the options above: ";
				cin >> input;
			}

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
	else
		cout << "Sorry, no game can be edited because there are no games in the inventory right now.\n";
}

void fileOutputForInventory(string& file, ofstream& fout, BST<Game>& games) {
	fout.open(file);
	games.outputAllData(fout);
	fout.close();
}

