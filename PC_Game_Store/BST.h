//BST.h 

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <ostream>
#include <string>
#include <assert.h>
#include <cstddef>
#include "Game.h"
using namespace std;

template<typename bstdata>
class BST {
private:
	struct Node {
		bstdata data;
		Node* left;
		Node* right;

		Node(bstdata newdata) :
				left(NULL), right(NULL), data(newdata) {
		}
	};

	typedef struct Node* NodePtr;

	NodePtr root;

	/**Private helper functions*/
	void insertByName(NodePtr root, bstdata value);
	//private helper function for insertbyName
	//recursively inserts a value into the BST by primary key (name)

	void insertByPublisher(NodePtr root, Game g);
	//private helper function for inserting games
	//according to secondary key (publisher)

	void inOrderPrint(ostream& out, NodePtr root) const;
	//private helper function for inOrderPrint
	//recursively prints tree values in order from smallest to largest

	void preOrderPrint(ostream& out, NodePtr root) const;
	//private helper function for preOrderPrint
	//recursively prints tree values in pre order

	void postOrderPrint(ostream& out, NodePtr root) const;
	//private helper function for postOrderPrint
	//recursively prints tree values in post order

	void outputAllData(ostream& out, NodePtr root) const;
	//private helper function for outputAllData
	//recursively prints tree values in pre order using output stream

	void searchAndPrintByName(ostream& out, NodePtr root, bstdata value, int& count) const;
	//private helper function to searchAndPrintByName
	//recursively searches BST for matching game name, and prints out all
	//elements that share the name

	void searchAndPrintByPublisher(ostream& out, NodePtr root, bstdata value, int& count) const;
	//private helper function to searchAndPrintByPublisher
	//recursively searches BST for matching game publisher, and prints out all
	//elements that share the publisher

	void makeCopy(NodePtr copy);
	//recursive helper function to the copy constructor

	void freeNode(NodePtr root);
	//private helper function for the destructor
	//recursively frees the memory in the BST

	bool searchByName(NodePtr root, bstdata value) const;
	//recursive helper function to searchByName
	//returns whether the value is found in the tree by name

	bool searchByPublisher(NodePtr root, bstdata value) const;
	//recursive helper function to searchByPublisher
	//returns whether the value is found in the tree by publisher

	bstdata returnData(NodePtr root, bstdata value) const;
	//recursive helper function to returnData
	//returns all information about data (game) that matches value
	//(publisher and name stored in game) as input

	bstdata minimum(NodePtr root) const;
	//recursive helper function to minimum
	//returns the minimum value in the tree

	bstdata maximum(NodePtr root) const;
	//recursive helper function to maximum
	//returns the maximum value in the tree

	NodePtr deleteByName(NodePtr root, bstdata value);
	//recursive helper function to removeByName
	//removes value from the tree by primary key (name)

	NodePtr deleteByPublisher(NodePtr root, bstdata value);
	//recursive helper function to removeByPublisher
	//removes value from the tree by primary key (publisher)

	void size(NodePtr root, int& size);
	//recursive helper function to the size function
	//calculates the size of the tree
	//stores the result in size

	int height(NodePtr root) const;
	//recursive helper function to the height function
	//returns the height of the tree

public:

	/**constructors and destructor*/

	BST();
	//Instantiates a new BST

	BST(const BST &bst);
	//copy constructor

	~BST();
	//deallocates the tree memory

	/**access functions*/

	bstdata minimum() const;
	//returns the minimum value in the BST
	//pre: !empty()

	bstdata maximum() const;
	//returns the maximum value in the BST and returns it
	//pre: !empty()

	bool empty() const;
	//determines whether the BST is empty

	int size();
	//returns the size of the tree

	bstdata getRoot() const;
	//returns the value stored at the root of the BST
	//pre: !empty()

	int height() const;
	//returns the height of the tree

	bool searchByName(bstdata value) const;
	//returns whether the value is found in the tree sorted by name
	//pre: !empty()

	bool searchByPublisher(bstdata value) const;
	//returns whether the value is found in the tree sorted by publisher
	//pre: !empty()

	bstdata returnData(bstdata value) const;
	//returns all information about data (game) in bST
	//given input (a game with name and publisher stored)
	//pre: searchByName()

	/**manipulation procedures*/

	void insertByName(bstdata value);
	//inserts a new value into the BST by primary key (name)

	void insertByPublisher(Game g);
	//inserts a game into BST according to publisher
	//(secondary key)

	void removeByName(bstdata value);
	//removes the specified value from the tree by primary key (name)
	//pre: value is located in the tree

	void removeByPublisher(bstdata value);
	//removes the specified value from the tree by primary key (publisher)
	//pre: value is located in the tree

	/**additional functions*/

	void inOrderPrint(ostream& out) const;
	//calls the inOrderPrint function to print out the values
	//stored in the BST

	void preOrderPrint(ostream& out) const;
	//calls the reOrderPrint function to print out the values
	//stored in the BST

	void postOrderPrint(ostream& out) const;
	//calls the postOrderPrint function to print out the values
	//stored in the BST

	void outputAllData(ostream& out) const;
	//calls the outputAllData function to print out the values
	//stored in the BST into the output stream in preOrder

	void searchAndPrintByName(ostream& out, bstdata value) const;
	//calls the searchAndPrintByName function in order to print all games
	//with matching name input

	void searchAndPrintByPublisher(ostream& out, bstdata value) const;
	//calls the searchAndPrintByPublisher function in order to print all games
	//with matching publisher input

};


template<class bstdata>
BST<bstdata>::BST() {
	root = NULL;
}

template<class bstdata>
BST<bstdata>::BST(const BST &bst) {
	if (bst.root == NULL) {
		root = NULL;
		return;
	} else
		root = NULL;
	makeCopy(bst.root);
}

template<class bstdata>
void BST<bstdata>::makeCopy(NodePtr copy) {

	if (copy != NULL) {
		insertByName(copy->data);
		makeCopy(copy->left);
		makeCopy(copy->right);
	}
}

template<class bstdata>
BST<bstdata>::~BST() {
	if (root != NULL)
		freeNode(root);
}

template<class bstdata>
void BST<bstdata>::freeNode(NodePtr root) {
	if (root == NULL)
		return;
	if (root->left != NULL)
		freeNode(root->left);
	if (root->right != NULL)
		freeNode(root->right);
	delete root;
}

template<class bstdata>
bstdata BST<bstdata>::minimum() const {
	assert(!empty());
	return minimum(root);
}

template<class bstdata>
bstdata BST<bstdata>::minimum(NodePtr root) const {
	if (root->left != NULL)
		return minimum(root->left);
	else
		return root->data;
}

template<class bstdata>
bstdata BST<bstdata>::maximum() const {
	assert(!empty());
	return maximum(root);
}

template<class bstdata>
bstdata BST<bstdata>::maximum(NodePtr root) const {
	if (root->right != NULL)
		return maximum(root->right);
	else
		return root->data;
}

template<class bstdata>
bool BST<bstdata>::empty() const {
	return root == NULL;
}

template<class bstdata>
int BST<bstdata>::size() {
	int s = 0; //size local variable
	if (root == NULL)
		return 0;
	else {
		size(root, s);
		return s;
	}
}

template<class bstdata>
void BST<bstdata>::size(NodePtr root, int& s) {
	if (root == NULL)
		return;
	else {
		size(root->left, s);
		s++;
		size(root->right, s);
	}
}

template<class bstdata>
bstdata BST<bstdata>::getRoot() const {
	assert(!empty());
	return root->data;
}

template<class bstdata>
int BST<bstdata>::height() const {
	if (root == NULL)
		return -1;
	else
		return height(root);
}

template<class bstdata>
int BST<bstdata>::height(NodePtr root) const {

	if (root == NULL)
		return -1;

	int left_subtree_height = height(root->left);
	int right_subtree_height = height(root->right);

	if (left_subtree_height > right_subtree_height) {
		left_subtree_height++;
		return left_subtree_height;
	} else {
		right_subtree_height++;
		return right_subtree_height;
	}
}

template<class bstdata>
bool BST<bstdata>::searchByName(bstdata value) const {
	assert(!empty());
	Game g1 = root->data;
	Game g2 = value;
	if (value == root->data && g1.getPublisher() == g2.getPublisher())
		return true;
	else
		return searchByName(root, value);
}

template<class bstdata>
bool BST<bstdata>::searchByName(NodePtr root, bstdata value) const {
	Game g1 = value;
	Game g2 = root->data;
	if (value == root->data && g1.getPublisher() == g2.getPublisher())
		return true;
	else if (value < root->data) {
		if (root->left == NULL)
			return false;
		else
			return searchByName(root->left, value);
	} else if (value >= root->data) {
		if (root->right == NULL)
			return false;
		else
			return searchByName(root->right, value);
	}
	return false;
}

template<class bstdata>
bool BST<bstdata>::searchByPublisher(bstdata value) const {
	assert(!empty());
	Game g1 = root->data;
	Game g2 = value;
	if (value == root->data && g1.getPublisher() == g2.getPublisher())
		return true;
	else
		return searchByPublisher(root, value);
}

template<class bstdata>
bool BST<bstdata>::searchByPublisher(NodePtr root, bstdata value) const {
	Game g1 = value;
	Game g2 = root->data;
	if (value == root->data && g1.getPublisher() == g2.getPublisher())
		return true;
	else if (g1.getPublisher() < g2.getPublisher()) {
		if (root->left == NULL)
			return false;
		else
			return searchByPublisher(root->left, value);
	} else if (g1.getPublisher() >= g2.getPublisher()) {
		if (root->right == NULL)
			return false;
		else
			return searchByPublisher(root->right, value);
	}
	return false;
}

template<class bstdata>
bstdata BST<bstdata>::returnData(bstdata value) const {
	assert(searchByName(value));
	Game g1 = root->data;
	Game g2 = value;
	if (value == root->data && g1.getPublisher() == g2.getPublisher())
		return g1;
	else
		return returnData(root, value);
}

template<class bstdata>
bstdata BST<bstdata>::returnData(NodePtr root, bstdata value) const {
	Game g1 = root->data;
	Game g2 = value;
	Game g3;
	if (value == root->data && g1.getPublisher() == g2.getPublisher())
		return g1;
	else if (value < root->data) {
		if (root->left == NULL)
			return g3;
		else
			return returnData(root->left, value);
	} else if (value >= root->data) {
		if (root->right == NULL)
			return g3;
		else
			return returnData(root->right, value);
	}
	return g3;
}

template<class bstdata>
void BST<bstdata>::insertByName(bstdata value) {
	if (root == NULL)
		root = new Node(value);
	else
		insertByName(root, value);
}

template<class bstdata>
void BST<bstdata>::insertByName(NodePtr root, bstdata value) {
	if (root == NULL)
		root = new Node(value);
	else if (value < root->data) {
		if (root->left == NULL)
			root->left = new Node(value);
		else
			insertByName(root->left, value);
	} else {
		if (root->right == NULL)
			root->right = new Node(value);
		else
			insertByName(root->right, value);
	}
}

template<class bstdata>
void BST<bstdata>::insertByPublisher(Game g) {
	if (root == NULL)
		root = new Node(g);
	else
		insertByPublisher(root, g);
}

template<class bstdata>
void BST<bstdata>::insertByPublisher(NodePtr root, Game g1) {
	Game g2 = root->data;
	if (root == NULL)
		root = new Node(g1);
	else if (g1.getPublisher() < g2.getPublisher()) {
		if (root->left == NULL)
			root->left = new Node(g1);
		else
			insertByPublisher(root->left, g1);
	} else {
		if (root->right == NULL)
			root->right = new Node(g1);
		else
			insertByPublisher(root->right, g1);
	}
}

template<class bstdata>
void BST<bstdata>::removeByName(bstdata value) {
	assert(searchByName(value));
	root = deleteByName(root, value);
}

template<class bstdata>
typename BST<bstdata>::NodePtr BST<bstdata>::deleteByName(NodePtr root,
		bstdata value) {
	Game g1 = value;
	Game g2 = root->data;
	if (root == NULL)
		return root; //needed to collapse stack
	else if (value == root->data && g1.getPublisher() == g2.getPublisher()) // it's found
	{
		if (root->left == NULL && root->right == NULL) //case 1, parent no children
		{
			delete root;
			root = NULL;
		} else if (root->left != NULL && root->right == NULL) //case 2, parent with one lefty child
		{
			NodePtr temp = root;
			root = root->left;
			delete temp;
		} else if (root->left == NULL && root->right != NULL) //case 3, parent with one right child
		{
			NodePtr temp = root;
			root = root->right;
			delete temp;
		} else //case 4, parent with two children
		{ //find min in right, copy value to target node, delete dupe from right
			root->data = minimum(root->right);
			root->right = deleteByName(root->right, minimum(root->right));
		}
	}
	else if (value < root->data)
		root->left = deleteByName(root->left, value); //search adjustment/ recursion step
	else if (value >= root->data)
		root->right = deleteByName(root->right, value);

	return root;
}

template<class bstdata>
void BST<bstdata>::removeByPublisher(bstdata value) {
	assert(searchByPublisher(value));
	root = deleteByPublisher(root, value);
}

template<class bstdata>
typename BST<bstdata>::NodePtr BST<bstdata>::deleteByPublisher(NodePtr root,
		bstdata value) {
	Game g1 = value;
	Game g2 = root->data;
	if (root == NULL)
		return root; //needed to collapse stack
	else if (value == root->data && g1.getPublisher() == g2.getPublisher()) // it's found
	{
		if (root->left == NULL && root->right == NULL) //case 1, parent no children
		{
			delete root;
			root = NULL;
		} else if (root->left != NULL && root->right == NULL) //case 2, parent with one lefty child
		{
			NodePtr temp = root;
			root = root->left;
			delete temp;
		} else if (root->left == NULL && root->right != NULL) //case 3, parent with one right child
		{
			NodePtr temp = root;
			root = root->right;
			delete temp;
		} else //case 4, parent with two children
		{ //find min in right, copy value to target node, delete dupe from right
			root->data = minimum(root->right);
			root->right = deleteByPublisher(root->right, minimum(root->right));
		}
	}
	else if (g1.getPublisher() < g2.getPublisher())
		root->left = deleteByPublisher(root->left, value); //search adjustment/ recursion step
	else if (g1.getPublisher() >= g2.getPublisher())
		root->right = deleteByPublisher(root->right, value);

	return root;
}

template<class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out) const {
	inOrderPrint(out, root);
}

template<class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out, NodePtr root) const {
	if (root == NULL)
		return;
	inOrderPrint(out, root->left);
	out << root->data << endl;
	inOrderPrint(out, root->right);
}

template<class bstdata>
void BST<bstdata>::preOrderPrint(ostream& out) const {
	preOrderPrint(out, root);
}

template<class bstdata>
void BST<bstdata>::preOrderPrint(ostream& out, NodePtr root) const {
	if (root == NULL)
		return;
	out << root->data << endl;
	preOrderPrint(out, root->left);
	preOrderPrint(out, root->right);
}

template<class bstdata>
void BST<bstdata>::postOrderPrint(ostream& out) const {
	postOrderPrint(out, root);
}

template<class bstdata>
void BST<bstdata>::postOrderPrint(ostream& out, NodePtr root) const {
	if (root == NULL)
		return;
	postOrderPrint(out, root->left);
	postOrderPrint(out, root->right);
	out << root->data << endl;
}

template<class bstdata>
void BST<bstdata>::searchAndPrintByName(ostream& out, bstdata value) const {
	assert(!empty());
	int count = 0;
	Game g1 = root->data;
	Game g2 = value;
	searchAndPrintByName(out, root, value, count);
	if (count == 1)
		cout << "(Found 1 matching result.)";
	else
		cout << "(Found " << count << " matching results.)";
}

template<class bstdata>
void BST<bstdata>::searchAndPrintByName(ostream& out, NodePtr root, bstdata value, int& count) const {
	Game g1 = root->data;
	Game g2 = value;
	if (g2.getName() == g1.getName()) {
		g1.printAllGameInfo(out);
		cout << endl;
		count++;
	}
	if (g2.getName() < g1.getName()) {
		if (root->left == NULL)
			return;
		else
			searchAndPrintByName(out, root->left, value, count);
	}
	if (g2.getName() >= g1.getName()) {
		if (root->right == NULL)
			return;
		else
			searchAndPrintByName(out, root->right, value, count);
	}
	return;
}

template<class bstdata>
void BST<bstdata>::searchAndPrintByPublisher(ostream& out, bstdata value) const {
	assert(!empty());
	int count = 0;
	Game g1 = root->data;
	Game g2 = value;
	searchAndPrintByPublisher(out, root, value, count);
	if (count == 1)
			cout << "(Found 1 matching result.)";
	else
		cout << "(Found " << count << " matching results.)";
}

template<class bstdata>
void BST<bstdata>::searchAndPrintByPublisher(ostream& out, NodePtr root, bstdata value, int& count) const {
	Game g1 = root->data;
	Game g2 = value;
	if (g2.getPublisher() == g1.getPublisher()) {
		g1.printAllGameInfo(out);
		cout << endl;
		count++;
	}
	if (g2.getPublisher() < g1.getPublisher()) {
		if (root->left == NULL)
			return;
		else
			searchAndPrintByPublisher(out, root->left, value, count);
	}
	if (g2.getPublisher() >= g1.getPublisher()) {
		if (root->right == NULL)
			return;
		else
			searchAndPrintByPublisher(out, root->right, value, count);
	}
	return;
}

template<class bstdata>
void BST<bstdata>::outputAllData(ostream& out) const {
	outputAllData(out, root);
}

template<class bstdata>
void BST<bstdata>::outputAllData(ostream& out, NodePtr root) const {
	if (root == NULL)
		return;
	Game g = root->data;
	out << g.getName() << endl;
	out << g.getPublisher() << endl;
	out << g.getGenre() << endl;
	out << g.getRating() << endl;
	out << g.getPrice() << endl;
	out << g.getDescription() << endl << endl;

	outputAllData(out, root->left);
	outputAllData(out, root->right);
}

#endif /* BST_H_ */
