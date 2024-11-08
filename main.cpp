#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"

std::vector<Contact> allContacts;
bool exitApp = false;

// Function Declarations
void GetChoice();
void AddContact();
void EditContact();
void FindContact();
void ShowContacts();
void ShowFavourites();
void ExitApp();
void ShowHelp();
void NullCatch();
void ClearScreen();

// Main Loop
int main() {
	while (!exitApp) {
		GetChoice();
	}
	ExitApp();
}

void GetChoice() {
	std::cout << "================================================\n";
	std::cout << "Input an option: \n(1) add \n(2) edit \n(3) find \n(4) favourites \n(5) exit \n(6) help \n\n";
	int choice = {};
	std::cin >> choice;
	std::cin.ignore();

	// Choice Option
	switch (choice) {
	case 1:
		AddContact();
		break;
	case 2:
		EditContact();
		break;
	case 3:
		FindContact();
		break;
	case 4:
		ShowFavourites();
		break;
	case 5:
		ExitApp();
		break;
	case 6:
		ShowHelp();
		break;

	default:
		NullCatch();
		break;
	}
}

void AddContact() {
	std::cout << std::flush;
	std::cout << '\n' << "Insert Name: ";
	std::string name = {};
	std::getline(std::cin, name);

	std::cout << '\n' << "Insert Number: ";
	int number = {};
	std::cin >> number;

	ClearScreen();
	std::cout << "Added Contact " << name << '\n';
	Contact contact = Contact{ name, number };
	allContacts.push_back(contact);
}

void EditContact() {
	// name
	// number
	// favourite
}

void FindContact() {
	// name
	// number
}

void RemoveContact() {
	// use name/number
}

void ShowFavourites() {
	// show list
}

void ShowContacts() {
	// display all contacts
}

void ExitApp() {
	// save file using ofstream
	std::cout << "Exiting :3";
}

void ShowHelp() {

}

void NullCatch() {
	ClearScreen();
	std::cout << "No Option Found. Please enter a valid option. \n\n";
}

void ClearScreen() {
	system("cls");
}