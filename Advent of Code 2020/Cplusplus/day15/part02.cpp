#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>      /* prlongf */
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
	long age = 0;
	long maxTurns = 30000000;
	vector<long> history;
	vector<long> turns;
	map<long, long> lastSaid;

	//long history[30000100];
	long idx = 0;
	string tempNum = "";
	long lastSpoken = 0;
	long firstIndex = 0;
	long lastIndex = 0;
	long example[] = { 0, 0, 3, 6, 0, 3, 3, 1, 0, 4, 0 };
	bool stillGood = true;

	maxTurns = maxTurns +2;
	fileString = "0,3,6";
	fileString = "2,20,0,4,1,17";

	for (int i = 0; i < maxTurns+5; i++) {
		history.push_back(-1);
		turns.push_back(i);
	}

	for (long i = 1; i < maxTurns + 1; i++) {
		idx = fileString.find(",");
		if (idx != string::npos) {
			tempNum = fileString.substr(0, idx);
			history[i] = (atol(tempNum.c_str()));
			lastSaid.insert(make_pair(history[i], i));
			//cout << "pair added " << history[i] << " " << i << endl << endl;

			fileString = fileString.substr(idx + 1, fileString.length() - 1);
		} else {
			history[i] = (atol(fileString.c_str()));
			lastSaid.insert(make_pair(history[i], i));
			//cout << "pair added " << history[i] << " " << i << endl << endl;
			i = maxTurns + 1;
		}
	}

	//for (int i = 1; i < history.size(); ++i) {
	//	cout << history.at(i) << endl;
		//cout << " " << turns.at(i) << endl;
	//}


	lastSpoken = -1;
	for (long i = 1; i < maxTurns -1; i++) {
		firstIndex = -1;
		age = 0;
		if (history.at(i) != -1) {
			//cout << endl;
			//cout << "**turn " << i << " say " << history[i]  <<endl;
			lastSpoken = history.at(i);
			//cout << "last spoken " << lastSpoken << endl;
			lastIndex = i;

			//if (history.at(i) != example[i] && i <=10) {
			//	stillGood = false;
			//}

		} else {
			firstIndex = i - 1;
			//cout << "last number spoken " << lastSpoken << endl;
			map<long, long>::iterator itr;
			itr = lastSaid.find(lastSpoken);
			if (itr == lastSaid.end()) {
				age = 0;
			} else {
				//cout << "first var " << itr->first << endl;
				firstIndex = itr->second;
				//cout << "firstIndex = " << firstIndex << endl;
				//cout << "lastIndex = " << lastIndex << endl;
				age = lastIndex - firstIndex;
				lastSaid.erase(itr);
			}
			lastSaid.insert(make_pair(lastSpoken, i - 1));
			//cout << "pair added " << lastSpoken << " " << i << endl;

			history[i] = age;
			if(i % 100000 ==0){
				cout << i << endl;
			}
			//cout << "i=" << i << " history " << history[i] << endl<< endl;
			i--;
		}

	}


	cout << "final " << history.at(lastIndex) << endl;
	cout << "still good " << stillGood << endl;

}

//part01:  758
//part02:  814

//175594 too high


