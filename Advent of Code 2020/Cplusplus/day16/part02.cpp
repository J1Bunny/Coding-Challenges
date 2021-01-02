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
	int others[99][999];
	int taken[99];
	string descriptions[99];
	int allValid[999];
	int field = 0;       //field descriptions
	int value = 0;       //value of field
	int myTicket[99];    //field on ticket
	int maxFields = 0;  //counts number of descriptions (matches maxTicket)
	int maxValues = 0;
	int maxTicket = 0;  //counts fields on my ticket (matches maxFields)
	int idx = 0;
	string tempString = "";
	int minRange = 0;
	int maxRange = 0;
	int valueToFind = 0;
	int invalidSum = 0;
	bool stillValid = true;
	string theDescription = "";
	int theIndex = 0;
	int tooMany = 0;
	bool allDone = true;
	long total = 0;

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
				descriptions[maxFields] = fileString.substr(0, idx);
				maxFields++;
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

					if (maxValues < maxRange) {
						maxValues = maxRange;
					}
					//cout << "." << minRange << "." << endl;
					//cout << "." << maxRange << "." << endl;
					for (int i = minRange; i < maxRange + 1; i++) {
						allValid[i] = 1;
						valid[field][i] = 1;
						//cout << "i = " << i << " " << allValid[i] << endl;
					}
					range1 = range2;
				}
				field++;
				//maxValues = 999;
				value = 0;

				//cout << fileString << endl;
				getline(inputFile, fileString);
			}
		}
		//file[maxInput] = fileString;
		//maxInput++;

		//your ticket
		if (fileString.find("your ticket") != string::npos) {
			getline(inputFile, fileString);

			tempString = fileString;
			idx = tempString.find(",");
			while (idx != string::npos) {
				valueToFind = atoi(tempString.substr(0, idx).c_str());
				myTicket[maxTicket] = valueToFind;
				maxTicket++;
				tempString = tempString.substr(idx + 1,
						tempString.length() - 1);
				idx = tempString.find(",");
			}

			valueToFind = atoi(tempString.substr(0, idx).c_str());
			myTicket[maxTicket] = valueToFind;
			maxTicket++;
		}

		//nearby tickets
		if (fileString.find("nearby tickets") != string::npos) {
			field = 0;
			while (fileString.length() > 0 && !inputFile.eof()) {
				stillValid = true;
				getline(inputFile, fileString);
				tempString = fileString;
				idx = tempString.find(",");
				while (idx != string::npos) {
					valueToFind = atoi(tempString.substr(0, idx).c_str());
					if (allValid[valueToFind] == 0) {
						invalidSum = invalidSum + valueToFind;
						stillValid = false;
					} else {
						//cout << "value to find " << valueToFind << endl;
						others[field][valueToFind] = 1;
						field++;
					}
					tempString = tempString.substr(idx + 1,
							tempString.length() - 1);
					idx = tempString.find(",");
				}
				valueToFind = atoi(tempString.substr(0, idx).c_str());
				if (allValid[valueToFind] == 0) {
					invalidSum = invalidSum + valueToFind;
					stillValid = false;
				} else {
					others[field][valueToFind] = 1;
					field++;
				}
				if (stillValid) {
					cout << fileString << endl;
				}
				field = 0;
			}
		}
	}

	//take first element of each "others" array
	//go down each line to see if that value is in each array

	cout << "maxFields " << maxFields << endl;
	cout << "maxValues " << maxValues << endl;

	cout << endl;

	total = 1;
	allDone = false;
	while (!allDone) {
		for (int k = 0; k < maxFields; k++) {
			tooMany = 0;
			for (int i = 0; i < maxFields; i++) {
				stillValid = true;
				theDescription = descriptions[k];
				for (int j = 0; j < maxValues; j++) {
					if (others[i][j] > 0) {
						valueToFind = j;

						if (valid[k][valueToFind] != 1) {
							stillValid = false;
						}
						if (taken[i] == 1) {
							stillValid = false;
						}
					}

					/*
					 cout << "[" << i << "]" << "[" << j << "] " << others[i][j]
					 << endl << endl;

					 cout << "[" << i << "]" << "[" << j << "] " << valid[i][j]
					 << endl;
					 */
				}

				if (stillValid) {
					//cout << theDescription << " = " << i << endl;
					theIndex = i;
					tooMany++;
					//cout << tooMany << endl;
				}
			}
			if (tooMany == 1) {
				cout << "actual " << theDescription << " " << myTicket[theIndex]
						<< endl;
				taken[theIndex] = 1;

				if (theDescription.find("departure") != string::npos) {
					total = total * myTicket[theIndex];
				}

				allDone = true;
				for (int m = 0; m < maxFields; m++) {
					if (taken[m] == 0) {
						allDone = false;
					}
				}
			}
		}

	}	//extra

	cout << "error rate: " << invalidSum << endl;
	cout << "total " << total << endl;
}

//part01:  25916
//part02:  2564529489989



//434014277 too low
//2564529489989
