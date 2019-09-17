#pragma once
#include"Contant.h"
#include"function.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

const int a = 100;
contact person[a];

int choice;
#pragma once
bool name_valid(string tname)
{
	if (tname.size()>20)
	{
		cout << "Invalid Name!\nEnter a name within 20 characters!"
			<< endl;
		return 0;
	}
	else if (tname == "")
	{
		cout << "Invalid Name!\nName cannot be blank!" << endl;
		return 0;
	}
	else {
		return 1;
	}
}

//mobile number validation

bool mob_valid(string tmob)
{
	if (tmob.size()>13 || tmob.size()<10)
	{
		cout << "Invalid mobile no.\nEnter a no."
			"between 10 and 13 digits" << endl;
		return 0;
	}
	else if (tmob == "")
	{
		cout << "Invalid mobile no.\nMobile"
			"no cannot be blank" << endl;
		return 0;
	}
	else {
		return 1;
	}
}


void printline(char ch, int size)
{
	for (int o = 0; o<size; o++)
		cout << ch;
	cout << "\n";
}

void showmenu() {
	cout << "0. Show contacts" << endl
		<< "1. Add New Contact" << endl
		<< "2. Edit Contact" << endl
		<< "3. Delete Contact" << endl
		<< "4. Search in the contacts " << endl
		<< "5. Quit" << endl << endl
		<< "Your choice : ";

	cin >> choice;
}


void sort() {
	int i = 0;
	bool exit = true;
	while (exit) {

		exit = false;
		for (int i = 0;i<a - 1;i++) {

			if (person[i].getName()>person[i + 1].getName()) {
				swap(person[i], person[i + 1]);
				exit = true;
			}
		}
	}
}

int main() {

	string temp_name, temp_mob,line1,line2;
	int i, counter = 0, cancel_flag = 0;
	fstream my_fileName("names.txt");
	fstream my_filetelephone("telephone.txt");

	//this function creat name's page in linkedlist L1	
	if (my_fileName.is_open()&& my_filetelephone.is_open())
	{
		for(int i=0;getline(my_fileName, line1)&& getline(my_filetelephone, line2);i++)
		{
			person[i].add(line1,line2);
		}
		counter = 0;
		my_fileName.close();
	}

	do {
		showmenu();
		cerr << " ";
		switch (choice) {
		case 0:
			for (i = 0;person[i].show() == 1; i++) {
				cout << i + 1 << "-";
				person[i].print();
			}
			break;
		case 1:

			//The following code resides in the main function.
			cout << "Add New Contact\t\t\t\tpress $ to cancel" << endl;
			printline('-', 20);
			counter = 0;

			//Loop until correct name and mobile number are entered
			do
			{
				flag = 0;
				if (counter)
					cout << "Try again\t\t\t\tpress $ to cancel" << endl;

				//counts how many times the do-while loop executes
				counter++;

				cout << "Name: ";
				cin >> temp_name;

				//Cancel operation
				if (temp_name == "$")
				{
					cancel_flag = 1;
					break;
				}
				cout << "Mobile No.: ";
				cin >> temp_mob;

				//Cancel operation
				if (temp_mob == "$")
				{
					cancel_flag = 1;
					break;
				}

				//Check whether name exists
				for (i = 0; i < 100; i++)
					if (person[i].name_exists(temp_name))
					{
						cout << "The name you entered is already there"
							"in the phonebook, enter a different name."
							<< endl;
						flag = 1;
						break;
					}

			} while (!name_valid(temp_name) || flag ||
				!mob_valid(temp_mob));

			if (cancel_flag)
			{
				system("cls");
				break;
			}


			//This code adds the contact to phonebook    
			for (i = 0; i < 100; i++)
				if (person[i].add(temp_name, temp_mob))
				{
					cout << "Contact added successfully!" << endl;
					flag = 1;
					break;
				}

			if (!flag)
				cout << "Memory full! Delete some contacts first." << endl;

			break;
		case 2:
			cout << "Enter a contact name to edit:"
				"\t\t\t\tpress $ to cancel\n";
			cin >> temp_name;

			//Cancel Operation
			if (temp_name == "$")
			{
				system("cls");
				break;
			}

			for (i = 0; i < 100; i++)
				if (person[i].edit(temp_name))
				{
					cout << "Edited Successfully!" << endl;
					flag = 1;
					break;
				}

			if (!flag)
				cout << "Contact name not found!" << endl;

			break;
		case 3:
			// The following code resides in the main function.
			do {
				if (counter)
					cout << "Try again" << endl;
				counter++;
				cout << "Enter a contact name to delete:"
					"\t\t\tpress $ to cancel\n";
				cin >> temp_name;

				//Cancel Operation
				if (temp_name == "$")
				{
					system("cls");
					break;
				}

				//Final Confirmation
				for (i = 0; i < 100; i++)
					if (person[i].name_exists(temp_name))
					{
						flag = 1;
						cout << "Are you sure you want to delete? (1/0)"
							<< endl;
						int yes;
						cin >> yes;
						if (!yes)
						{
							system("cls");
							cancel_flag = 1;
						}
						break;
					}

				if (!flag)
					cout << "Contact name not found!" << endl;

				if (cancel_flag)
					break;

				// This code deletes the contact
				if (flag)
				{
					for (i = 0; i < 100; i++)
						if (person[i].erase(temp_name))
						{
							cout << "Deleted successfully!" << endl;
							break;
						}
				}

			} while (!flag);


			break;
		case 4:
			// The following code resides in the main function.
			do {
				if (counter)
					cout << "Try again" << endl;
				counter++;
				cout << "Search a name: \t\t\t\tpress $ to cancel\n";
				cin >> temp_name;

				//Cancel Operation
				if (temp_name == "$")
				{
					system("cls");
					break;
				}

				for (i = 0; i < 100; i++)
					if (person[i].name_exists(temp_name))
					{
						flag = 1;
						person[i].print();
						break;
					}

				if (!flag)
					cout << "Contact name not found" << endl;
			} while (!flag);

			break;
		case 5:
			break;
		default:
			cout << "Enter number from 0 to 5 " << endl;
			break;
		}

	sort();
}while (choice != 5);

//The following code resides in the class
return 0;
}