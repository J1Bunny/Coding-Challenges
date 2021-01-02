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
	long start = 0;
	long stop = 0;
	long firstNum = 0;
	long secondNum = 0;
	bool matchFound = false;

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
					cout << i << "-" << numbers[i] << " " << j << "-"
							<< numbers[j] << endl;
					cout << numbers[i] + numbers[j] << " " << numbers[preamble]
							<< endl << endl;
				}
			}
		}
		if (!matchFound) {
			cout << "no match " << numbers[preamble] << endl;
			k = 9999;
		} else {
			preamble++;
		}
	}
}

//part 01:  552655238
//part 02:
