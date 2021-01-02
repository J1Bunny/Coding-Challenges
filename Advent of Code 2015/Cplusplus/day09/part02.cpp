#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	string locationA = "";
	string locationB = "";
	int distance = 0;
	int distList [8][8] = {};
	int locA = 0;
	int locB = 0;
	int totalDistance = 0;
	int smallDistance = 0;


	fileString = "C:/advent/2015/day09_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		strLength = fileString.length();
		locationA = fileString;
		inputFile >> fileString;
		inputFile >> fileString;
		locationB = fileString;
		inputFile >> fileString;
		inputFile >> fileString;
		distance = stoi(fileString);
		//cout << locationA << " " << locationB << " " << distance << endl;

		if(locationA.compare("Faerun") ==0){
			locA = 0;
		}
		else if(locationA.compare("Norrath") ==0){
			locA = 1;
		}
		else if(locationA.compare("Tristram") ==0){
			locA = 2;
		}
		else if(locationA.compare("AlphaCentauri") ==0){
			locA = 3;
		}
		else if(locationA.compare("Arbre") ==0){
			locA = 4;
		}
		else if(locationA.compare("Snowdin") ==0){
			locA = 5;
		}
		else if(locationA.compare("Tambi") ==0){
			locA = 6;
		}
		else if(locationA.compare("Straylight") ==0){
			locA = 7;
		}

		if(locationB.compare("Faerun") ==0){
			locB = 0;
		}
		else if(locationB.compare("Norrath") ==0){
			locB = 1;
		}
		else if(locationB.compare("Tristram") ==0){
			locB = 2;
		}
		else if(locationB.compare("AlphaCentauri") ==0){
			locB = 3;
		}
		else if(locationB.compare("Arbre") ==0){
			locB = 4;
		}
		else if(locationB.compare("Snowdin") ==0){
			locB = 5;
		}
		else if(locationB.compare("Tambi") ==0){
			locB = 6;
		}
		else if(locationB.compare("Straylight") ==0){
			locB = 7;
		}

		//cout << locA << " " << locB << " " << distance << endl;
		distList[locA][locB] = distance;
		distList[locB][locA] = distance;
	}

	totalDistance = 0;
	int entireList [] = {0,1,2,3,4,5,6,7};
	for(int i = 0; i < 8; i++){
		cout << entireList[i];
		if(i < 7){
			totalDistance = totalDistance + distList[entireList[i]][entireList[i+1]];
			//cout << "next " << totalDistance << endl;
			smallDistance = totalDistance;
		}
	}

	cout << " " << totalDistance << endl;

	for(int k = 0; k<40500; k++){
		totalDistance = 0;
		next_permutation(entireList, entireList+8);
		for(int i = 0; i < 8; i++){
			cout << entireList[i];
			if(i < 7){
				totalDistance = totalDistance + distList[entireList[i]][entireList[i+1]];
			}
		}
		cout << " " << totalDistance << endl;
		if(totalDistance>smallDistance){
			cout << " < check < " << smallDistance << endl;
			smallDistance = totalDistance;
			system("pause");
		}
	}


	system("pause");
	exit(-1);

	//Part 01:  207
	//Part 02:  804
}
