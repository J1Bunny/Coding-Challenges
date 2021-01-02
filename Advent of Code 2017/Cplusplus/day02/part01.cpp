#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
	string fileString;
	ifstream inputFile;
	string line;
	int strLength;
	//int list[9999];
	int i;
	int step;
	string numberChar;
	int max;
	string blank = " ";
	int pos;
	string tempString;
	int large;
	int small;
	int tempNum;
	int checkSum;

	fileString = "C:/advent/input.txt";
	//fileString = "C:/advent/testdata.txt";

	ifstream fileName(fileString);
	i = 0;
	step = 0;
	numberChar = "";
	checkSum = 0;


	while (!fileName.eof()){
		pos = 99;
		tempString = "";
		getline(fileName, line);
		step = 0;
		max = 0;
		large = 0;
		small = 99999;
		//cout << line << endl;

		while (pos >0){
			strLength = line.length();
			//cout << line << endl;
			pos = line.find("	");
			tempString = line.substr(0, pos);
			line = line.substr(pos + 1, strLength - pos - 1);
			tempNum = atoi(tempString.c_str());
			//cout << tempNum << " ";


			if (tempNum > large){
				large = tempNum;
			}
			if (tempNum < small){
				small = tempNum;
			}
		}
		//system("pause");

		cout << "fin " << small << " " << large << endl;
		checkSum = checkSum + (large - small);
		large = 0;
		small = 99999;
	}

	fileName.close();
	cout << endl << checkSum << endl;

	system("pause");
	exit(-1);

	//Part 1:  53460 
	//Part 2:  

}
