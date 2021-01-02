//not yet working

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//int countLetters(string current);
string newString = "";

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	int charCount = 0;
	int totalCount = 0;
	string newString = "";
	double intString [15000] = {};
	int space = 0;
	int letters = 0;
	int repeat = 0;
	int xSpot = 0;
	string tempString = "";
	double totalLength = 0;

	fileString = "C:/advent/day09_input.txt";
	//fileString = "C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	inputFile >> fileString;
	//cout << fileString << endl;
	strLength = fileString.length();
	newString = "";
	cout << strLength << endl;

	for (int i =0; i < strLength; i++){
		intString[i] = 1;
	}

	for (int i = 0; i < strLength; i++){
		char step = fileString[i];

		if(step!=40){
			totalLength = totalLength + intString[i];
		}
		else{
			string another = fileString.substr(i, fileString.length()); 
			space = another.find(")");
			tempString = another.substr(1,space - 1);
			xSpot = tempString.find("x");
			letters = stoi(tempString.substr(0,xSpot));
			repeat = stoi(tempString.substr(xSpot+1,tempString.length() - xSpot));

			for(int j = 0; j<letters; j++){
				intString[space + 1+j+i]=intString[space + 1+j + i]*repeat;
			}

			i = i + space;
		}

	}

	cout.precision(17);
	cout << totalLength << endl;

	system("pause");
	exit(-1);

	//Part 01:  123908
	//Part 02:  10755693147


}
