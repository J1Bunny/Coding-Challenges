#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string commands[30] = { };
	string entireList[9999];
	int letter[4];
	string tempString = "";
	int max = 0;
	string first = "";
	string second = "";
	int space = 0;
	int r = 0;
	bool useLetter = true;
	int value = 0;

	//fileString = "C:/advent/day12_input.txt";
	//fileString = "C:/advent/testdata.txt";
	fileString = "/Users/sarahwilkinson/Desktop/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()) {
		//inputFile >> fileString;
		ifstream fileString;
		getline(inputFile, tempString);
		entireList[max] = tempString;
		//cout << entireList[max] << endl;
		max++;
	}

	for (int i = 0; i < 4; i++) {
		letter[i] = 0;
	}

	for (int i = 0; i < max; i++) {

		useLetter = true;
		r = 0;
		value = 0;
		tempString = entireList[i].substr(4, entireList[i].length() - 4);
		//cout << "." << tempString << "." << endl;

		space = tempString.find(" ");
		first = tempString.substr(0, space);

		//cout << "." << first << "." << endl;

		if (first.compare("a") == 0) {
			r = 0;
		} else if (first.compare("b") == 0) {
			r = 1;
		} else if (first.compare("c") == 0) {
			r = 2;
		} else if (first.compare("d") == 0) {
			r = 3;
		} else {
			useLetter = false;
		}

		cout << entireList[i] << " ~ " << i << " ~ " << letter[0] << " " << letter[1] << " "
				<< letter[2] << " " << letter[3] << endl;

		if (entireList[i].substr(0, 3).compare("cpy") == 0) {
			//cout << entireList[i] << " copy" << endl;
			second = tempString.substr(space + 1);
			//cout << first << "." << second << "." << endl;
			if (useLetter) {
				value = letter[r];
			} else {
				value = stoi(first);
			}

			if (second.compare("a") == 0) {
				r = 0;
			} else if (second.compare("b") == 0) {
				r = 1;
			} else if (second.compare("c") == 0) {
				r = 2;
			} else if (second.compare("d") == 0) {
				r = 3;
			}

			letter[r] = value;
		}

		else if (entireList[i].substr(0, 3).compare("inc") == 0) {
			//cout << entireList[i] << " inc" << endl;
			//cout << first << "." << second << "." << endl;
			letter[r]++;
		}

		else if (entireList[i].substr(0, 3).compare("dec") == 0) {
			//cout << entireList[i] << " dec" << endl;
			//cout << first << "." << second << "." << endl;
			letter[r]--;
		}

		else if (entireList[i].substr(0, 3).compare("jnz") == 0) {
			//cout << entireList[i] << " jump" << endl;
			second = tempString.substr(space + 1);
			//cout << first << "." << second << "." << endl;

			if (useLetter) {
				value = letter[r];
			} else {
				value = stoi(first);
			}

			if (value != 0) {
				i = i + stoi(second) - 1;
			}

		}

		first = "";
		second = "";
	}

	cout << letter[0] << endl;
	
	//part01 - 318003
	

}
