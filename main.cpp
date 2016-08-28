// Driver.cpp
// Alec Mas

#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

using namespace std;

int main() {

	Hash hashy;

	hashy.addItem("Alec", "Milk");
	hashy.addItem("Bob", "Juice");
	hashy.addItem("Carol", "Tea");
	hashy.addItem("Daniel", "Coffee");
	hashy.addItem("Eli", "Water");
	hashy.addItem("Fred", "Beer");

	cout << "Welcome to the basic Hash Table!" << endl;
	cout << "Here is a list of available options: " << endl;
	cout << endl;
	cout << "[1] Print contents of table" << endl;
	cout << "[2] Print contents of index" << endl;
	cout << "[3] Add entry" << endl;
	cout << "[4] Remove entry" << endl;
	cout << "[5] Find someone's favorite drink" << endl;
	cout << "[6] Exit" << endl;
	cout << endl;

	int input = 0;

	while (input != 6) {

		cout << "Command: ";
		cin >> input;						

		if (input == 1) {

			cout << endl;
			hashy.printTable();
			cout << endl;
			
		}

		else if (input == 2) {

			int index = 0;

			cout << endl;
			cout << "What index would you like to see?" << endl;
			cout << "Index: ";
			cin >> index;					
			cout << endl;

			hashy.printItemsInIndex(index);
			cout << endl;

		}

		else if (input == 3) {

			string newName;
			string newDrink;

			cout << endl;
			cout << "First name: ";
			cin >> newName;					

			cout << "Favorite drink: ";			
			cin >> newDrink;				
			cout << endl;
			
			hashy.addItem(newName, newDrink);
			cout << "Entry added!" << endl;
			cout << endl;

		}

		else if (input == 4) {

			string removeName;

			cout << endl;
			cout << "Name of entry to be removed: ";
			cin >> removeName;				

			cout << endl;
			hashy.removeItem(removeName);
			cout << endl;

		}

		else if (input == 5) {

			string searchName;

			cout << endl;
			cout << "Search name: ";
			cin >> searchName;				

			cout << endl;
			hashy.findDrink(searchName);
			cout << endl;

		}

		else if (input == 6) {

			cout << endl;
			cout << "Exiting program..." << endl;

		}

		else {

			cout << endl;
			cout << "Please enter a valid command number" << endl;
			cout << endl;

		}

	}

	return 0;

}