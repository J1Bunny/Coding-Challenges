#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string masterString = "";
	string holdString = "";
	string newString = "";
	int max = 0;
	char theChar;
	char secondChar;
	int differences = 0;
	int newDifferences = 0;
	int lower = 0;
	int upper = 0;
	int low = 999999;

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";
	fileString = "/Users/sarahwilkinson/Desktop/testdata.txt";
//fileString="/Users/sarahbier/Desktop/realdata.txt";

//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()) {
		inputFile.get(theChar);
		masterString.append(1, theChar);
	}

	//A = 65
	//a = 97
	//z = 122

	lower = 97;
	upper = 65;
	while (lower < 123) {
		holdString = masterString;
		for (int step = 0; step < holdString.length() - 1; step++) {
			theChar = holdString[step];

			//cout << theChar << " " << int(theChar) << endl;

			if (int(theChar) == lower) {
				//cout << "same " << endl;
				//theChar = ' ';
			}
			else if (int(theChar) == upper){
				//cout << "same " << endl;
			}
			else{
				newString.append(1, theChar);
			}
		}

		//cout << "first " << newString << endl;

		holdString = newString;
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

			if(low > holdString.length()){
				low = holdString.length();
			}

		}

		//cout << holdString << endl;
		cout << low << endl;
		lower ++;
		upper ++;
		newString = "";
		holdString = "";
	}
	//Part 01:  9202
	//Part 02:  6394
	exit(-1);
}


