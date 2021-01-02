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
	int max = 0;
	int colon = 0;
	int space = 0;
	string tempString;
	string tempValue;
	int strLength = 0;
	int good = 0;

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
				byr[passNum] = tempValue;
			} else if (tempString.compare("iyr") == 0) {
				iyr[passNum] = tempValue;
			} else if (tempString.compare("eyr") == 0) {
				eyr[passNum] = tempValue;
			} else if (tempString.compare("hgt") == 0) {
				hgt[passNum] = tempValue;
			} else if (tempString.compare("hcl") == 0) {
				hcl[passNum] = tempValue;
			} else if (tempString.compare("ecl") == 0) {
				ecl[passNum] = tempValue;
			} else if (tempString.compare("pid") == 0) {
				pid[passNum] = tempValue;
			} else if (tempString.compare("cid") == 0) {
				cid[passNum] = tempValue;
			}

		}

	}

	for (int i = 0; i < passNum; i++) {
		if ( byr[i].compare("") != 0 && iyr[i].compare("") != 0
				&& eyr[i].compare("") != 0 && hgt[i].compare("") != 0
				&& hcl[i].compare("") != 0 && ecl[i].compare("") != 0
				&& pid[i].compare("") != 0) {

			good++;
		}
	}

	cout << endl << endl;

	cout << good << endl;
}

//Part 1:  182
//Part 2:

