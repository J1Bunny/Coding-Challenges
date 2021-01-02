#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string masterList[9999];
	string holdString = "";
	string newString = "";
	int max = 0;
	char theChar;
	char secondChar;
	int differences = 0;
	int newDifferences = 0;

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";
	fileString = "/Users/sarahwilkinson/Desktop/testdata.txt";
//fileString="/Users/sarahbier/Desktop/realdata.txt";

//opens the file
	inputFile.open(fileString);

	max = 0;

	while (!inputFile.eof()) {
		inputFile.get(theChar);
		//cout << "1 " << theChar << endl;

		inputFile.get(secondChar);
		//cout << "2 " << secondChar << endl;

		if ((int) theChar - 32 != (int) secondChar
				&& (int) theChar + 32 != (int) secondChar) {
			holdString.append(1, theChar);
			holdString.append(1, secondChar);
		}

		//cout << holdString << endl;
		theChar = ' ';
		secondChar = ' ';
	}

	newString = holdString;
	newDifferences = -1;
	differences = 0;
	while (differences != newDifferences) {
		holdString = newString;
		differences = newDifferences;
		newString = "";
		for (int i = 0; i < holdString.length(); i++) {
			theChar = holdString[i];
			secondChar = holdString[i + 1];

			if ((int) theChar - 32 == (int) secondChar
					|| (int) theChar + 32 == (int) secondChar) {
				i++;
				newDifferences++;
			} else {
				newString.append(1, theChar);
			}
		}
	}

	cout << holdString << endl;

	cout << holdString.length() << endl;

	//Part 01:  9202
	//Part 02:
	exit(-1);
}


