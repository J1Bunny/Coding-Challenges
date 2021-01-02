#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	string instruction = "";
	string first = "";
	string second = "";
	static int grid[999][999];
	int firstX = 0;
	int firstY = 0;
	int secondX = 0;
	int secondY = 0;
	int comma = 0;
	int lights = 0;

	for (int i = 0; i < 999 ; i++){
		for (int j = 0; j < 999; j++){
			grid[i][j]=0;
		}
	}

	fileString = "C:/advent/2015/day06_input.txt";
	//fileString="C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		//cout << fileString << endl;

		if (fileString.compare("on") == 0 || fileString.compare("off") == 0 || fileString.compare("toggle") == 0){
			instruction = fileString;
			inputFile >> fileString;
			first = fileString;
			inputFile >> fileString;
			inputFile >> fileString;
			second = fileString;

			comma = first.find(",");
			strLength = first.length();
			firstX = stoi(first.substr(0,comma));
			firstY = stoi(first.substr(comma + 1,strLength - (comma + 1)));

			comma = second.find(",");
			strLength = second.length();
			secondX = stoi(second.substr(0,comma));
			secondY = stoi(second.substr(comma + 1,strLength - (comma + 1)));

			//cout << instruction << " " << firstX << " " << firstY << " " << secondX << " " << secondY << endl;

			if(instruction.compare("on") == 0){
				for (int i = firstX; i <= secondX ; i++){
					for (int j = firstY; j <= secondY; j++){
						grid[i][j]=grid[i][j]+1;
					}
				}
			}
			else if (instruction.compare("off") == 0){
				for (int i = firstX; i <= secondX ; i++){
					for (int j = firstY; j <= secondY; j++){
						if(grid[i][j]>0){
							grid[i][j]=grid[i][j]-1;
						}
					}
				}
			}
			else if (instruction.compare("toggle") == 0){
				for (int i = firstX; i <= secondX ; i++){
					for (int j = firstY; j <= secondY; j++){
						grid[i][j]=grid[i][j]+2;
					}
				}
			}
		}
	}

	for (int i = 0; i < 1000 ; i++){
		for (int j = 0; j < 1000; j++){
			lights = lights+grid[i][j];
		}
	}

	cout << lights << endl;

	system("pause");
	exit(-1);

	//Part 01:  377891
	//Part 02:  14110788

}
