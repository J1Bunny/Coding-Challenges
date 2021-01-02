#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int timestamp = 0;
	string fullLine = "";
	string allRecords[999];
	int actual[999];
	int nextTime[999];
	int maxRecords = 0;
	int max = 0;
	int idx = 0;
	int busNum = 0;


	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		timestamp = atoi(fileString.c_str());
		getline(inputFile, fileString);
		fullLine = fileString;
	}

	cout << timestamp << endl;
	cout << fullLine << endl;
	idx = 1;

	while(idx > 0){
		idx = fullLine.find(",");
		//cout << fullLine.substr(0,idx) <<endl;
		allRecords[maxRecords] = fullLine.substr(0,idx);
		if (allRecords[maxRecords].compare("x") != 0){
			actual[max] = atoi(allRecords[maxRecords].c_str());
			max++;
		}
		fullLine = fullLine.substr(idx+1,fullLine.length()-idx);
		maxRecords++;
	}

	for (int i = 0; i < max; i++){
		idx = 0;
		while (idx < timestamp){
			idx = idx + actual[i];
			if (nextTime[i] < idx){
				nextTime[i] = idx;
			}
		}
		cout << "time " << nextTime[i] << endl;
	}

	idx = timestamp * timestamp;
	for (int i = 0; i < max; i++){
		if (nextTime[i] < idx){
			idx = nextTime[i];
			busNum = actual[i];
		}
	}

	cout << "bus = " << busNum << endl;
	cout << "idx = " << idx << endl;
	cout << "time " << timestamp << endl;
	cout << "final " << busNum * (idx - timestamp) << endl;

}

//part 01:  138
//part 02:
