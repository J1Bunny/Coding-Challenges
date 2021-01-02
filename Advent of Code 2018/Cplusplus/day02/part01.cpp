#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int max = 0;
	int i = 0;
	string step;
	int counts[30];
	string entireList[9999];
	int strLength = 0;
	string tempString = "";
	int twoCount = 0;
	int threeCount = 0;
	bool twoDone = false;
	bool threeDone = false;

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";
	fileString = "/Users/sarahwilkinson/Desktop/testdata.txt";
//fileString="/Users/sarahbier/Desktop/realdata.txt";

	for (int i = 0; i < 9999; i++) {
		entireList[i] = "";
	}

	//opens the file
	inputFile.open(fileString);

	max = 0;

	while (!inputFile.eof()) {
		inputFile >> fileString;
		entireList[max] = fileString;
		max++;
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 30; j++){
			counts[j] = 0;
		}

		//cout << entireList[i] << " ";
		tempString = entireList[i];
		strLength = tempString.length();
		for (int j = 0; j < strLength; j++){
			char letter = tempString[j];
			counts[(int)letter - 96]++;
		}

		for (int j = 0; j < 30; j++){
			if (counts[j] == 2 && twoDone == false){
				twoCount++;
				twoDone = true;
			}
			if (counts[j] == 3 && threeDone == false){
				threeCount++;
				threeDone = true;
			}
		}

		//cout << twoCount << " " << threeCount << endl;
		twoDone = false;
		threeDone = false;
	}

	cout << twoCount * threeCount << endl;



		//system("pause");
		exit(-1);

		//Part 01:  7808

}


