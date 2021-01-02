#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	static int grid[9999][9999];
	int fromLeft = 0;
	int fromTop = 0;
	int length = 0;
	int width = 0;
	string entireList[9999];
	int max = 0;
	string tempString = "";
	int first = 0;
	int second = 0;
	int strLength = 0;
	int total = 0;
	bool allGood = false;

	int fromLeftArray[9999];
	int fromTopArray[9999];
	int lengthArray[9999];
	int widthArray[9999];
	int IDArray[9999];

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";
	fileString = "/Users/sarahwilkinson/Desktop/testdata.txt";
//fileString="/Users/sarahbier/Desktop/realdata.txt";

	for (int i = 0; i < 9999; i++) {
		for (int j = 0; j < 9999; j++) {
			grid[i][j] = 0;
		}
	}

	//opens the file
	inputFile.open(fileString);

	max = 0;

	while (!inputFile.eof()) {
		//inputFile >> fileString;
		ifstream fileString;
		getline(inputFile, tempString);
		entireList[max] = tempString;
		//cout << entireList[max] << endl;
		max++;
	}

	for (int i = 0; i < max; i++) {
		fromLeft = 0;
		fromTop = 0;
		length = 0;
		width = 0;

		tempString = entireList[i];
		strLength = tempString.length();

		first = tempString.find("@");
		second = tempString.find(",");

		fromLeft = stoi(tempString.substr(first + 1, second - first - 1));

		first = tempString.find(",");
		second = tempString.find(":");
		fromTop = stoi(tempString.substr(first + 1, second - first - 1));

		first = tempString.find(":");
		second = tempString.find("x");
		length = stoi(tempString.substr(first + 1, second - first - 1));

		first = tempString.find("x");
		width = stoi(tempString.substr(first + 1, strLength - first - 1));

		fromLeftArray[i] = fromLeft;
		fromTopArray[i] = fromTop;
		lengthArray[i] = length;
		widthArray[i] = width;
		IDArray[i] = i + 1;

		//cout << "list " << fromLeft << " " << fromTop << " " << length << " " << width << endl;

		for (int i = fromTop; i < width + fromTop; i++) {
			for (int j = fromLeft; j < length + fromLeft; j++) {
				grid[i][j]++;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//cout << grid[i][j];
		}
		//cout << endl;
	}

	for (int k = 0; k < 9999; k++) {
		//cout << "ID1 " << IDArray[k] << endl;
		allGood = true;
		for (int i = fromTopArray[k]; i < widthArray[k] + fromTopArray[k]; i++) {
			for (int j = fromLeftArray[k]; j < lengthArray[k] + fromLeftArray[k]; j++) {
				if (grid[i][j] > 1) {
					allGood = false;
				}
			}
		}
		if (allGood && IDArray[k] > 0) {
			cout << "ID2 " << IDArray[k] << endl;
		}
	}




	//Part 01:  116489
	//Part 02:  1260
	exit(-1);
}

