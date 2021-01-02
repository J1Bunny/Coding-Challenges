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
	multimap<string, string> masterMap;  //does not change
	multimap<string, string> numberMap;  //does not change
	multimap<string, string> finalMap;
	int goldCount = 0;

	string goldParent[99999];
	string goldChild[99999];
	string goldAmount[99999];

	string numberChar = "";

	int totalBags = 0;
	int parentBags = 0;

	//int numberMap[999];

	int newSize = 0;

	string amount = "";
	string parentBag = "";
	string parentRule = "";
	int maxBags = 0;
	int step = 0;
	int idx = 0;
	bool addBag = false;
	string one = "";
	string two = "";
	string three = "";

	int sizeCount = 0;

	string usedAnswers = "";
	string rules[999];
	string colorList[999];

	string childBag = "";
	string fancyBag = "shiny gold";

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;

		//if (fileString.find("contain no other bags") == string::npos) {
		rules[step] = fileString;
		//cout << rules[step] << endl;
		idx = rules[step].find("bags");
		colorList[step] = (rules[step].substr(0, idx));
		maxBags = maxBags + 1;
		step++;
		//}

	}
	//cout << endl;
	inputFile.close();

	/*
	 for (int i = 0; i < maxBags; i++) {
	 cout << colorList[i] << " " << rules[i] << endl;
	 }
	 */

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
				amount = parentRule.substr(0, idx);
				if (amount.compare("no") == 0) {
					amount = "0";
				}
				//cout << parentRule << " ";
				//cout << amount << endl;
				tempChar = parentRule.substr(idx + 1,
						parentRule.length() - idx);
				idx = tempChar.find("bag");
				tempChar = tempChar.substr(0, idx - 1);
				masterMap.insert(make_pair(parentBag, tempChar));
				numberMap.insert(make_pair(parentBag + "." + tempChar, amount));

				if (parentBag.compare("shiny gold") == 0) {
					for (int q = 0; q < atoi(amount.c_str()); q++) {
						goldMap.insert(make_pair(parentBag, tempChar));
						newSize++;
					}
				}

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

	sizeCount = sizeCount + goldMap.size();
	map<string, string>::iterator itr;
	map<string, string>::iterator findIt;

	cout << " newmap start" << endl;
	for (itr = goldMap.begin(); itr != goldMap.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
	}
	cout << goldMap.size() << endl;
	cout << " newmap end" << endl << endl;

	totalBags = 0;
	goldCount = 0;
	int original = 0;

	for (int j = 0; j < 99999; j++) {
		goldCount = 0;
		for (itr = goldMap.begin(); itr != goldMap.end(); itr++) {
			goldParent[goldCount] = itr->first;
			goldChild[goldCount] = itr->second;
			one = itr->first;
			two = itr->second;
			three = one + "." + two;

			if (numberMap.count(three) > 0) {
				goldAmount[goldCount] = numberMap.find(three)->second;
			}
			else{
				goldAmount[goldCount]="0";
			}

			goldCount++;
		}

		cout << "out " << endl;
		goldMap.clear();

		parentBags = 0;
		int totalChild = 0;

		for (int i = 0; i < goldCount; i++) {

			one = goldParent[i];
			two = goldChild[i];
			three = one + "." + two;
			amount = numberMap.find(three)->second;
			parentBags = atoi(amount.c_str());
			cout << one << " > " << two << " bags " << parentBags << endl; //how many bags for that color

			for (findIt = masterMap.begin(); findIt != masterMap.end();
					findIt++) {
				if (findIt->first.compare(goldChild[i]) == 0) {
					one = findIt->first;
					two = findIt->second;
					//goldMap.insert(make_pair(findIt->first, findIt->second));
					three = one + "." + two;
					//findIt = numberMap[three];
					amount = numberMap.find(three)->second;
					//cout << amount << endl;
					if (original == 0) {
						original = atoi(amount.c_str());
					}

					for (int q = 0; q < atoi(amount.c_str()); q++) {
						//if (amount.compare("0") != 0) {
						goldMap.insert(
								make_pair(findIt->first, findIt->second));
						newSize++;
						//}
					}
					totalChild = totalChild + atoi(amount.c_str());
				}
			}

			//if (totalChild == 0) {
			//	totalChild = 1;
			//}
			//cout << "child Bags " << totalChild << endl;
			parentBags = totalChild; //* parentBags;
			totalChild = 0;
			//cout << "total for " << goldChild[i] << " " << parentBags << endl;
			goldAmount[i] = to_string(parentBags);
			parentBags = 0;

			totalBags = totalBags + atoi(goldAmount[i].c_str());
			//cout << "total " << totalBags << endl;
		}

		cout << " newmap start" << endl;
		for (itr = goldMap.begin(); itr != goldMap.end(); itr++) {
			cout << itr->first << " " << itr->second << endl;
		}
		cout << goldMap.size() << "  ";
		sizeCount = sizeCount + goldMap.size();
		cout << sizeCount << endl;
		cout << " newmap end" << endl << endl;
		cout << j << " newSize " << newSize << endl;
	}

	cout << "total " << totalBags << endl;
//totalBags = totalBags + original;
	cout << "actual total " << totalBags << endl;
	cout << "size count " << sizeCount << endl;

}

//Part 1:  332
//Part 2:  10875

