#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int currentLoc = 0;
	int treeCount = 0;
	int lineNum = 0;

	int min = 0;
	int max = 0;
	string theLetter = "";
	int count = 0;
	int solution = 0;
	int strLength = 0;
	int idx = 0;
	string tempString;
	int slot1 = 0;
	int slot2 = 0;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	//fileString = "/Users/sarahbier/Desktop/realdata.txt";

	//opens the file
	inputFile.open(fileString);
	max = 0;
	solution = 0;
	lineNum = 1;
	currentLoc = 0;

	//tree only counts if going down
	getline(inputFile, fileString);
	cout << fileString;
	cout << "  line " << lineNum << " trees " << treeCount << " loc " << currentLoc;
	cout << " len " << fileString.length() << endl;

	while (!inputFile.eof()) {
		lineNum++;
		getline(inputFile, fileString);

		if(currentLoc + 3 >= fileString.length()){
			//fileString = fileString + fileString;
			currentLoc = currentLoc - fileString.length() + 3;

			//currentloc + 3 = 10 + 3
			//11 - 10 - 1 = 0
		}
		else{
			currentLoc = currentLoc + 3;
		}

		cout << fileString;
		if (fileString.substr(currentLoc, 1).compare("#") == 0) {
			treeCount++;
		}




		cout << "  line " << lineNum << " trees " << treeCount << " loc " << currentLoc;
		cout << " len " << fileString.length() << endl;



	}

	cout << endl << treeCount << endl;

	//Part 1:  282
	//Part 2:

	//274 - same answer for someone else, too low
}


