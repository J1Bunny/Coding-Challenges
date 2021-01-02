#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int highRange = 0;
	int lowRange = 0;
	int actualHigh = 0;
	int actualLow = 0;
	int lowRow = 0;
	int highRow = 0;
	int highRL = 0;
	int lowRL = 0;
	int finalNum = 0;
	int highSeat = 0;

	int seatCount = 0;
	int rowCount = 0;
	int seatID = 0;
	int rowID = 0;

	highRange = 127;
	highRL = 7;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);

		actualHigh = highRange;
		actualLow = lowRange;

		highRow = highRL;
		lowRow = lowRL;

		seatCount = 128;
		rowCount = 8;
		finalNum = 0;

		cout << fileString << endl;

		for (int i = 0; i < fileString.length(); i++) {

			if (fileString[i] == 'F') {
				seatCount = seatCount / 2;
				actualHigh = seatCount + actualLow - 1;
				seatID = actualHigh;
				//cout << "seats " << seatCount << "  ";
				//cout << fileString[i] << " rows " << actualLow << " through "
				//<< actualHigh << endl;

			} else if (fileString[i] == 'B') {
				seatCount = seatCount / 2;
				actualLow = actualHigh - seatCount + 1;
				seatID = actualLow;
				//cout << "seats " << seatCount << "  ";
				//cout << fileString[i] << " rows " << actualLow << " through "
				//<< actualHigh << endl;

			} else if (fileString[i] == 'R') {
				rowCount = rowCount / 2;
				lowRow = highRow - rowCount + 1;
				rowID = lowRow;
				//cout << "seats " << rowCount << "  ";
				//cout << fileString[i] << " rows " << lowRow << " through "
				//<< highRow << endl;

			} else if (fileString[i] == 'L') {
				rowCount = rowCount / 2;
				highRow = rowCount + lowRow - 1;
				rowID = highRow;
				//cout << "seats " << rowCount << "  ";
				//cout << fileString[i] << " rows " << lowRow << " through "
				//<< highRow << endl;
			}

		}


		finalNum = seatID * 8 + rowID;
		cout << "row " << seatID << " column " << rowID << " ";
		cout << finalNum << endl;
		if (finalNum > highSeat) {
			highSeat = finalNum;
		}

	}

	cout << endl << endl << highSeat << endl;

//Part 1:  864
//Part 2:

	//871 too high, answer for another person
}
