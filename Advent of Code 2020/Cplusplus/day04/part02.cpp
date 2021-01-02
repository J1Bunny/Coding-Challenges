#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int passNum = 0;
	string byr[999];
	string iyr[999];
	string eyr[999];
	string hgt[999];
	string hcl[999];
	string ecl[999];
	string pid[999];
	string cid[999];
	string colors[9];
	int max = 0;
	int colon = 0;
	int space = 0;
	string tempString;
	string tempValue;
	int strLength = 0;
	int good = 0;
	int colorStep = 0;
	bool colorFound = 0;
	bool goodHair = 0;
	int idx = 0;
	int minValue = 0;
	int maxValue = 0;
	string newHeight = "";
	string newHair = "";

	for (int i = 0; i < 999; i++) {
		byr[i] = "";
		iyr[i] = "";
		eyr[i] = "";
		hgt[i] = "";
		hcl[i] = "";
		ecl[i] = "";
		pid[i] = "";
		cid[i] = "";
	}

	colors[0] = "amb";
	colors[1] = "blu";
	colors[2] = "brn";
	colors[3] = "gry";
	colors[4] = "grn";
	colors[5] = "hzl";
	colors[6] = "oth";

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);

		cout << fileString << endl;

		strLength = fileString.length();
		if (strLength == 0) {
			passNum++;
		}

		while (strLength > 0) {
			tempString = "";
			tempValue = "";

			colon = fileString.find(":");
			tempString = fileString.substr(0, colon);
			fileString = fileString.substr(colon + 1, strLength - colon);
			strLength = fileString.length();

			space = fileString.find(" ");
			if (space > 0) {
				tempValue = fileString.substr(0, space);
				fileString = fileString.substr(space + 1, strLength - space);
				strLength = fileString.length();
				//cout << fileString << endl;
			} else {
				tempValue = fileString;
				strLength = 0;
			}
			//cout << "letn " << strLength << endl;

			if (tempString.compare("byr") == 0) {
				if (tempValue.length() == 4 && atoi(tempValue.c_str()) >= 1920
						&& atoi(tempValue.c_str()) <= 2002) {
					byr[passNum] = tempValue;
					cout << "byr = good ";

				}
				cout << tempValue << endl;
			}

			else if (tempString.compare("iyr") == 0) {
				if (tempValue.length() == 4 && atoi(tempValue.c_str()) >= 2010
						&& atoi(tempValue.c_str()) <= 2020) {
					iyr[passNum] = tempValue;
					cout << "iyr = good ";

				}
				cout << tempValue << endl;
			}
			//atoi(tempValue.c_str()>=1920)
			else if (tempString.compare("eyr") == 0) {

				if (tempValue.length() == 4 && atoi(tempValue.c_str()) >= 2020
						&& atoi(tempValue.c_str()) <= 2030) {
					eyr[passNum] = tempValue;
					cout << "eyr = good ";

				}
				cout << tempValue << endl;

				/*
				 hgt (Height) - a number followed by either cm or in:
				 If cm, the number must be at least 150 and at most 193.
				 If in, the number must be at least 59 and at most 76.
				 hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.

				 */

			} else if (tempString.compare("hgt") == 0) {
				cout << "in height" << endl;
				idx = 0;
				idx = tempValue.find("cm");
				minValue = 150;
				maxValue = 193;
				if (idx < 0) {
					idx = tempValue.find("in");
					minValue = 59;
					maxValue = 76;
				}

				if (idx > 0) {
					newHeight = tempValue.substr(0, idx);
					if (atoi(newHeight.c_str()) <= maxValue
							&& atoi(newHeight.c_str()) >= minValue) {
						hgt[passNum] = tempValue;
						cout << "hgt = good ";

					}
					cout << tempValue << endl;
				}

			} else if (tempString.compare("hcl") == 0) {
				if (tempValue.substr(0, 1).compare("#") == 0) {
					newHair = tempValue.substr(1, tempValue.length() - 1);
					goodHair = true;
					//followed by exactly six characters 0-9 or a-f.

					for (int j = 0; j < newHair.length(); j++) {
						if ((newHair[j] >= 'a' && newHair[j] <= 'f')
								|| (newHair[j] - '0' >= 0
										&& newHair[j] - '0' <= 9)
								|| (newHair[j] >= 'A' && newHair[j] <= 'Z')
										&& goodHair) {
							goodHair = true;
						} else {
							goodHair = false;
						}
					}

					if (goodHair && tempValue.length() == 7) {
						hcl[passNum] = tempValue;
						cout << "hcl = good ";
					}

				}
				cout << tempValue << endl;
			} else if (tempString.compare("ecl") == 0) {
				colorFound = false;
				for (colorStep = 0; colorStep < 7; colorStep++) {
					if (tempValue.compare(colors[colorStep]) == 0) {
						colorFound = true;
					}
				}
				if (colorFound) {
					ecl[passNum] = tempValue;
					cout << "ecl = good ";

				}
				cout << tempValue << endl;

			} else if (tempString.compare("pid") == 0) {
				if (tempValue.length() == 9) {
					pid[passNum] = tempValue;
					cout << "pid = good ";

					//pid  - a nine-digit number, including leading zeroes.
				}
				cout << tempValue << endl;
			} else if (tempString.compare("cid") == 0) {
				cid[passNum] = tempValue;
			}

		}

	}

//get the last one
	passNum++;

	for (int i = 0; i < passNum; i++) {
		if (byr[i].compare("") != 0 && iyr[i].compare("") != 0
				&& eyr[i].compare("") != 0 && hgt[i].compare("") != 0
				&& hcl[i].compare("") != 0 && ecl[i].compare("") != 0
				&& pid[i].compare("") != 0) {

			good++;
		}
		cout << "i " << i << " good " << good << endl;
	}

	cout << endl << endl;

	cout << good << endl;
}

//Part 1:  182
//Part 2:  109


