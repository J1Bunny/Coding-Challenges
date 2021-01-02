#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string usedAnswers = "";
	int step = 0;
	int count = 0;
	int finalCount = 0;
	string group[99];
	bool found = true;
	string currentString = "";
	string tempString = "";

	for (int i = 0; i < 99; i++) {
		group[i] = "";
	}

	/*
	 * if the letter is found in all lines, add one
	 */

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);

		if (fileString.length() > 0) {
			group[step] = fileString;
			step++;

		} else {

			if (step == 1) {
				cout << group[0] << endl;
				count = group[0].length();
				finalCount = finalCount + count;
				cout << "count " << count << endl << endl;
				cout << "final " << finalCount << endl;
				count = 0;
				usedAnswers = "";
				for (int i = 0; i < 99; i++) {
					group[i] = "";
				}
			} else {
				for (int i = 0; i < step; i++) {
					for (int j = i + 1; j < step; j++) {
						if (group[i].length() > group[j].length()) {
							tempString = group[i];
							group[i] = group[j];
							group[j] = tempString;
						}
					}
					cout << group[i] << endl;
				}

				//empty space, process existing lines
				cout << endl;
				usedAnswers = "";
				count = 0;

				//for (int i = 0; i < step - 1; i++) {
				currentString = group[0];
				found = false;

				//go through the first string
				for (int j = 0; j < currentString.length(); j++) {
					char ch = currentString[j];
					if (usedAnswers.find(ch) == std::string::npos) { //not found
						found = true;
						usedAnswers.push_back(ch);
					}

					if (found) {
						for (int k = 1; k < step; k++) {
							if (group[k].find(ch) == std::string::npos) {
								found = false;
							}
						}
					}

					if (found) {
						count++;
					}

					cout << ch << " " << count << endl;
				}
				//}

				//space to reset everything
				for (int i = 0; i < 99; i++) {
					group[step] = "";
				}
				finalCount = finalCount + count;
				cout << "count " << count << endl << endl;
				cout << "final " << finalCount << endl;
				step = 0;
				count = 0;
				usedAnswers = "";

			}

		}

	}

	//get info from last lines
	if (step == 1) {
		cout << group[0] << endl;
		count = group[0].length();
		finalCount = finalCount + count;
		cout << "count " << count << endl << endl;
		cout << "final " << finalCount << endl;
		count = 0;
		usedAnswers = "";
	} else {

		for (int i = 0; i < step; i++) {
			for (int j = i + 1; j < step; j++) {
				if (group[i].length() > group[j].length()) {
					tempString = group[i];
					group[i] = group[j];
					group[j] = tempString;
				}
			}
			cout << group[i] << endl;
		}

		//empty space, process existing lines
		cout << endl;
		usedAnswers = "";
		count = 0;

		//for (int i = 0; i < step - 1; i++) {
		currentString = group[0];
		found = false;

		//go through the first string
		for (int j = 0; j < currentString.length(); j++) {
			char ch = currentString[j];
			if (usedAnswers.find(ch) == std::string::npos) {  //not found
				found = true;
				usedAnswers.push_back(ch);
			}

			if (found) {
				for (int k = 1; k < step; k++) {
					if (group[k].find(ch) == std::string::npos) {
						found = false;
					}
				}
			}

			if (found) {
				count++;
			}

			cout << ch << " " << count << endl;
			//cout << "final " << finalCount << endl;
		}
		//}

		//space to reset everything
		for (int i = 0; i < 99; i++) {
			group[step] = "";
		}

		cout << "count " << count << endl << endl;
		finalCount = finalCount + count;
		step = 0;
		count = 0;
		usedAnswers = "";
	}

	cout << endl << "all done" << endl;
	cout << "final " << finalCount << endl;
}

//Part 1:  6703
//Part 2:  3430

//2331 too low
//8013 too high
//3482 wrong
//3570 answer for someone else
