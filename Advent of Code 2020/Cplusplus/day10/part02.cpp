#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	long adapter[9999];
	long paths[9999];
	long max = 0;
	long highnum = 0;
	long currentCharge = 0;
	long countOne = 0;
	long countThree = 0;
	long tempNum = 0;
	long pathCount = 0;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;

		adapter[max] = atol(fileString.c_str());
		if (adapter[max]>highnum){
			highnum = adapter[max];
		}
		max++;
	}


	adapter[max] = highnum+3;
	max++;
	adapter[max] = 0;
	max++;

	for (long i = 0; i < max - 1; i++) {
		for (long j = 0; j < max - i - 1; j++) {
			if (adapter[j] < adapter[j + 1]) {
				tempNum = adapter[j];
				adapter[j] = adapter[j + 1];
				adapter[j + 1] = tempNum;
			}
		}
	}


	//for (int i = 0; i < max; i++) {
	//	cout << adapter[i] << endl;
	//}
	//cout << "max " << max << endl;

	paths[0] = 1;
	//paths[1] = 1;
	for (long i = 0; i < max; i++) {

		if (adapter[i] - adapter[i + 1] <= 3) {
			paths[i+1] = paths[i+1]+paths[i];
		}

		cout << adapter[i] << " " << currentCharge << " " << paths[i] << endl;

		if (adapter[i] - adapter[i + 2] <= 3) {
			paths[i+2] = paths[i+2]+paths[i];
		}

		cout << adapter[i + 1] << " " << currentCharge << endl;

		if (adapter[i] - adapter[i + 3] <= 3) {
			paths[i+3] = paths[i+3]+paths[i];
		}

		cout << endl;
		cout << adapter[i + 2] << " " << currentCharge << endl;
		cout << "stop " << i << endl;
		cout << "paths " << paths[i] << endl;
		cout << endl << endl;

		currentCharge = adapter[i];

		cout << currentCharge << " - ";
		cout << adapter[i] << endl;;
	}

	for(long i = 0; i < max; i++){
		cout << "i = " << i << " " << "a" << adapter[i] << " " << paths[i] << endl;
		pathCount = paths[i];
	}

	cout << endl << "final total " << pathCount;

}

//part 01:  1920
//part 02:  1511207993344
