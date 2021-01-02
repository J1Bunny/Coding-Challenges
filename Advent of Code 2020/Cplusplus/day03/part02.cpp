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
	int maxLines = 0;
	int step[5];
	int drop[5];
	int trees[5];
	string path[999];

	step[0] = 1;
	step[1] = 3;
	step[2] = 5;
	step[3] = 7;
	step[4] = 1;

	drop[0] = 1;
	drop[1] = 1;
	drop[2] = 1;
	drop[3] = 1;
	drop[4] = 2;
	int i = 0;
	int j = 0;
	int route = 0;
	int max = 0;

	for (int i = 0; i < 5; i++) {
		trees[i] = 0;
	}



	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	i = 0;
	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		path[i] = fileString;
		i++;
	}

	max = i;

	for (route = 0; route < 5; route++) {
		//opens the file
		lineNum = 1;
		currentLoc = 0;

		//tree only counts if going down
		fileString = path[i];
		i ++;

		//cout << fileString << endl;;
		//cout << "  line " << lineNum << " trees " << treeCount << " loc " << currentLoc;
		//cout << " len " << fileString.length() << endl;

		for (i = drop[route]; i < max; i=i+drop[route]) {
			lineNum++;
			fileString = path[i];

			if (currentLoc + step[route] >= fileString.length()) {
				//fileString = fileString + fileString;
				currentLoc = currentLoc - fileString.length() + step[route];

				//currentloc + 3 = 10 + 3
				//11 - 10 - 1 = 0
			} else {
				currentLoc = currentLoc + step[route];
			}

			//cout << fileString << endl;
			if (fileString.substr(currentLoc, 1).compare("#") == 0) {
				trees[route]++;
			}

			//cout << "  line " << lineNum << " trees " << treeCount << " loc " << currentLoc;
			//cout << " len " << fileString.length() << endl;

		}
		cout << "route " << route << " " << " trees " << trees[route] << " steps " << step[route] << endl;
		cout << trees[0] * trees[1] * trees[2] * trees[3] * trees[4] << endl;
	}
}

//Part 1:  282
//Part 2:  958815792

//274 - same answer for someone else, too low

