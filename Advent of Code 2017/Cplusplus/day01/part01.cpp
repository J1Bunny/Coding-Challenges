#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
	string fileString;
	ifstream inputFile;
	int firstNum;
	int total;
	int max;
	int list[99999];

	string tempChar;


	fileString = "C:/advent/input.txt";
	//fileString = "C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		//cout << fileString << endl;
		max = fileString.length();
	}

	//cout << max << endl;


	for (int i = 0; i < max; i++){
		tempChar = fileString.substr(i,1);
		list[i] = atoi(tempChar.c_str());
	}

	total = 0;
	firstNum = list[0];
	for (int i = 0; i < max; i++){
		if (i < max - 1){
			if (list[i] == list[i + 1]){
				total = total + list[i];
			}
		}
		else{
			if (list[i] == list[0]){
				total = total + list[i];
			}
		}
	}

	cout << "Total: " << total << endl;

	system("pause");
	exit(-1);

	//Part 1:  1031

}
