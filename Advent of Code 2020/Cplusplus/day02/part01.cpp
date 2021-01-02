#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int min = 0;
	int max = 0;
	string theLetter = "";
	int count = 0;
	int solution = 0;
	int strLength = 0;
	int idx = 0;
	string tempString;

	//fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString="/Users/sarahbier/Desktop/realdata.txt";

	//opens the file
	inputFile.open(fileString);
	max = 0;
	solution = 0;

	while (!inputFile.eof()) {
		//inputFile >> fileString;

		getline(inputFile, fileString);

		strLength = fileString.length();
		idx = fileString.find("-");
		tempString = fileString.substr(0, idx);
		min = atoi(tempString.c_str());

		fileString = fileString.substr(idx + 1, strLength - idx);
		strLength = fileString.length();
		idx = fileString.find(" ");
		tempString = fileString.substr(0, idx);
		max = atoi(tempString.c_str());

		fileString = fileString.substr(idx + 1, strLength - idx);
		strLength = fileString.length();
		idx = fileString.find(":");
		theLetter = fileString.substr(0, idx);

		fileString = fileString.substr(idx + 2, strLength - idx);

		cout << min << " " << max << " " << theLetter << " " << fileString
				<< endl;

		int count = 0;
		for (int i = 0; i < fileString.length(); i++) {
			if (fileString.substr(i, 1).compare(theLetter) == 0) {
				count++;
			}
		}

		if (count <= max && count >= min) {
			solution++;
		}
	}

	cout << solution << endl;

	//Part 1:  603
	//Part 2:
}
