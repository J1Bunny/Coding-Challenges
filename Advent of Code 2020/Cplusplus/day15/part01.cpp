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

int main() {
	string fileString = "";
	int age = 0;
	int turn = 0;
	int maxTurns = 2500;
	int history[2500];
	int idx = 0;
	string tempNum = "";
	int back = 0;
	int lastSpoken = 0;
	int firstIndex = 0;
	int lastIndex = 0;
	int example[] = { 0, 0, 3, 6, 0, 3, 3, 1, 0, 4, 0 };

	fileString = "0,3,6";
	fileString = "2,20,0,4,1,17";

	for (int i = 0; i < maxTurns; i++) {
		history[i] = -1;
	}

	for (int i = 1; i < maxTurns; i++) {
		idx = fileString.find(",");
		if (idx != string::npos) {
			tempNum = fileString.substr(0, idx);
			history[i] = atoi(tempNum.c_str());
			fileString = fileString.substr(idx + 1, fileString.length() - 1);
		} else {
			history[i] = atoi(fileString.c_str());
			i = maxTurns + 1;
		}
	}

	for (int i = 1; i < 2021; i++) {
		firstIndex = -1;
		age = 0;
		if (history[i] != -1) {
			cout << endl;
			cout << "**turn " << i << " say " << history[i];
			lastSpoken = history[i];
			lastIndex = i;
			if (history[i] != example[i]) {
				cout << " x " << endl;
			} else {
				cout << endl;
			}
		} else {
			//cout << "last number spoken " << lastNumberSpoken << endl;
			for (int k = i - 1; k > 0; k--) {

				if (history[k] == lastSpoken && k != lastIndex) {
					firstIndex = k;
					cout << "last spoken " << lastSpoken << ", turn " << lastIndex
							<< endl;
					//age = lastIndex - k;
					k = -1;
				}

				if (firstIndex > -1) {
					age = lastIndex - firstIndex;
					cout << "first spoken " << lastSpoken << ", turn " << firstIndex
							<< endl;
				}

			}
			history[i] = age;
			//cout << history[i] << endl;
			i--;
		}
	}
}

//part01:  758


