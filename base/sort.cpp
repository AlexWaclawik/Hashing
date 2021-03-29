#include <iostream>
#include <fstream>
#include <cmath>

int main() {
	
	std::ifstream inFile;
	std::string currentLine;

	// polynomial hash sorting
	inFile.open("ogDictionary.txt");
	while (getline(inFile, currentLine)) {
		int hashVal = 0;
		int A = 1;
		int M = 5003;
		for (int i = 0; i < currentLine.size(); i++) {
			hashVal = (hashVal + ((int)currentLine[i] * A)) % M;
			A = (A * 31) % M;
		}
		std::cout << hashVal << " " << currentLine << std::endl;
	}
	inFile.close();

	/* sort for alphaDictionary.txt
	inFile.open("alphaDictionary.txt");
	while (getline(inFile, currentLine)) {
		std::string key = currentLine.substr(0,2);
		std::cout << key << " " << currentLine << std::endl;
	}
	inFile.close();*/
	
	return 0;
}
