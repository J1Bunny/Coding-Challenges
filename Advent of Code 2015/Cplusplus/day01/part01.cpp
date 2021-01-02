#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	double strLength = 0;
	int i = 0;
	string step = "";
	int floor = 0;

	fileString = "C:/advent/day01_input.txt";
	//fileString="C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);
	inputFile >> fileString;
	strLength = fileString.length();

	for (int i = 0; i < strLength; i++){
		step = fileString.substr(i, 1);
		if (step == "("){
			floor = floor++;
		}
		else{
			floor = floor--;
		}
	}

	cout << floor << endl;

	system("pause");
	exit(-1);

	//Part 01:  280
}

