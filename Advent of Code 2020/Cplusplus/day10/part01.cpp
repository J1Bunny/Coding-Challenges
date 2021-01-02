#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int adapter[9999];
	int max = 0;
	int currentCharge = 0;
	int countOne = 0;
	int countThree = 0;
	int tempNum = 0;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;

		adapter[max] = atol(fileString.c_str());
		max++;
	}

	for (int i = 0; i < max - 1; i++) {

		for (int j = 0; j < max - i - 1; j++) {
			if (adapter[j] > adapter[j + 1]) {
				tempNum = adapter[j];
				adapter[j] = adapter[j + 1];
				adapter[j + 1] = tempNum;
			}
		}
	}

	for (int i = 0; i < max; i++) {

		cout << currentCharge<< " - " ;
		cout << adapter[i];

		if(adapter[i] - currentCharge == 1){
			countOne++;
		}
		else if (adapter[i] - currentCharge == 3){
			countThree++;
		}

		currentCharge = adapter[i];
		cout << " - " << currentCharge << endl;
	}

	countThree++;

	cout << "one jolt " << countOne << endl;
	cout << "three jolt " << countThree << endl;

	cout << "final " << countOne * countThree << endl;

}

//part 01:  1920
//part 02:  
