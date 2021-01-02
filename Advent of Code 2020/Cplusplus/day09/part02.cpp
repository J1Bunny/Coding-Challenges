#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	long numbers[9999];
	long max = 0;
	long preamble = 0;
	long original = 0;
	long sum = 0;
	long small = 0;
	long big = 0;
	long firstNum = 0;
	long secondNum = 0;
	bool matchFound = false;
	int badNumber = 0;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	preamble = 25;
	if (fileString.find("test") != string::npos) {
		preamble = 5;
	}

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;

		numbers[max] = atol(fileString.c_str());
		max++;
	}

	//for (long i = 0; i < max; i++) {
	//	cout << numbers[i] << endl;
	//}

	original = preamble;
	for (int k = 0; k < 9999; k++) {
		matchFound = false;
		for (int i = preamble - original; i < preamble; i++) {
			for (int j = i + 1; j < max - 1; j++) {
				//cout << i << "-" << numbers[i] << " " << j << "-" << numbers[j] << endl;
				//cout << numbers[i] + numbers[j] << " " << numbers[preamble] << endl << endl;
				if (numbers[i] + numbers[j] == numbers[preamble]) {
					matchFound = true;
					//cout << i << "-" << numbers[i] << " " << j << "-"
					//<< numbers[j] << endl;
					//cout << numbers[i] + numbers[j] << " " << numbers[preamble]
					//<< endl << endl;
				}
			}
		}
		if (!matchFound) {
			cout << "no match " << numbers[preamble] << endl;
			badNumber = numbers[preamble];
			k = 9999;
		} else {
			preamble++;
		}
	}

	for (int k = 0; k < 9999; k++) {
		cout << "k = " << k << endl;
		for (int i = 0; i < max; i++) {
			sum = numbers[i];
			for (int j = i + 1; j < max; j++) {
				sum = sum + numbers[j];
				cout << sum << endl;
				if (sum == badNumber) {
					cout << "found it " << endl;
					firstNum = i;
					secondNum = j;
					cout << firstNum << " " << secondNum << endl;
					small = numbers[firstNum];
					big = numbers[firstNum];

					for (int l = firstNum; l <= secondNum; l++) {
						if (numbers[l] <= small) {
							small = numbers[l];
						}
						if (numbers[l] >= big) {
							big = numbers[l];
						}
					}

					cout << endl;
					cout << "check " << small << " " << big << endl;

					j = 9999;
					i = 9999;
					k = 9999;
				}
			}
		}
	}

	cout << "final " << big + small << endl;
}

//part 01:  552655238
//part 02:  70672245
