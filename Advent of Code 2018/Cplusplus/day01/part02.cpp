#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int max = 0;
	int i = 0;
	int freq = 0;
	int distance = 0;
	string step;
	string add = "+";
	bool matchFound = false;
	int positive[999999];
	int negative[999999];
	int entireList[9999];
	//int times = 0;

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";

	for (int i = 0; i < 999999; i++) {
		positive[i] = 0;
		negative[i] = 0;
	}

	for (int i = 0; i < 9999; i++) {
		entireList[i] = 0;
	}

	positive[0] = -1;
	negative[0] = -1;

	//opens the file
	inputFile.open(fileString);

	max = 0;

	while (!inputFile.eof()) {
		inputFile >> fileString;
		//cout << fileString << endl;
		distance = stoi(fileString);
		entireList[max] = distance;
		max++;
	}

	//for (int i = 0; i < max; i++) {
		//cout << entireList[i] << endl;
	//}

	cout << "" << endl;

	while (matchFound == false) {
		for (int i = 0; i < max; i++) {
			freq = freq + entireList[i];

			if (freq >= 0) {
				if (freq == positive[freq]) {
					cout << "found: " << freq << endl;
					matchFound = true;
				} else {
					positive[freq] = freq;
				}
			} else {
				if (freq == negative[freq * -1]) {
					cout << "found: " << freq << endl;
					matchFound = true;
				} else {
					negative[freq * -1] = freq;
				}
			}
		}
	}

		//it doesn't work because there are negative values
		cout << "freq:  " << freq << endl;

		//system("pause");
		exit(-1);

		//Part 01:  525
		//Part 01:  75749

}


