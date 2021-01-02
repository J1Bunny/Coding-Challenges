#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */
#include <math.h>
#include <map>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
	string brandNew[99];
	map<string, string> finalMap;

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

	long xCount = 0;
	long totalAddress = 0;
	string littleBin = "";
	string binArray[9999];
	string tempBin = "";
	long finalSum = 0;

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
			tempInput = convertToBinary(theAddress); //convertToBinary(theValue);

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

			//printLine(original, stringLength);
			//cout << " original " << endl;
			printLine(input, stringLength);
			cout << " input " << endl;
			printLine(mask, stringLength);
			cout << " mask " << endl;

			tempString = "";
			xCount = 0;
			for (long j = 0; j < stringLength; j++) {
				if (mask[j].compare("X") == 0) {
					original[j] = "X";
					xCount++;
				} else {
					if ((input[j].compare("1") == 0)
							|| (mask[j].compare("1") == 0)) {
						original[j] = "1";
					} else {
						original[j] = "0";
					}
				}

				tempString = tempString + original[j];
			}

			printLine(original, stringLength);
			cout << " new " << endl;
			totalAddress = pow(2, xCount);

			cout << "total addresses " << totalAddress << endl;
			cout << "value " << theValue << endl << endl;

			for (long j = 0; j < totalAddress; j++) { //start of total addresses
				tempString = "";
				littleBin = convertToBinary(j);
				littleBin = fillZeros(littleBin, xCount);
				//cout << littleBin << " littleBin " << endl;
				tempBin = littleBin;
				//cout << tempBin << " temp" << endl;

				/*
				 for (long j = 0; j < stringLength; j++) {
				 input[j] = tempInput.substr(0, 1);
				 tempInput = tempInput.substr(1, tempInput.length() - 1);
				 }
				 */

				for (long k = 0; k < littleBin.length(); k++) {
					binArray[k] = tempBin.substr(0, 1);
					tempBin = tempBin.substr(1, tempBin.length() - 1);
					//cout << binArray[k];
				}
				//cout << " bin array" << endl;

				int binStep = 0;
				for (int k = 0; k < stringLength; k++) {
					if (original[k].compare("X") == 0) {
						brandNew[k] = littleBin[binStep];
						binStep++;
					} else {
						brandNew[k] = original[k];
					}
					//cout << brandNew[k];
					tempString = tempString + brandNew[k];

				}
				cout << tempString << " brand new";
				cout << endl;
				theOriginal = convertToDecimal(tempString);

				cout << "mem[" << theOriginal << "] = " << theValue << "."
						<< endl << endl;

				map<string, string>::iterator itr;
				itr = finalMap.find(std::to_string(theOriginal));
				if (itr != finalMap.end()) {
					finalMap.erase(itr);
				}
				finalMap.insert(
						make_pair(std::to_string(theOriginal),
								std::to_string(theValue)));

				//tempString = convertToBinary(theValue);

				//results[theOriginal] = theValue;

			} //end of total addresses
			cout << endl;
		} //end of mem line
	} //end of input read

	//calculating the last bit

	/*
	theOriginal = 0;
	for (int i = 0; i < 99999; i++) {
		if (results[i] > 0) {
			theOriginal = theOriginal + results[i];
		}
	}
	*/


	theOriginal = 0;
	map<string, string>::iterator itr;
	for (itr = finalMap.begin(); itr != finalMap.end(); itr++) {
		theOriginal = theOriginal + atol((itr->second).c_str());
	}

	cout << "final " << theOriginal << endl;

}

string convertToBinary(long inputDecimal) {
	string newBinary = "";
	string temp = "";
	int tempNum = 0;

	for (int i = 0; inputDecimal > 0; i++) {
		tempNum = inputDecimal % 2;
		temp = std::to_string(tempNum);
		newBinary = temp + newBinary;
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
//part 02:  4195339838136


