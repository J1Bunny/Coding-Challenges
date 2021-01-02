#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	double strLength = 0;
	//int i = 0;
	double freq = 0;
	double distance = 0;
	string step;
	string add = "+";

	//fileString = "C:/advent/day01_input.txt";
	//fileString="C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		strLength = fileString.length();
		step = fileString.substr(0, 1);
		distance = stoi(fileString);
		freq = freq + distance;
		//cout << freq << endl;
	}


	cout << "freq:  " << freq << endl;

	//system("pause");
	exit(-1);

	//Part 01:  525
}
