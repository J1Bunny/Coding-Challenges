#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int max = 0;
	//int i = 0;
	string step;
	int counts[30];
	string entireList[9999];
	int strLength = 0;
	string firstString = "";
	string secondString = "";
	int lowCount = 999999;
	int count = 0;
	string final = "";

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";
	fileString = "/Users/sarahwilkinson/Desktop/testdata.txt";
//fileString="/Users/sarahbier/Desktop/realdata.txt";

	for (int i = 0; i < 9999; i++) {
		entireList[i] = "";
	}

	//opens the file
	inputFile.open(fileString);

	max = 0;

	while (!inputFile.eof()) {
		inputFile >> fileString;
		entireList[max] = fileString;
		max++;
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 30; j++){
			counts[j] = 0;
		}

		//cout << " " << endl;
		firstString = entireList[i];
		for (int k = 0; k < max; k++){
			strLength = firstString.length();
			secondString = entireList[k];

			//cout << firstString << " " << secondString << endl;

			for (int l = 0; l < strLength; l++){
				if(firstString[l] != secondString[l]){
					count++;
				}
				else{
					final.append(firstString.substr(l,1));
				}
			}

			//cout << firstString << " " << secondString << " " << count << endl;
			if (count > 0 && count <= lowCount){
				lowCount = count;
				cout << firstString << " " << secondString << " " << lowCount << endl;
				cout << final << endl;
			}
			count = 0;
			final = "";
		}
	}

		//system("pause");
		exit(-1);

		//Part 01:  7808
		//Part 02:  efmyhuckqldtwjyvisipargno

}


