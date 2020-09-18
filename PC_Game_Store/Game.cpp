//Game.cpp

#include <iostream>
#include <ostream>
#include <iomanip>
#include "Game.h"
using namespace std;


Game::Game() {
	name = "";
	publisher = "";
	genre = "";
	description = "";
	rating = ' ';
	price = 0;
	quantity = 0;
}

Game::Game(string name, string publisher, string genre, char rating, double price, string description, int quantity) {
	this->name = name;
	this->publisher = publisher;
	this->genre = genre;
	this->rating = rating;
	this->price = price;
	this->description = description;
	this->quantity = quantity;
}

Game::~Game() {}

string Game::getName() const {
	return name;
}

string Game::getPublisher() const {
	return publisher;
}

string Game::getGenre() const {
	return genre;
}

string Game::getDescription() const {
	return description;
}

char Game::getRating() const {
	return rating;
}

double Game::getPrice() const {
	return price;
}

int Game::getQuantity() const {
	return quantity;
}

void Game::setName(string name) {
	this->name = name;
}

void Game::setPublisher(string publisher) {
	this->publisher = publisher;
}

void Game::setGenre(string genre) {
	this->genre = genre;
}

void Game::setDescription(string description) {
	this->description = description;
}

void Game::setRating(char rating) {
	this->rating = rating;
}

void Game::setPrice(double price) {
	this->price = price;
}

void Game::setQuantity(int quantity) {
	this->quantity = quantity;
}

void Game::printAllGameInfo(ostream& os) const {
	os << name << " by " << publisher << endl << genre << endl;
	os << "Rated " << rating << " for ";
	if (rating == 'E')
		os << "Everyone" << endl;
	else if (rating == 'M')
		os << "Mature" << endl;
	else
		os << "Teen" << endl;
	os << "$" << fixed << setprecision(2) << price << endl;
	os << "Description: " << description << endl;
}

bool Game::operator==(const Game& game) {
    return (name == game.name);
}

bool Game::operator<(const Game& game) {
	if (name < game.name)
		return true;
	return false;
}

bool Game::operator>(const Game& game) {
	if (name >= game.name)
		return true;
	return false;
}

bool Game::operator>=(const Game& game) {
	if (name >= game.name)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Game& game) {
	os << game.name << " by " << game.publisher << endl << game.genre << endl << "Rating: " << game.rating << endl << "$" << fixed << setprecision(2) << game.price << endl;
	return os;
}
