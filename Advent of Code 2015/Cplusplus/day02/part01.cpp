#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	int idx = 0;
	string tempSide = "";
	int side[3] = {};
	int totalArea = 0;
	int smallArea = 0;
	int finalArea = 0;

	fileString = "C:/advent/day02_input.txt";
	//fileString="C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		//cout << fileString << endl;

		strLength = fileString.length();
		idx = fileString.find("x");
		tempSide = fileString.substr(0, idx);
		side[0] = atoi(tempSide.c_str());

		fileString = fileString.substr(idx+1, strLength - idx);
		strLength = fileString.length();
		idx = fileString.find("x");
		tempSide = fileString.substr(0, idx);
		side[1] = atoi(tempSide.c_str());

		fileString = fileString.substr(idx + 1, strLength - idx);
		strLength = fileString.length();
		side[2] = atoi(fileString.c_str());

		if (side[0] <= side[1] && side[0] <= side[2]){
			if (side[1] <= side[2]){
				smallArea = side[0] * side[1];
			}
			else{
				smallArea = side[0] * side[2];
			}
		}

		else if (side[1] <= side[0] && side[1] <= side[2]){
			if (side[0] <= side[2]){
				smallArea = side[1] * side[0];
			}
			else{
				smallArea = side[1] * side[2];
			}
		}

		else if (side[2] <= side[1] && side[2] <= side[0]){
			if (side[1] <= side[0]){
				smallArea = side[2] * side[1];
			}
			else{
				smallArea = side[2] * side[0];
			}
		}

		totalArea = (2 * side[0] * side[1]) + (2 * side[1] * side[2]) + (2 * side[0] * side[2]);

		cout << totalArea << endl;
		cout << smallArea << endl << endl;

		finalArea = finalArea + totalArea + smallArea;
		totalArea = 0;
		smallArea = 0;

	}

	cout << endl << finalArea << endl;

	system("pause");
	exit(-1);

	//Part 01:  1598415
	//Part 02:  
}
