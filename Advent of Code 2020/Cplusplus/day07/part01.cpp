#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main() {
	string fileString;
	ifstream inputFile;
	multimap<string, string> goldMap;
	multimap<string, string> childMap;
	multimap<string, string> finalMap;

	int oldSize = 0;
	int newSize = 0;
	int i = 0;

	int count = 0;
	string parentBag = "";
	string parentRule = "";
	int maxBags = 0;
	int step = 0;
	int idx = 0;
	bool addBag = false;

	string usedAnswers = "";
	string rules[999];
	string colorList[999];
	int finalCount = 0;
	bool isThere = false;

	string childBag = "";
	string fancyBag = "shiny gold";

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;
		if (fileString.find("contain no other bags") == string::npos) {
			rules[step] = fileString;
			//cout << rules[step] << endl;
			idx = rules[step].find("bags");
			colorList[step] = (rules[step].substr(0, idx));
			maxBags = maxBags + 1;
			step++;
		}
	}
	//cout << endl;
	inputFile.close();

	for (int i = 0; i < maxBags; i++) {
		addBag = false;

		//get the parent bag name
		int idx = rules[i].find("contain");
		string tempChar = rules[i].substr(0, idx);
		idx = idx + 8;
		string parentRule = rules[i].substr(idx, rules[i].length() - idx);
		idx = tempChar.find("bag");
		int maxRules = 0;

		parentBag = tempChar.substr(0, idx - 1);

		for (int k = 0; k < 999; k++) {
			idx = parentRule.find(" ");
			if (idx != string::npos) {
				tempChar = parentRule.substr(idx + 1,
						parentRule.length() - idx);
				idx = tempChar.find("bag");
				tempChar = tempChar.substr(0, idx - 1);
				childMap.insert(make_pair(parentBag, tempChar));

				idx = parentRule.find(",");
				if (idx != string::npos) {
					parentRule = parentRule.substr(idx + 2,
							parentRule.length() - idx);
					maxRules++;
				} else {
					k = 999;
					maxRules++;
				}
			}
		}
	}

	//loading map is done
	map<string, string>::iterator itr;
	for (itr = childMap.begin(); itr != childMap.end(); itr++) {
		if (itr->second.compare("shiny gold") == 0) {
			goldMap.insert(make_pair(itr->first, itr->second));
			childMap.erase(itr);
		}
	}

	cout << "first " << endl;
	for (itr = childMap.begin(); itr != childMap.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
	}

	cout << endl;
	for (itr = goldMap.begin(); itr != goldMap.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
	}

	for (int i = 0; i < 3; i++) {
		oldSize = childMap.size();
		for (itr = childMap.begin(); itr != childMap.end(); itr++) {

			if (goldMap.find(itr->second) != goldMap.end()) {
				goldMap.insert(make_pair(itr->first, itr->second));
				childMap.erase(itr);
			}
		}
		newSize = childMap.size();
		if (oldSize != newSize) {
			i--;
		}

		cout << oldSize << " " << newSize << endl;
	}

	cout << endl;

	for (itr = goldMap.begin(); itr != goldMap.end(); itr++) {
		if (finalMap.find(itr->first) == finalMap.end()) {
			finalMap.insert(make_pair(itr->first, ""));
		}
	}

	cout << endl;
	cout << "total " << finalMap.size();

}


//Part 1:  332
//Part 2:



