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
	int half;
	int list[99999];
	int newList[99999];

	string tempChar;
	int j;


	fileString = "C:/advent/input.txt";
	//fileString = "C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		//cout << fileString << endl;
		max = fileString.length();
	}

	half = max / 2;
	//cout << max << endl;


	for (int i = 0; i < max; i++){
		j = i + half;
		if (j == max){
			j = 0;
		}
		else if (j > max){
			j = i-half;
		}

		//cout << i << " " << j << endl;

		tempChar = fileString.substr(i, 1);
		list[i] = atoi(tempChar.c_str());

		tempChar = fileString.substr(j, 1);
		newList[i] = atoi(tempChar.c_str());

		//cout << list[i] << " " << newList[i] << endl;
	}

	total = 0;
	firstNum = list[0];
	for (int i = 0; i < max; i++){
			if (list[i] == newList[i]){
				total = total + list[i];
			}
	}

	cout << "Total: " << total << endl;

	system("pause");
	exit(-1);

	//Part 1:  1031
	//Part 2:  1080

}




