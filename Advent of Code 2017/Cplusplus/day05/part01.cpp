#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
	string fileString;
	ifstream inputFile;
	int jumps[99999];
	int max;
	int i;
	int newJump;
	int steps;


	fileString = "C:/advent/input.txt";
	//fileString = "C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	i = 0;
	while (!inputFile.eof()){
		inputFile >> fileString;
		//cout << fileString << endl;
		jumps[i] = atoi(fileString.c_str());
		i++;
	}

	max = i - 1;
	i = 0; 
	newJump = 0;
	steps = 0;

	while (newJump<max){
		newJump = i + jumps[i];
		jumps[i]++;
		i = newJump;
		steps++;
	}


	cout << steps << endl;

	system("pause");
	exit(-1);

	//Part 1:  372139
	//Part 2:  

}




