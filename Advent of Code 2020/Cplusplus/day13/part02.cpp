#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	long timestamp = 0;
	string fullLine = "";
	string allRecords[999];
	long actual[999];
	long nextTime[999];
	long count[999];
	long maxRecords = 0;
	long max = 0;
	long idx = 0;
	long busNum = 0;
	long startIndex = 0;
	long stopIndex = 0;
	bool found = false;
	long start = 0;
	long stop = 0;
	long bigStep = 0;
	long firstNum = 0;
	long secondNum = 0;
	long absMax = 1;
	long mult = 0;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	/*
	 17,x,13,19 is 3417.
	 67,7,59,61 first occurs at timestamp 754018.
	 67,x,7,59,61 first occurs at timestamp 779210.
	 67,7,x,59,61 first occurs at timestamp 1261476.
	 1789,37,47,1889 first occurs at timestamp 1202161486
	 7,13,x,x,59,x,31,19 at 1068781
	 */

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		timestamp = atoi(fileString.c_str());
		getline(inputFile, fileString);
		fullLine = fileString;
	}

	//fullLine = "67,7,59,61";

	cout << timestamp << endl;
	cout << fullLine << endl;
	idx = 1;

	while (idx > 0) {
		idx = fullLine.find(",");
		//cout << fullLine.substr(0,idx) <<endl;
		allRecords[maxRecords] = fullLine.substr(0, idx);
		if (allRecords[maxRecords].compare("x") != 0) {
			actual[max] = atol(allRecords[maxRecords].c_str());
			nextTime[max] = 0;
			count[max] = max;
			absMax = absMax * actual[max];
			max++;
		} else {
			count[max] = -1;
			max++;
		}
		fullLine = fullLine.substr(idx + 1, fullLine.length() - idx);
		maxRecords++;
	}

	//get the two biggest numbers
	//find when they match up
	//multiply all the numbers for the bigstep

	bigStep = 1;
	for (int i = 0; i < max; i++) {
		if (actual[i] > -1) {
			//if (actual[i] > 0) {
			//	bigStep = bigStep * actual[i];
			//}

			if (start == 0) {
				start = actual[i];
				startIndex = i;
			}
			if (start != actual[i] && stop == 0) {
				stop = actual[i];
				stopIndex = i;
			}
		}
	}

	cout << start << " " << stop << endl;
	bigStep = start * stop;

	for (int i = 0; i < start * stop; i++) {
		if (i % actual[startIndex] == 0
				&& (i + (stopIndex - startIndex)) % actual[stopIndex] == 0) {
			if (firstNum == 0) {
				firstNum = i;
			}
		}
	}

	//for (long i = firstNum; i < 854018; i = i + bigStep) {

	mult = 1;
	cout << "max " << max << endl;
	for (int k = 0; k <= max; k++) {
		if (count[k] > -1) {
			cout << endl;
			cout << "k " << k << endl;
			cout << "first " << firstNum << endl;
			cout << "bigstep " << bigStep << endl;
			for (long i = firstNum; i < absMax; i = i + bigStep) {
				found = true;
				mult = 1;

				for (long j = 0; j < k; j++) {
					if (count[j] > -1) {
						//cout << i + count[j] << endl;
						//cout << i << " " << count[j] << " " << actual[j] << endl;
						if ((i + count[j]) % (actual[count[j]]) != 0) {
							found = false;
						} else {
							mult = mult * actual[count[j]];
						}
					}
				}
				if (found) {
					cout << "mult " << mult << endl;
					cout << "found " << i << endl;
					firstNum = i;
					i = absMax;
					//if (mult > bigStep) {
						bigStep = mult;
						//firstNum = i;
					//}

					/*
					 //maybe
					 bigStep = 1;
					 for (int q = 0; q < k; q++) {
					 if (actual[q] > 0) {
					 cout << "q"+actual[q] << endl;
					 bigStep = bigStep * actual[q];
					 bigStep = bigStep + i;
					 cout << i << endl;
					 i = absMax;
					 }
					 }
					 //maybe
					 *
					 */
				}
			}
		}
	}
}

//part 01:  138
//part 02:  226845233210288


