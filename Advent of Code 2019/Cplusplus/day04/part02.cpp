#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string tempString = "";
	int strLength = 0;
	int idx = 0;
	int first;
	int second;
	string firstString = "";
	string secondString = "";
	bool good = true;
	bool match = false;
	bool tooMany = false;
	int allGood = 0;
	int count[10];
	int theNumber = 0;

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";
	fileString = "/Users/sarahwilkinson/Desktop/testdata.txt";
//fileString="/Users/sarahbier/Desktop/realdata.txt";

//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()) {
		inputFile >> fileString;
	}

	//cout << fileString << endl;

	strLength = fileString.length();
	idx = fileString.find("-");
	firstString = fileString.substr(0, idx);
	secondString = fileString.substr(idx + 1, strLength - idx);
	first = stoi(firstString);
	second = stoi(secondString);

	cout << first << " " << second << endl;

	for (int i = 0; i < 10; i++) {
		count[i] = 0;
	}

	for (int i = first; i < second + 1; i++) {
	//for (int i = 123444; i < 123444 + 1; i++) {
		good = true;
		match = false;
		tooMany = false;

		//cout << i << endl;
		firstString = to_string(i);
		strLength = firstString.length();

		for (int j = 0; j < strLength - 1; j++) {

			//check if the numbers are in the right order
			if (stoi(firstString.substr(j, 1))
					> (stoi(firstString.substr(j + 1, 1)))) {
				good = false;
			}

			if (good == true) {
				theNumber = stoi(firstString.substr(j, 1));

				if (stoi(firstString.substr(j, 1))
						== (stoi(firstString.substr(j + 1, 1)))) {
					if (count[theNumber] == 0) {
						count[theNumber] = 2;
					} else {
						count[theNumber] = count[theNumber] + 1;

					}
				}

			}
		}

		if (good == true) {
			cout << i << endl;
			for (int k = 0; k < 10; k++) {

				cout << k << " " << count[k] << endl;
				if (count[k] == 2) {
					match = true;
				}
			}

			if (match == true) {

				//cout << i << " " << "good" << endl;
				allGood++;

			}
		}

		cout << i << " " << allGood << endl;
		for (int k = 0; k < 10; k++) {
			count[k] = 0;
		}
	}

	cout << "final " << allGood << endl;

	//905 too low

	//Part 01:  1919
	//Part 02:  1291
	exit(-1);
}
