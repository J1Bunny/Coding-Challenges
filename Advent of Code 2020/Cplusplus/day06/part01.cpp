#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string usedAnswers = "";
	int count = 0;
	int finalCount = 0;


	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);

		if(fileString.length() == 0){
			cout << count << " ";
			finalCount = finalCount + count;
			count = 0;
			usedAnswers = "";
		}

		for (int j = 0; j < fileString.length(); j++) {
			char ch = fileString[j];
			if (usedAnswers.find(ch) == std::string::npos){
				count++;
			}
			usedAnswers.push_back(ch);
		}

		cout << fileString << endl;
	}

	cout << count << endl;
	finalCount = finalCount + count;

	cout << "total " << finalCount << endl;



//Part 1:  6703
//Part 2:

}
