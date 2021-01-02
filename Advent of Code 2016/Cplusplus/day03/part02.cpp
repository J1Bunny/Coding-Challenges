#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isTriangle(int sideA, int sideB, int sideC);

int main(){
	string fileString;
	ifstream inputFile;
	int stringLength = 0;
	int triA[3] = {};
	int triB[3] = {};
	int triC[3] = {};
	int i = 0;
	int totalTriangles = 0;

	fileString = "C:/advent/day03_input.txt";
	//fileString="C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		triA[i] = stoi(fileString);

		inputFile >> fileString;
		triB[i] = stoi(fileString);

		inputFile >> fileString;
		triC[i] = stoi(fileString);
		i++;

		if(i == 3){
			//cout << triA[0] << " " << triA[1] << " "  << triA[2] << endl;
			i = 0;
			if (isTriangle(triA[0],triA[1],triA[2])){
				totalTriangles = totalTriangles ++;
			}
			if (isTriangle(triB[0],triB[1],triB[2])){
				totalTriangles = totalTriangles ++;
			}
			if (isTriangle(triC[0],triC[1],triC[2])){
				totalTriangles = totalTriangles ++;
			}
		}
	}

	cout << endl << totalTriangles << endl;

	system("pause");
	exit(-1);

	//Part 1:  982
	//Part 2:  1826

}

bool isTriangle(int sideA, int sideB, int sideC){
	bool triangleTrue = false;
	int largeSide = 0;
	int smallSide[2] = {};

	if (sideA >= sideB && sideA >= sideC){
		largeSide = sideA;
		smallSide[0] = sideB;
		smallSide[1] = sideC;
	}
	else if (sideB >= sideA && sideB >= sideC){
		largeSide = sideB;
		smallSide[0] = sideA;
		smallSide[1] = sideC;
	}
		else if (sideC >= sideB && sideC >= sideA){
		largeSide = sideC;
		smallSide[0] = sideB;
		smallSide[1] = sideA;
	}

	if (smallSide[0] + smallSide[1] > largeSide){
		triangleTrue = true;
	}
	return triangleTrue;
}
