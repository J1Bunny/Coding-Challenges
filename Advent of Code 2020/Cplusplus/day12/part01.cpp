#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string facing = "";
	string command[9999];
	int units[9999];
	int max = 0;
	int northSouth = 0;
	int eastWest = 0;
	int clicks = 0;
	string directions[] = { "E", "S", "W", "N" };
	int directIndex = 0;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		cout << fileString << endl;
		command[max] = fileString.substr(0, 1);
		units[max] = atoi(
				fileString.substr(1, fileString.length() - 1).c_str());
		//cout << command[max] << " " << units[max] << endl;
		max++;
	}

	/*
	 *
	 Action N means to move north by the given value.
	 Action S means to move south by the given value.
	 Action E means to move east by the given value.
	 Action W means to move west by the given value.
	 Action L means to turn left the given number of degrees.
	 Action R means to turn right the given number of degrees.
	 Action F means to move forward by the given value in the direction the ship is currently facing.
	 *
	 */

	facing = directions[0];
	for (int i = 0; i < max; i++) {
		cout << "start" << i << " " << command[i]<< units[i] << endl;

		if (command[i].compare("N") == 0) {
			northSouth = northSouth + units[i];
		}
		if (command[i].compare("S") == 0) {
			northSouth = northSouth - units[i];
		}
		if (command[i].compare("E") == 0) {
			eastWest = eastWest + units[i];
		}
		if (command[i].compare("W") == 0) {
			eastWest = eastWest - units[i];
		}
		if (command[i].compare("L") == 0) {
			clicks = 0;
			if (units[i] > 0) {
				clicks = units[i] / 90;
			}
			cout << "clicks " << clicks << endl;
			for (int k = 0; k < clicks; k++) {
				directIndex = directIndex - 1;
				cout << "index pre " << directIndex << endl;
				if (directIndex < 0) {
					directIndex = 3;
				}
				cout << "index post " << directIndex << endl;
				cout << "k " << k << endl;
				cout << "new direction1 " << directions[directIndex] << endl;

			}
			cout << "new direction " << directions[directIndex] << endl;
		}
		if (command[i].compare("R") == 0) {
			clicks = 0;
			if (units[i] > 0) {
				clicks = units[i] / 90;
			}
			for (int k = 0; k < clicks; k++) {
				directIndex = directIndex + 1;
				if (directIndex > 3) {
					directIndex = 0;
				}
			}
			cout << "new direction " << directions[directIndex] << endl;
		}
		if (command[i].compare("F") == 0) {
			if (directions[directIndex].compare("N") == 0) {
				northSouth = northSouth + units[i];
			}
			if (directions[directIndex].compare("S") == 0) {
				northSouth = northSouth - units[i];
			}
			if (directions[directIndex].compare("E") == 0) {
				eastWest = eastWest + units[i];
			}
			if (directions[directIndex].compare("W") == 0) {
				eastWest = eastWest - units[i];
			}
		}


		cout << "facing " << directions[directIndex] <<endl;
		cout << "NS " << northSouth << endl;
		cout << "EW " << eastWest <<endl;
	}

	if (northSouth<0){
		northSouth = northSouth * -1;
	}
	if (eastWest<0){
		eastWest = eastWest * -1;
	}

	cout << "distance " << northSouth + eastWest << endl;
}

//part 01:  590
//part 02:


