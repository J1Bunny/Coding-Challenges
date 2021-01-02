#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>      /* prlongf */
#include <stdlib.h>     /* strtol */
#include <math.h>
#include <map>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int valid[99][999];  //[fields][values]
	int allValid[999];
	int field = 0;       //field descriptions
	int value = 0;       //value of field
	int myTicket[99];    //field on ticket
	int maxFields = 0;
	int maxValues = 0;
	int maxTicket = 0;
	int idx = 0;
	string tempString = "";
	int minRange = 0;
	int maxRange = 0;
	int valueToFind = 0;
	int invalidSum = 0;

	string range1 = "";
	string range2 = "";

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;

		//field section - done for pt 1
		if (fileString.find("or") != string::npos) {
			while (fileString.length() > 0) {
				idx = fileString.find(":");
				fileString = fileString.substr(idx + 2,
						fileString.length() - idx - 1);

				idx = fileString.find("or");
				range1 = fileString.substr(0, idx - 1);
				range2 = fileString.substr(idx + 3,
						fileString.length() - idx - 2);
				//cout << "." << range1 << "." << endl;
				//cout << "." << range2 << "." << endl;

				for (int step = 0; step < 2; step++) {
					idx = range1.find("-");
					minRange = atoi(range1.substr(0, idx).c_str());
					maxRange =
							atoi(
									range1.substr(idx + 1,
											range1.length() - idx - 1).c_str());
					//cout << "." << minRange << "." << endl;
					//cout << "." << maxRange << "." << endl;
					for (int i = minRange; i < maxRange + 1; i++) {
						allValid[i] = 1;
						//cout << "i = " << i << " " << allValid[i] << endl;
					}
					range1 = range2;
				}

				//cout << fileString << endl;
				getline(inputFile, fileString);
			}
		}
		//file[maxInput] = fileString;
		//maxInput++;

		//your ticket
		if (fileString.find("your ticket") != string::npos) {
			getline(inputFile, fileString);
			cout << fileString << endl;
		}

		//nearby tickets
		if (fileString.find("nearby tickets") != string::npos) {
			while (fileString.length() > 0 && !inputFile.eof()) {
				getline(inputFile, fileString);
				cout << fileString << endl;

				idx = fileString.find(",");
				while (idx != string::npos) {
					valueToFind = atoi(fileString.substr(0, idx).c_str());
					if (allValid[valueToFind] == 0) {
						invalidSum = invalidSum + valueToFind;
					}
					fileString = fileString.substr(idx + 1,
							fileString.length() - 1);
					idx = fileString.find(",");
				}
				valueToFind = atoi(fileString.substr(0, idx).c_str());
				if (allValid[valueToFind] == 0) {
					invalidSum = invalidSum + valueToFind;
				}
			}
		}
	}

	cout << "error rate: " << invalidSum << endl;
}

//part01:  25916
//part02:

