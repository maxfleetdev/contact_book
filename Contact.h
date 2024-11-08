#pragma once

class Contact {
private:
	std::string name = {};
	int number = {};
	bool favourite = false;

public:
	Contact(std::string name, int number) {
		this->name = name;
		this->number = number;
	}

	// Getters
	std::string GetName() {
		return name;
	}

	int GetNumber() {
		return number;
	}

	bool IsFavourite() {
		return favourite;
	}


	// Setters
	void SetName(std::string name) {
		this->name = name;
	}

	void SetNumber(int number) {
		this->number = number;
	}

	void SetFavourite(bool favourite) {
		this->favourite = favourite;
	}
};