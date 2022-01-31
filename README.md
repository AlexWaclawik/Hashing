## Hash Dictionary

A program that takes user input and uses a hash table to determine if it exists in the given dictionary.
If the word exists, then it also suggests similiar words that start with the same two letters. Lastly,
a timer is used to measure the execution time after input is given.

<p align="right"></p>

### Installation

1. Clone the repository
2. Compile the program by typing **make**
3. Run the program by typing **make run**
4. Follow the instructions in the terminal

**Example Output:**
```
	Please enter a word: hi
	Word exists in dictionary: True
	
	hic
	him
	hip
	his
	hit

	Execution time: 500 micro-sec
```

<p align="right"></p>

### Design

The Hash Dictionary utilizes a **Polynomial Rolling Hash** to assign hash keys. While not the most efficent, it's advantages are a
fairly low collision rate and releative mathmatical simplicity.

- Hash Key = (c[0] * A^0 + c[1] * A^1 + c[2] * A^2 + ...) % M
	1. c = string being hashed
	2. A = constant (prime number that is greater than number of characters, in this case 31)
	3. M = large prime number (in this case, 5003)

For finding similiar words, a simple alphabetical dictionary is used. The words are sorted alphabetically, where the key is just
the first two letters of the word. Collosions are appended to the element they are colliding with, and are seperated by a tilde.

- Example: **be be~because~been~before**

At the start of the program, two maps are created for the hash and alphabetical dictionaries. The data for these maps comes from the
**Dictionary.txt** and **alphaDictionary.txt** files respectively. Both of these files were manipulated and organized beforehand with
the program **sort.cpp**.

<p align="right"></p>
