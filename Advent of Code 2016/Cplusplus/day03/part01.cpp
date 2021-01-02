#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isTriangle(int sideA, int sideB, int sideC);

int main(){
	string fileString;
	ifstream inputFile;
	int stringLength = 0;
	int side[3] = {};
	int i = 0;
	int totalTriangles = 0;

	fileString = "C:/advent/day03_input.txt";
	//fileString="C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;

		side[i] = stoi(fileString);
		i++;

		if(i == 3){
			//cout << side[0] << " " << side[1] << " "  << side[2] << endl;
			i = 0;
			if (isTriangle(side[0],side[1],side[2])){
				totalTriangles = totalTriangles ++;
			}
		}
	}

	cout << endl << totalTriangles << endl;

	system("pause");
	exit(-1);

	//Part 1:  982

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
