// Alex Waclawik
// November 16th 2020
// CSCI 36200
// Term Project


// c++ libraries
#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include "TimeInterval.h"


// global variables
std::map<int, std::string> hashTable;
std::map<std::string, std::string> alphaTable;


// function prototypes
void makeTable();
int findHash(std::string input);
bool checkHash(int hashValue);
void checkTable(std::string input);


int main() {

	// initialize hash table
	makeTable();

	// initialize timer class
	TimeInterval t;

	bool keepGoing = true;
	while (keepGoing) {
		std::string userInput;
		std::cout << "Please type a word: ";
		std::cin >> userInput;
		std::cout << std::endl;

		// start timer
		t.start();

		// find the hash value for input
		int hashVal = findHash(userInput);
		// check if the hash value exists
		bool doesExist = checkHash(hashVal);
		if (doesExist == true) {
			std::cout << "Word exists in dictionary: True" << std::endl;
			std::cout << std::endl;
			checkTable(userInput);
			std::cout << std::endl;
			// stop timer
			t.stop();
			// output exec time
			std::cout << "Execution Time: " << t.GetInterval() << " Micro-Seconds" << std::endl;
			
		}
		else if (doesExist == false) {
			std::cout << "Word exists in dictionary: False" << std::endl;
			// stop timer
			t.stop();
			// output exec time
			std::cout << "Execution Time: " << t.GetInterval() << " Micro-Seconds" << std::endl;
		}
		else { 
			std::cout << "An error occured" << std::endl;
			t.stop();
		}
		std::string contInput;
		std::cout << "Continue? (y/n): " << std::endl;
		std::cin >> contInput;
		if (contInput == "y") {
			continue;
		}
		else {
			keepGoing = false;
		}
		
	}
	return 0;
} // end main()


void makeTable() {
	// create hashTable map
	int key;
	std::string value;
	std::ifstream inFile;
	inFile.open("Dictionary.txt");
	while (inFile >> key >> value) {
		hashTable[key] = value;
	}
	inFile.close();
	// create alphaTable map
	std::string akey;
	std::string aValue;
	inFile.open("alphaDictionary.txt");
	while (inFile >> akey >> aValue) {
		alphaTable[akey] = aValue;
	}
	inFile.close();
} // end makeTable()


int findHash(std::string input) {
	int hashVal = 0;
	int A = 1;
	int M = 5003;
	for (int i = 0; i < input.size(); i++) {
		hashVal = (hashVal + ((int)input[i] * A)) % M;
		A = (A * 31) % M;
	}
	return hashVal;
} // end findHash()


bool checkHash(int hashValue) {
	if (hashTable.find(hashValue) == hashTable.end()) {
		return false;
	}
	else {
		return true;
	}
} // end checkHash()


void checkTable(std::string input) {
	std::string newLine = "~";
	std::string inputKey = input.substr(0,2);
	std::string sameWords = alphaTable[inputKey];
	for (int i = 0; i < sameWords.size(); i++) {
		if (sameWords[i] == newLine[0]) {
			std::cout << std::endl;
		}
		else {
			std::cout << sameWords[i];
		}
	}
	std::cout << std::endl;
} // end checkTable()
