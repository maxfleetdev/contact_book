#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/*
> Add Contact
> Search Contact
> Delete Contact

	>> Struct for single contact (name & number) DONE
	>> Vector to store contacts DONE
	>> system("cls") for continuety ?? NO
*/

// Struct for single contact
struct Contact {
	std::string name = "";
	std::string number = "";
};

// All contacts
std::vector<Contact> ContactList{};

// Function Declerations
Contact GetContact();
Contact FindContact(Contact& contact);
bool DeleteNumber(Contact& contact);
bool AddContact(Contact& contact);
void ExitApp();


int main() {
	// Input Option (add, delete, search)
	while (1) {
		std::cout << "=================================================";
		std::cout << "\n\nInput one option: add, delete, find or exit: ";
		std::string option = {};
		std::cin >> option;

		// Flush input stream
		std::cin.ignore();			

		if (option.compare("add") == 0) {
			Contact contact = GetContact();
			AddContact(contact);
		}
		else if (option.compare("delete") == 0) {
			// Get Number
			std::cout << "Input number (e.g: 07123456789): ";
			std::string number = {};
			std::cin >> number;
			
			Contact contact = { "", number };
			DeleteNumber(contact);
		}
		else if (option.compare("find") == 0) {
			std::cout << "Input number (e.g: 07123456789): ";
			std::string number = {};
			std::cin >> number;

			Contact contact = { "", number };
			FindContact(contact);
		}
		else if (option.compare("exit") == 0) {
			ExitApp();
			break;
		}

		// Default Option
		else {
			std::cout << "Option " << option << " does not exist!\n";
		}
	}
}

Contact GetContact() {
	// Get Name
	std::cout << "Input name (e.g: John Doe): ";
	std::string name;
	std::getline(std::cin, name);

	// Get Number
	std::cout << "Input number (e.g: 07123456789): ";
	std::string number = {};
	std::cin >> number;

	// Return Contact
	return { name, number };
}



bool AddContact(Contact& contact) {
	// Check each contact
	if (ContactList.size() > 0) {
		for (int i = 0; i < ContactList.size(); i++) {
			if (ContactList[i].number == contact.number) {
				std::cout << "Contact with number " << contact.number << " already exists!\n";
				return false;
			}
		}
	}
	// Add Contact
	ContactList.push_back(contact);
	std::cout << "Added Contact: " << contact.name << ", " << contact.number << "\n";
	return true;
}

bool DeleteNumber(Contact& contact) {
	// Check contact exists
	if (ContactList.size() > 0) {
		for (int i = 0; i < ContactList.size(); i++) {
			if (ContactList[i].number == contact.number) {
				std::cout << "Deleted numeber: " << contact.number << "\n";
				ContactList.erase(ContactList.begin() + i);
				return true;
			}
		}
	}
	// Unable to delete
	std::cout << "Unable to delete number: " << contact.number << "\n";
	return false;
}

Contact FindContact(Contact& contact) {
	if (ContactList.size() > 0) {
		for (int i = 0; i < ContactList.size(); i++) {
			if (ContactList[i].number == contact.number) {
				std::cout << "Found contact: " << ContactList[i].name << ", " << ContactList[i].number << "\n";
				return ContactList[i];
			}
		}
	}
	std::cout << "Unable to find contact: " << contact.number << "\n";
	return {"", ""};
}

void ExitApp() {
	// save contacts to .txt file
	std::ofstream file;
	file.open("contacts.txt");
	for (int i = 0; i < ContactList.size(); i++) {
		file << ContactList[i].name << ", ";
		file << ContactList[i].number << "\n";
	}
	file.close();
}