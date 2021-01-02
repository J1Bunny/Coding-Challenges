#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	static int grid[105][105];
	static int newGrid[105][105];
	int newLight = 0;
	int lightsOn = 0;
	int step = 0;
	int lights = 0;
	int original = 100;
	//int original = 6;

	for (int i = -1; i < original +1; i++){
		for (int j = -1; j < original +1; j++){
			grid[i][j]=5;
		}
	}

	for (int i = 0; i < original ; i++){
		for (int j = 0; j < original; j++){
			grid[i][j]=0;
		}
	}

	fileString = "C:/advent/2015/day18_input.txt";
	//fileString="C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		strLength = fileString.length();
		for(int i = 0; i < strLength; i++){
			if(fileString.substr(i,1).compare("#") == 0){
				grid[step][i] = 1;
			}
			else{
				grid[step][i] = 0;
			}
		}
		step++;
	}

	/*
	for (int x = 0; x < original; x++){
		for (int y = 0; y < original; y++){
			cout << grid[x][y];
		}
		cout << endl;
	}
	*/

	for(int i = 0; i < 100; i++){
		for (int x = 0; x < original; x++){
			for (int y = 0; y < original; y++){
				lightsOn = 0;

				if(grid[x-1][y-1] == 1){
					lightsOn++;
				}
				if(grid[x-1][y] == 1){
					lightsOn++;
				}
				if(grid[x-1][y+1] == 1){
					lightsOn++;
				}
				if(grid[x][y-1] == 1){
					lightsOn++;
				}
				if(grid[x][y+1] == 1){
					lightsOn++;
				}
				if(grid[x+1][y-1] == 1){
					lightsOn++;
				}
				if(grid[x+1][y] == 1){
					lightsOn++;
				}
				if(grid[x+1][y+1] == 1){
					lightsOn++;
				}

				if(grid[x][y] == 0){
					if(lightsOn == 3){
						newGrid[x][y] = 1;
					}
					else{
						newGrid[x][y] = 0;
					}
				}
				else{
					if(lightsOn == 2 || lightsOn == 3){
						newGrid[x][y] = 1;
					}
					else{
						newGrid[x][y] = 0;
					}
				}
			}
		}

		for (int x = 0; x < original; x++){
			for (int y = 0; y < original; y++){
				grid[x][y] = newGrid[x][y];
			}
		}
	}

	for (int x = 0; x < original; x++){
		for (int y = 0; y < original; y++){
			lights = lights + grid[x][y];
		}
	}

	cout << lights << endl;

	system("pause");
	exit(-1);

	//Part 01:  768
	//Part 02:  

}
