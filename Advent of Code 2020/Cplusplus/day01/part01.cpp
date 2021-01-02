#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int i = 0;
	int j = 0;
	int tempInt = 0;
	int solution;
	int arrayList[9999];
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
		tempInt = arrayList[i];
		for (j = i + 1; j < max; j++) {
			if (arrayList[j] + tempInt == 2020) {
				solution = arrayList[j] * tempInt;
			}
		}
	}


	cout << solution << endl;

	//Part 1:  870331
}
