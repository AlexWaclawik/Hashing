## Alex Waclawik
## CSCI 36200
## November 16th, 2020
## Term Project


## Algorithm

###### Goals
	* Given a word, determine if it is present in the given dictionary
	* If true, then suggest words starting with the same two letters as the input
	* Using "TimeInterval.h", record the total execution time for program after input is taken

###### Inputs
	* Dictionary File "Dictionary.txt"
	* Users input to be checked with dictionary

###### Outputs
	* Whether the users word is located in "Dictionary.txt"
	* If true, then suggest words from "Dictionary.txt" that start with the same two letters

###### Variables
	* map(int, string) "hashTable"
	* map(string, string) "alphaTable"

###### Libraries
	* <iostream>
	* <fstream>
	* <cmath>
	* <map>


## Procedure

###### Hash Functionality
	* Will use two dictionaries for program:
		1) Hash Dictionary
			* Polynomial Rolling Hash
			* Hash = (c[0] * A^0 + c[1] * A^1 + c[2] * A^2 + ...) % M
				* c = string being hashed
				* A = constant (prime number that is greater than number of characters, in this case 31)
				* M = large prime number (in this case, 5003)
			* While not the most efficent, this method has a fairly low collision rate and is very mathematically simple
			* Dictionary format is (key element)
		2) Alphabetical Dictionary
			* Will be used for finding similiar words
			* Words are sorted alphabetically via format (key element)
			* The key is just the first two letters of the word
			* Collisions are just tacked onto the first element of that key and seperated by "~"
				* example: "be be~because~been~before"
	* At the start of the program two maps are created, one for the Hash Dictionary and one for the Alpha Dictionary
	* These are made from the "Dictionary.txt" and "alphaDictionary.txt" files respectively
	* These files were manipulated beforehand by the program "sort.cpp"
	* That is how I generated the proper formatting with the key prefix


## Example Output

	Please enter a word: 'hi'
	Word exists in dictionary: True
	
	hic
	him
	hip
	his
	hit
	
	Execution time: 500 micro-sec
