#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
	double row = 2981;
	double column = 3075;
	double currentRow = 1;
	double currentColumn = 1;
	double max = 1;
	double start = 20151125;
	double multBy = 252533;
	double divBy = 33554393;
	double newCode = 0;
	bool found = false;

	cout << "(" << currentRow << "," << currentColumn << ")" << endl;
	cout.precision(17);
	cout << start << endl;
	currentRow = 2;
	currentColumn = 1;
	max = 2;


	while(!found){
		start = start * multBy;
		newCode = fmod(start,divBy);
		//cout << "(" << currentRow << "," << currentColumn << ")" << endl;
		//cout.precision(17);
		//cout << newCode << endl;
		if(currentColumn == 3075 && currentRow == 2981){
			cout << "(" << currentRow << "," << currentColumn << ")" << endl;
			cout.precision(17);
			cout << newCode << endl;
			found = true;
			system("pause");
		}
		start = newCode;
		if(currentColumn == max){
			max++;
			currentColumn = 1;
			currentRow = max;
		}
		else{
			currentColumn ++;
			currentRow --;
		}
	}


	system("pause");
	exit(-1);

	//Part 01:  9132360
	//Part 02:  
}
