// Hash.h
// Alec Mas

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class Hash {

private: 

	// static table size initialized
	static const int tableSize = 4;

	// each item struct has a name and a drink, as well as a next pointer
	struct item {

		string name;
		string drink;
		item* next;

	};

	// initialize table of item pointers
	item* HashTable[tableSize];

public:

	// constructor populates hash table and sets all values to "empty"
	Hash();

	// takes a string and generates a hash value
	int hash(string key);

	// adds an item to the hash table
	void addItem(string name, string drink);

	// returns the number of items in an index
	int numberOfItemsInIndex(int index);

	// prints the hash table
	void printTable();

	// prints the items contained in an index
	void printItemsInIndex(int index);

	// searches the hash table and prints that person's favorite drink
	void findDrink(string name);

	// removes an item fron the hash table
	void removeItem(string name);

};

#endif