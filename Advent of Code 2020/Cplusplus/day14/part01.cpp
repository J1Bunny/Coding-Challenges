#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */

using namespace std;

string convertToBinary(long inputDecimal);
long convertToDecimal(string inputBinary);
string fillZeros(string inputString, long stringLength);
void printLine(string inputArray[], long stringLength);

int main() {
	string fileString;
	ifstream inputFile;
	string file[999];
	long results[99999];
	string mask[99];
	string input[99];
	string original[99];

	long maxInput = 0;
	long idx = 0;

	long stringLength = 0;
	string tempInput = "";
	string tempString = "";
	string tempOriginal = "";
	string binary = "";
	//long input = 0;
	long theAddress = 0;
	long theValue = 0;
	long theOriginal = 0;
	string theMask = "";

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;
		file[maxInput] = fileString;
		maxInput++;
	}

	for (long i = 0; i < maxInput; i++) {
		//mask is good
		tempString = file[i];
		if (tempString.find("mask") != string::npos) {
			tempString = tempString.substr(7, tempString.length() - 7);
			stringLength = tempString.length();
			theMask = tempString;

			for (long j = 0; j < stringLength; j++) {
				mask[j] = tempString.substr(0, 1);
				tempString = tempString.substr(1, tempString.length() - 1);
			}
		} else if (tempString.find("mem") != string::npos) {
			//parse data from input
			tempString = tempString.substr(4, tempString.length() - 4);
			idx = tempString.find("]");
			theAddress = atoi(tempString.substr(0, idx).c_str());
			tempString = tempString.substr(idx + 1,
					tempString.length() - idx - 1);
			idx = tempString.find("=");
			theValue =
					atoi(
							tempString.substr(idx + 2,
									tempString.length() - idx - 1).c_str());

			cout << "mem[" << theAddress << "] = " << theValue << "." << endl;
			tempInput = convertToBinary(theValue);

			//load zeros to value
			tempInput = fillZeros(tempInput, theMask.length());

			//put value long array
			for (long j = 0; j < stringLength; j++) {
				input[j] = tempInput.substr(0, 1);
				tempInput = tempInput.substr(1, tempInput.length() - 1);
			}

			//get original value (to be changed)
			theOriginal = results[theAddress];
			tempOriginal = convertToBinary(theOriginal);
			tempOriginal = fillZeros(tempOriginal, stringLength);

			//load original long array
			for (long j = 0; j < stringLength; j++) {
				original[j] = tempOriginal.substr(0, 1);
				tempOriginal = tempOriginal.substr(1,
						tempOriginal.length() - 1);
			}

			printLine(original, stringLength);
			cout << " original " << endl;
			printLine(input, stringLength);
			cout << " input " << endl;
			printLine(mask, stringLength);
			cout << " mask " << endl;

			tempString = "";
			for (long j = 0; j < stringLength; j++) {
				if (mask[j].compare("0") == 0) {
					original[j] = "0";
				} else if (mask[j].compare("1") == 0) {
					original[j] = "1";
				} else {
					original[j] = input[j];
				}
				tempString = tempString + original[j];
			}

			printLine(original, stringLength);
			cout << " new " << endl;

			/*
			for (long j = 0; j < stringLength; j++) {
				if (mask[j].compare("X") == 0) {
					cout << "X";
				} else {
					cout << ".";
				}
			}
			cout << " check " << endl;
*/

			theOriginal = convertToDecimal(tempString);
			tempString = convertToBinary(theValue);
			results[theAddress] = theOriginal;

			cout << "mem[" << theAddress << "] = " << results[theAddress] << "."
					<< endl << endl;
		}

	}

	theOriginal = 0;
	for (int i = 0; i < 99999; i++) {
		if (results[i] > 0) {
			theOriginal = theOriginal + results[i];
		}
	}

	cout << "final " << theOriginal << endl;

}

string convertToBinary(long inputDecimal) {
	string newBinary = "";
	string temp = "";
	int tempNum = 0;

	for (int i = 0; inputDecimal > 0; i++) {
		tempNum = inputDecimal % 2;
		cout << tempNum;
		temp = std::to_string(tempNum);
		newBinary = temp+newBinary;
		inputDecimal = inputDecimal / 2;
	}

	return newBinary;
}

long convertToDecimal(string inputBinary) {
	return stol(inputBinary, nullptr, 2);
}

string fillZeros(string inputString, long stringLength) {
	while (inputString.length() < stringLength) {
		inputString = "0" + inputString;
	}
	return inputString;
}

void printLine(string inputArray[], long stringLength) {
	for (long j = 0; j < stringLength; j++) {
		cout << inputArray[j];
	}
}

//part 01:  13865835758282
//part 02:




