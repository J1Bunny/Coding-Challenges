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
	int allGood = 0;

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

	for (int i = first; i < second + 1; i++) {
		good = true;
		match = false;

		//cout << i << endl;
		firstString = to_string(i);
		strLength = firstString.length();

		for (int j = 0; j < strLength - 1; j++) {
			if (stoi(firstString.substr(j, 1))
					== (stoi(firstString.substr(j + 1, 1)))) {
				match = true;
			}

			if (stoi(firstString.substr(j, 1))
					> (stoi(firstString.substr(j + 1, 1)))) {
				good = false;
			}
		}

		if (good == true && match == true){
			//cout << i << " " << "good" << endl;
			allGood ++;
		}
	}

	cout << "final " << allGood << endl;

	//Part 01:  1919
	//Part 02:
	exit(-1);
}
