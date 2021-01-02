#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void combineJars(int jars, int ways, int *newOne, int size, int current, int total);
int jarArray[20] = {};
int totalWays = 0;
int actual = 0;
int minNumber [20] = {};

int main(){
	string fileString;
	ifstream inputFile;
	//string items[10] = {};
	int currentTotal = 0;
	int max = 0;
	int step = 0;

	fileString = "C:/advent/2015/day17_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		jarArray[step] = stoi(fileString);
		step++;
	}

	inputFile.close();

	totalWays = 0;
	cout << "first " << totalWays << endl;

	for(int methods = 20; methods > 1; methods--){
	//for(int methods = 5; methods > 1; methods--){
		int totalJars = 20;
		//int methods = 20;
		int *newArray = new int[methods];
		currentTotal = 0;
		combineJars(totalJars, methods, newArray, methods, currentTotal, totalWays);
	}

	for(int i = 0; i < 20; i ++){
		cout << i << " " << minNumber[i] << endl;
	}


	system("pause");
	exit(-1);

	//Part 01:  1638
	//Part 02:  17
}


void combineJars(int jars, int ways, int *newOne, int size, int current, int total){
	for (int j = jars; j >= ways; j--){
		newOne[ways - 1] = j;
		if (ways > 1){ 
			combineJars(j - 1, ways - 1, newOne, size, current, total);
		} 
		else{
			for (int j = 0; j < size; j ++){
				if(j == 0){
					current = 0;
				}
				current = current + jarArray[newOne[j]-1];
				//cout << newOne[j] << " ";
				//cout << "jar " << newOne[j] <<  " " << jarArray[newOne[j]-1] << " current " << current << " size " << size << endl;
			}
			if(current == 150){
				total++;
				//cout << "total " << total << endl;
				//cout << "size " << size << endl;
			}
			//cout << endl << current << endl;
			//cout << endl;
			//system("pause");
		}
	}

	actual = actual + total;
	if (total == 1){
		minNumber[size] = minNumber[size] + 1;
	}
	cout << actual << endl;
}

