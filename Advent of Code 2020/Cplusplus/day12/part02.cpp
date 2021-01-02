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
	int northSouthWay = 0;
	int eastWestWay = 0;
	int clicks = 0;
	string directions[] = { "E", "S", "W", "N" };
	int directIndex = 0;
	int holding = 0;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;
		command[max] = fileString.substr(0, 1);
		units[max] = atoi(
				fileString.substr(1, fileString.length() - 1).c_str());
		//cout << command[max] << " " << units[max] << endl;
		max++;
	}

	northSouthWay = 1;
	eastWestWay = 10;

	/*
	 *

	 Action N means to move the waypoint north by the given value.
	 Action S means to move the waypoint south by the given value.
	 Action E means to move the waypoint east by the given value.
	 Action W means to move the waypoint west by the given value.
	 Action L means to rotate the waypoint around the ship left (counter-clockwise) the given number of degrees.
	 Action R means to rotate the waypoint around the ship right (clockwise) the given number of degrees.
	 Action F means to move forward to the waypoint a number of times equal to the given value.

	 *
	 */

	facing = directions[0];
	for (int i = 0; i < max; i++) {
		cout << endl;
		cout << "start" << i << " " << command[i] << units[i] << endl;

		if (command[i].compare("N") == 0) {
			northSouthWay = northSouthWay + units[i];
		}
		if (command[i].compare("S") == 0) {
			northSouthWay = northSouthWay - units[i];
		}
		if (command[i].compare("E") == 0) {
			eastWestWay = eastWestWay + units[i];
		}
		if (command[i].compare("W") == 0) {
			eastWestWay = eastWestWay - units[i];
		}
		if (command[i].compare("L") == 0) {
			clicks = 0;
			if (units[i] > 0) {
				clicks = units[i] / 90;
			}

			if (clicks > 4) {
				while (clicks > 4) {
					clicks = clicks - 4;
				}
			}

			if (clicks == 1) {
				holding = eastWestWay;
				eastWestWay = northSouthWay * -1;
				northSouthWay = holding;

			} else if (clicks == 2) {
				northSouthWay = northSouthWay * -1;
				eastWestWay = eastWestWay * -1;

			} else if (clicks == 3) {
				holding = eastWestWay;
				eastWestWay = northSouthWay;
				northSouthWay = holding * -1;

			} else if (clicks == 4) {
				northSouthWay = northSouthWay * 1;
				eastWestWay = eastWestWay * 1;
			}

		}
		if (command[i].compare("R") == 0) {
			clicks = 0;
			if (units[i] > 0) {
				clicks = units[i] / 90;
			}

			if (clicks > 4) {
				while (clicks > 4) {
					clicks = clicks - 4;
				}
			}

			if (clicks == 1) {
				holding = eastWestWay;
				eastWestWay = northSouthWay;
				northSouthWay = holding * -1;

			} else if (clicks == 2) {
				northSouthWay = northSouthWay * -1;
				eastWestWay = eastWestWay * -1;

			} else if (clicks == 3) {
				holding = eastWestWay;
				eastWestWay = northSouthWay * -1;
				northSouthWay = holding;

			} else if (clicks == 4) {
				northSouthWay = northSouthWay * 1;
				eastWestWay = eastWestWay * 1;
			}
		}
		if (command[i].compare("F") == 0) {
			northSouth = northSouth + northSouthWay * units[i];
			eastWest = eastWest + eastWestWay * units[i];
		}

		cout << "facing " << directions[directIndex] << endl;

		cout << "Way NS " << northSouthWay << endl;
		cout << "Way EW " << eastWestWay << endl;
		cout << "NS " << northSouth << endl;
		cout << "EW " << eastWest << endl;
	}

	if (northSouth < 0) {
		northSouth = northSouth * -1;
	}
	if (eastWest < 0) {
		eastWest = eastWest * -1;
	}

	cout << "distance " << northSouth + eastWest << endl;
}

//part 01:  590
//part 02:  42013


//13139 too low

