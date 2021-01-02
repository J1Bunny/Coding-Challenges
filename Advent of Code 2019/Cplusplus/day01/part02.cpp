#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	int number = 0;
	int total = 0;

//fileString = "C:/advent/day01_input.txt";
//fileString="C:/advent/testdata.txt";
	fileString = "/Users/sarahwilkinson/Desktop/testdata.txt";
//fileString="/Users/sarahbier/Desktop/realdata.txt";

//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		//cout << fileString << endl;
		number = stoi(fileString);

		number = number / 3;
		//cout << number << endl;

		number = number - 2;
		//cout << number << endl;
		total = total + number;

		while (number > 0){
			number = number / 3;
			//cout << number << endl;

			number = number - 2;
			cout << number << endl;
			if(number > 0){
			total = total + number;}
		}
	}

	cout << total << endl;

	//Part 01:  3415695
	//Part 02:  5120654
	exit(-1);
}


