#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int max = 0;
	int acc = 0;
	string entireList[9999];
	int run[9999];
	string command = "";
	string tempValue = "";
	int value = 0;
	string tempString = "";
	int space = 0;
	string operate = "";

	/*
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
	 */

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;

		entireList[max] = fileString;
		//cout << entireList[max] << endl;
		max++;
	}

	for (int i = 0; i < 9999; i++) {
		run[i] = -1;
	}

	for (int i = 0; i < max; i++) {
		tempString = entireList[i];
		space = tempString.find(" ");
		command = tempString.substr(0, space);
		operate = tempString.substr(space + 1, 1);
		tempValue = tempString.substr(space + 2,
				tempString.length() - space - 1);
		value = atoi(tempValue.c_str());
		//cout << "." << value <<  "." << operate << "." << endl;

		run[i]++;
		if (run[i] > 0) {
			i = 9999;
			cout << command << " " << operate << value << endl;
			cout << "acc " << acc << endl;
		}

		if (command.compare("nop") == 0) {
			i = i;
		} else if (command.compare("acc") == 0) {
			if (operate.compare("-") == 0) {
				acc = acc - value;
			} else {
				acc = acc + value;
			}
		} else if (command.compare("jmp") == 0) {
			if (operate.compare("-") == 0) {
				i = i - 1 - value;
			} else {
				i = i - 1 + value;
			}
		}
	}
}

//part 01:  1420
//part 02:
