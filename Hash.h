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

	static const int tableSize = 4;

	struct item {

		string name;
		string drink;
		item* next;

	};

	item* HashTable[tableSize];

public:

	Hash();
	int hash(string key);
	void addItem(string name, string drink);
	int numberOfItemsInIndex(int index);
	void printTable();
	void printItemsInIndex(int index);
	void findDrink(string name);
	void removeItem(string name);



};

#endif