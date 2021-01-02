#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string tempString = "";
	int strLength = 0;
	int idx = 0;
	int step = 0;
	int first = 0;
	int second = 0;
	int final = 0;

	int number = 0;
	int count[9999];
	int location[9999];

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";
	fileString = "/Users/sarahwilkinson/Desktop/testdata.txt";
//fileString="/Users/sarahbier/Desktop/realdata.txt";

//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()) {
		inputFile >> fileString;
	}

	cout << fileString << endl;

	strLength = fileString.length();
	idx = fileString.find(",");
	tempString = fileString.substr(0, idx);
	count[step] = stoi(tempString);

	//cout << count[step] << endl;

	step++;

	while (idx > 0) {
		strLength = fileString.length();
		fileString = fileString.substr(idx + 1, strLength - idx);
		idx = fileString.find(",");
		tempString = fileString.substr(0, idx);
		count[step] = stoi(tempString);
		//cout << count[step] << endl;
		step++;
	}

	count[1] = 12;
	count[2] = 2;

	for (int i = 0; i < step; i++) {
		//cout << count[i] << endl;

		first = i +1;
		second = i +2;
		final = i +3;

		if (count[i] == 1){
			first = count[i +1];
			second = count[i +2];
			final = count[i +3];

			count[final] = count[first] + count[second];
			i = i +3;
		}
		else if (count[i] == 2){
			first = count[i +1];
			second = count[i +2];
			final = count[i +3];

			count[final] = count[first] * count[second];
			i = i +3;
		}
		else if(count[i] == 99){
			i = step;
		}
	}

	for (int i = 0; i < step; i++){
			cout << count[i] << " ";
	}

	cout << endl;


	cout << "final " << count[0] << endl;


	//Part 01:  4570637
	//Part 02:
	exit(-1);
}


