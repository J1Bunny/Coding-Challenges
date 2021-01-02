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
		int fromLeft = 0;
		int fromTop = 0;
		int length = 0;
		int width = 0;

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


		//cout << "list " << fromLeft << " " << fromTop << " " << length << " " << width << endl;

		for (int i = fromTop; i < width + fromTop; i++) {
			for (int j = fromLeft; j < length + fromLeft; j++) {
				grid[i][j]++;
			}
		}

	}

	/*
	cout << endl;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	*/



	for (int i = 0; i < 9999; i++) {
		for (int j = 0; j < 9999; j++) {
			if (grid[i][j] > 1) {
				total++;
			}
		}
	}


	cout << total << endl;

	//Part 01:  116489
	//Part 02:

	exit(-1);
}


