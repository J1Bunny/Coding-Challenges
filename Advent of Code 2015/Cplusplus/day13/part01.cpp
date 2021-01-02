#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	string tempString = "";
	int strLength = 0;
	int space = 0;
	int seatA = -1;
	int seatB = -1;
	int happy = 0;
	int arrange[8][8] = {};
	int totalHappy = 0;
	int highHappy = 0;

	fileString = "C:/advent/2015/day13_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;

		if(seatA == -1){
			if(fileString.compare("Alice") ==0){
				seatA = 0;
			}
			else if(fileString.compare("Bob") ==0){
				seatA = 1;
			}
			else if(fileString.compare("Carol") ==0){
				seatA = 2;
			}
			else if(fileString.compare("David") ==0){
				seatA = 3;
			}
			else if(fileString.compare("Eric") ==0){
				seatA = 4;
			}
			else if(fileString.compare("Frank") ==0){
				seatA = 5;
			}
			else if(fileString.compare("George") ==0){
				seatA = 6;
			}
			else if(fileString.compare("Mallory") ==0){
				seatA = 7;
			}
		}

		if (fileString.compare("lose") == 0){
			inputFile >> fileString;
			happy = stoi(fileString) *-1;
		}
		if (fileString.compare("gain") == 0){
			inputFile >> fileString;
			happy = stoi(fileString);
		}

		if(seatA > -1){
			if(fileString.compare("Alice.") ==0){
				seatB = 0;
			}
			else if(fileString.compare("Bob.") ==0){
				seatB = 1;
			}
			else if(fileString.compare("Carol.") ==0){
				seatB = 2;
			}
			else if(fileString.compare("David.") ==0){
				seatB = 3;
			}
			else if(fileString.compare("Eric.") ==0){
				seatB = 4;
			}
			else if(fileString.compare("Frank.") ==0){
				seatB = 5;
			}
			else if(fileString.compare("George.") ==0){
				seatB = 6;
			}
			else if(fileString.compare("Mallory.") ==0){
				seatB = 7;
			}
		}

		if(seatA > -1 && seatB > -1){
			cout << seatA << "." << seatB<< "."  << happy << "." << endl;
			arrange[seatA][seatB] = happy;
			seatA = -1;
			seatB = -1;
			happy = 0;
		}
	}

	int entireList [] = {0,1,2,3,4,5,6,7};
	for(int i = 0; i < 8; i++){
		cout << entireList[i];
		if(i < 7){
			totalHappy = totalHappy + arrange[entireList[i]][entireList[i+1]];
			totalHappy = totalHappy + arrange[entireList[i+1]][entireList[i]];
		}
		else{
			cout << entireList[0];
			totalHappy = totalHappy + arrange[entireList[7]][entireList[0]];
			totalHappy = totalHappy + arrange[entireList[0]][entireList[7]];
		}
	}

	cout << " " << totalHappy << endl;
	highHappy = totalHappy;
	totalHappy = 0;

	for(int k = 0; k<40500; k++){
		totalHappy = 0;
		next_permutation(entireList, entireList+8);
		for(int i = 0; i < 8; i++){
			cout << entireList[i];
			if(i < 7){
				totalHappy = totalHappy + arrange[entireList[i]][entireList[i+1]];
				totalHappy = totalHappy + arrange[entireList[i+1]][entireList[i]];
			}
			else{
				cout << entireList[0];
				totalHappy = totalHappy + arrange[entireList[7]][entireList[0]];
				totalHappy = totalHappy + arrange[entireList[0]][entireList[7]];
			}
		}

		cout << " " << totalHappy << endl;
		if(totalHappy > highHappy){
			highHappy = totalHappy;
			system("pause");
		}
		totalHappy = 0;
	}

	system("pause");
	exit(-1);

	//Part 01:  664
	//Part 02:  
}
