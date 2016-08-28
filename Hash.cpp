// Hash.cpp
// Alec Mas

#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

using namespace std;

// constructor populates hash table and sets all values to "empty"
Hash::Hash() {
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}

// takes a string and generates a hash value
int Hash::hash(string key) {
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;

	return index;
}

// adds an item to the hash table
void Hash::addItem(string name, string drink) {
	int index = hash(name);

	if (HashTable[index]->name == "empty") {
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else {
		item* ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while (ptr->next != NULL) {
			ptr = ptr->next;
		}

		ptr->next = n;	
	}
}

// returns the number of items in an index
int Hash::numberOfItemsInIndex(int index) {
	int count = 0;

	if (HashTable[index]->name == "empty") {
		return count;
	}
	else {
		count++;
		item* ptr = HashTable[index];

		while (ptr->next != NULL) {
			count++;
			ptr = ptr->next;
		}

		return count;
	}
}

// prints the hash table
void Hash::printTable() {
	int number;
	int count;

	for (int i = 0; i < tableSize; i++) {
		number = numberOfItemsInIndex(i);
		cout << "-----------------\n";
		cout << "Index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "-----------------\n";

		count += number;
	}

	if (count == 0) {
		cout << "Table is empty!" << endl;
	}
}

// prints the items contained in an index
void Hash::printItemsInIndex(int index) {
	item* ptr = NULL;

	if (index >= tableSize) {
		cout << "Index does not exist" << endl;
		return;
	}
	else {
		ptr = HashTable[index];
	}

	if (ptr->name == "empty") {
		cout << "Index = " << index << " is empty" << endl;
	}
	else {
		cout << "Index " << index << " contains the following item(s):\n";

		while (ptr != NULL) {
			cout << "-----------------\n";
			cout << ptr->name << endl;
			cout << ptr->drink << endl;
			cout << "-----------------\n";
			ptr = ptr->next;
		}
	}
}

// searches the hash table and prints that person's favorite drink
void Hash::findDrink(string name) {
	int index = hash(name);
	bool foundName = false;
	string drink;

	item* ptr = HashTable[index];

	if (HashTable[index]->name == name) {
		foundName = true;
		drink = ptr->drink;
	}

	while (ptr->next != NULL) {
		if(ptr->name == name) {
			foundName = true;
			drink = ptr->drink;
			break;					
		}

		ptr = ptr->next;
	}

	if (foundName == true) {
		cout << "Favorite drink = " << drink << endl;
	}
	else {
		cout << name << "'s info was not found in the Hash Table" << endl;
	}
}

// removes an item fron the hash table
void Hash::removeItem(string name) {
	int index = hash(name);		

	item* delPtr;
	item* ptr1;
	item* ptr2;

	// if bucket is empty
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty") {
		cout << name << " was not found in the Hash Table\n";
	}
	// else if there is 1 item contained in bucket and that item has matching name
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL) {
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		cout << name << " was removed from the Hash Table\n";
	}
	// else if match is located in the first item of the bucket, but there are more items in the bucket
	else if (HashTable[index]->name == name) {
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		cout << name << " was removed from the Hash Table\n";
	}
	// else the bucket contains items but first item is not a match
	else {
		ptr1 = HashTable[index]->next;
		ptr2 = HashTable[index];

		// while name has not been found, keep searching
		while (ptr1 != NULL && ptr1->name != name) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}

		// if name was never found
		if (ptr1 == NULL) {
			cout << name << " was not found in the Hash Table\n";
		}
		// else a match was found for item searched
		else {
			delPtr = ptr1;
			ptr1 = ptr1->next;
			ptr2->next = ptr1;
			delete delPtr;

			cout << name << " was removed from the Hash Table\n";
		}
	}
}