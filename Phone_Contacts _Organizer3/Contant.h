#pragma once
#include <iostream>
#include <string>
#include"function.h"
using namespace std;
int flag = 0;
class contact
{
	string name;
	string mob;

public:
	contact();
	void print();
	bool show();
	bool showName(string search_term);
	bool name_exists(string tname);
	bool add(string new_name, string new_mob);
	bool edit(string);
	bool erase(string new_name);
	string getName();
};
//This block of code resides inside the class
contact::contact() :name(""), mob("") {}

string contact::getName() {
	return name; }
bool contact::show()
{
	if (name != "")
	{
		// cout << name << "\t" << mob << endl;
		cout << endl;
		return 1; //Indicates success
	}
	else
		return 0; //Indicates failure
}

bool contact::showName(string search_term) {

	cout << "Showing Contacts" << endl;

//	    printline('-', 20);
	for (int o = 0; o<20; o++)
		cout << "-";
	cout << "\n";


	for (int i = 0; i<100; i++)
		if (search_term == name)
			flag = 1;



	if (!flag)
		cout << "No contacts found!" << endl;
	return 1;
}
bool contact::add(string new_name, string new_mob)
{
	if (name == "")
	{
		name = new_name;
		mob = new_mob;
		return 1; // Success
	}
	else
		return 0; // Failure

}

//The following code resides in the class
bool contact::edit(string new_name)
{
	string new_mob;
	if (new_name == name)
	{
		cout << " Menu " << endl;
		cout << "1. Edit Name only " << endl;
		cout << "2. Edit phone only" << endl;
		cout << "3. Edit Name and phone" << endl;
		cout << "Enter your choice :" << endl;
		int ch;
		cin >> ch;
		switch (ch) {
		case 1:
			cout << "Enter new name: ";
			cin >> new_name;
			name = new_name;
			break;
		case 2:
			cout << "Enter new mobile no: ";
			cin >> new_mob;
			mob = new_mob;
			break;

		case 3:
			cout << "Enter new name: ";
			cin >> new_name;
			cout << "Enter new mobile no: ";
			cin >> new_mob;

			name = new_name;
			mob = new_mob;
			return 1;
			break;
		}
	}
	else {
		return 0;
	}
}

// The following code resides in the class
bool contact::erase(string new_name)
{
	if (new_name == name)
	{
		name = "";
		mob = "";
		return 1;
	}
	else
		return 0;
}

// The following code resides in the class
bool contact::name_exists(string search_term)
{
	if (search_term == name)
	{
		// cout << name << "\t" << mob << endl;
		return 1;
	}
	else
		return 0;
}

void contact::print() {
	cout << name << "\t" << mob << endl;
}


