#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int i = 0;
	int j = 0;
	int k = 0;
	int tempInt = 0;
	int anotherInt = 0;
	int solution;
	int arrayList[9999];
	int theList[5];
	int max;

	//fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString="/Users/sarahbier/Desktop/realdata.txt";

	//opens the file
	inputFile.open(fileString);
	max = 0;
	solution = 0;

	while (!inputFile.eof()) {
		inputFile >> fileString;
		//cout << fileString << endl;
		arrayList[max] = atoi(fileString.c_str());
		//cout << arrayList[max] << endl;
		max++;
	}

	for (i = 0; i < max; i++) {
		for (j = i + 1; j < max; j++) {
			for (k = j + 1; k < max; k++) {
				if (arrayList[k] + arrayList[j] + arrayList[i] == 2020) {
					solution = arrayList[k] * arrayList[j] * arrayList[i];
				}
			}
		}
	}

	cout << solution << endl;

	//Part 1:  870331
	//Part 2:  283025088
}

