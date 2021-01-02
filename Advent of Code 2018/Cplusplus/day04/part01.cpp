#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string masterList[9999];
	string firstString = "";
	string secondString = "";
	string thirdString = "";
	string fourthString = "";
	string fifthString = "";
	string sixthString = "";
	string holdString = "";
	int guards[9999];
	int guardDay[9999];
	int minute[99][99];  //[guard][day][minute]
	int dayTime[9999];
	int max = 0;
	int first = 0;
	int second = 0;
	int theGuard = 0;
	int startTime = 0;
	int endTime = 0;
	int maxTime = 0;
	int holdTime = 0;
	int sleepyGuard = 0;
	int day = 0;
	int j = 0;

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/testdata.txt";
//fileString="/Users/sarahbier/Desktop/realdata.txt";

//opens the file
	inputFile.open(fileString);
	max = 0;

	for (int i = 0; i < 9999; i++) {
		masterList[i] = "";
		guards[i] = 0;
		guardDay[i] = 0;
		dayTime[i] = 0;
	}

	for (int i = 0; i < 99; i++) {
		for (int j = 0; j < 99; j++) {
			minute[i][j] = 0;
		}
	}

	while (!inputFile.eof()) {
//inputFile >> fileString;
		ifstream fileString;
		getline(inputFile, holdString);
		masterList[max] = holdString;
		//cout << masterList[max] << endl;
		max++;
	}

	for (int i = 0; i < max - 1; i++) {
		for (int j = 0; j < max - 1 - i; j++) {
			firstString = masterList[j].substr(6, 2);
			secondString = masterList[j + 1].substr(6, 2);
			if (stoi(firstString) > stoi(secondString)) {
				holdString = masterList[j + 1];
				masterList[j + 1] = masterList[j];
				masterList[j] = holdString;
			}
		}
	}

	for (int i = 0; i < max - 1; i++) {
		for (int j = 0; j < max - 1 - i; j++) {
			firstString = masterList[j].substr(6, 2);
			secondString = masterList[j + 1].substr(6, 2);
			thirdString = masterList[j].substr(9, 2);
			fourthString = masterList[j + 1].substr(9, 2);
			if (stoi(thirdString) > stoi(fourthString)
					&& firstString >= secondString) {
				holdString = masterList[j + 1];
				masterList[j + 1] = masterList[j];
				masterList[j] = holdString;
			}
		}
	}

	for (int i = 0; i < max - 1; i++) {
		for (int j = 0; j < max - 1 - i; j++) {
			firstString = masterList[j].substr(6, 2);
			secondString = masterList[j + 1].substr(6, 2);
			thirdString = masterList[j].substr(9, 2);
			fourthString = masterList[j + 1].substr(9, 2);
			fifthString = masterList[j].substr(12, 2)
					+ masterList[j].substr(15, 2);
			sixthString = masterList[j + 1].substr(12, 2)
					+ masterList[j + 1].substr(15, 2);
			if (stoi(fifthString) > stoi(sixthString)
					&& (firstString >= secondString)
					&& (thirdString >= fourthString)) {
				holdString = masterList[j + 1];
				masterList[j + 1] = masterList[j];
				masterList[j] = holdString;
			}
		}
	}

	/*
	 *
	 * Sort is complete at this point
	 for (int i = 0; i < max; i++) {
	 cout << masterList[i] << endl;
	 }

	 */

	theGuard = -1;
	day = -1;

	//[guard][day][minute]
	for (int i = 0; i < max; i++) {
		first = 0;
		first = masterList[i].find("#");
		second = masterList[i].find("begins");
		if ((first > 0)
				&& (stoi(masterList[i].substr(first + 1, second - first - 1))
						!= theGuard)) {
			theGuard = stoi(
					masterList[i].substr(first + 1, second - first - 1));
		} else {

			first = masterList[i].find("falls");
			if (first > 0) {
				for (j = i; j < max; j++) {

					//cout << "i= " << i << " j= " << j << endl;
					day ++;
					dayTime[day] = (stoi(masterList[j].substr(6, 2)) * 100)
							+ (stoi(masterList[j].substr(9, 2)));
					guardDay[day] = theGuard;
					startTime = (stoi(masterList[j].substr(12, 2)) * 60)
							+ stoi(masterList[j].substr(15, 2));
					endTime = (stoi(masterList[j + 1].substr(12, 2)) * 60)
							+ stoi(masterList[j + 1].substr(15, 2));
					guards[theGuard] = guards[theGuard] + (endTime - startTime);
					//cout << theGuard << " " << masterList[j] << " " << startTime
					//<< " " << endTime << " " << endl;

					for (int k = startTime; k < endTime; k++) {
						minute[day][k] = 1;
					}

					j++;
					if (masterList[j].find("#") > 0) {
						i = j;
						j = max;
					}
				}
			}
		}
	}

	cout << "000000000011111111112222222222333333333344444444445555555555"
			<< endl;
	cout << "012345678901234567890123456789012345678901234567890123456789"
			<< endl;

	for (int j = 0; j < max; j++) { //guard
		for (int i = 0; i < 60; i++) { //minute per day
			if (dayTime[j] > 0) {
				cout << minute[j][i];
			}
		}
		if (dayTime[j] > 0) {
			cout << endl;
		}
	}

	for (int i = 0; i < 9999; i++) {
		if (guards[i] > maxTime) {
			maxTime = guards[i];
			sleepyGuard = i;
		}
	}


	maxTime = 0;
	holdTime = 0;
	startTime = 0; //hold minute value
	for (int i = 0; i < 60; i++) {
		for (int j = 1; j < day +1; j++) {
			//cout << "step " << i << " " << j << " ";
			if (guardDay[j] == sleepyGuard){
				//cout << guardDay[j] << endl;
				holdTime = holdTime + minute[j][i];
			}
		}
		if (holdTime > maxTime){
			maxTime = holdTime;
			startTime = i;
		}
		holdTime = 0;
	}

	cout << sleepyGuard << endl;
	cout << startTime << endl;
	cout << sleepyGuard * startTime << endl;


//Part 01:  74743
//Part 02:
	exit(-1);
}
