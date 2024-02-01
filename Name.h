#pragma once
#include <string>

class Name {
	char gender; // random by default

	std::string firstName;
	std::string lastName;

	// temp arrays for storing names (deleted after generation)
	std::string* firstNames;
	std::string* lastNames;

	int getLineCount(std::string file);
	void setRandomName(char _gender);
	void setNames(std::string file);
public:
	std::string getName() const;
	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }

	void setName(std::string _firstName, std::string _lastName = "") { firstName = _firstName; lastName = _lastName; }
	void setFirstName(std::string _firstName) { firstName = _firstName; }
	void setLastName(std::string _lastName) { lastName = _lastName; }

	Name();
	Name(std::string _firstName, std::string _lastName = "") { setName(_firstName, _lastName); }
	Name(char _gender) { gender = _gender; setRandomName(gender); }
};