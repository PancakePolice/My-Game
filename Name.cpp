#include "name.h"
#include <time.h>
#include <fstream>

Name::Name() {
	srand(time(0));
	int randomNumber = (rand() % 2) + 1;

	if (randomNumber == 1)
		gender = 'm';
	else
		gender = 'f';

	setRandomName(gender);
}

std::string Name::getName() const {
	if (lastName == "")
		return firstName;
	else
		return firstName + " " + lastName;
		
}

int Name::getLineCount(std::string file) {
	std::ifstream inFile;
	std::string junk;
	int count = 0;

	inFile.open(file);
	while (!inFile.eof()) {
		getline(inFile, junk);
		count++;
	}
	inFile.close();

	return count;
}

void Name::setNames(std::string file) {
	std::ifstream inFile;

	srand(time(0));

	// Set first names array
	firstNames = new std::string[getLineCount(file)];
	inFile.open(file);
	for (int i = 0; !inFile.eof(); i++) {
		getline(inFile, firstNames[i]);
	}
	inFile.close();

	// Set last names array
	lastNames = new std::string[getLineCount("LastNames.txt")];
	inFile.open("LastNames.txt");
	for (int i = 0; !inFile.eof(); i++) {
		getline(inFile, lastNames[i]);
	}
	inFile.close();

}

void Name::setRandomName(char _gender) {
	std::string file;
	int randomIndex = 0;

	switch (_gender) {
	case 'm':
	case 'M':
		file = "MaleNames.txt";
		setNames(file);
		break;
	case 'f':
	case 'F':
		file = "FemaleNames.txt";
		setNames(file);
		break;
	default:
		file = "NeuterNames.txt";
		setNames(file);
		break;
	}

	// Set random first name
	randomIndex = rand() % getLineCount(file);
	firstName = firstNames[randomIndex];

	// Set random last name
	file = "LastNames.txt";
	randomIndex = rand() % getLineCount(file);
	lastName = lastNames[randomIndex];

	delete[] firstNames;
	delete[] lastNames;
}