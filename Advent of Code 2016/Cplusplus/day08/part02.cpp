#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	static string grid[100][100];
	int space = 0;
	string instruction = "";
	string tempString = "";
	int sideX = 0;
	int sideY = 0;
	string holding = "";
	static string tempArray [60] = {};

	//const int realNumX = 7;//50;
	//const int realNumY = 3; //6;
	const int realNumX = 50;
	const int realNumY = 6;


	string spots[60] = {};
	int count = 0;

	for (int y = 0; y < realNumY; y++){
		for (int x = 0; x < realNumX; x++){
			grid[x][y] = ".";
			cout << grid[x][y];
		}
		cout << endl;
	}



	fileString = "C:/advent/day08_input.txt";
	//fileString = "C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){//
		cout << endl << endl;
		inputFile >> fileString;
		//cout << fileString << endl;
		instruction = fileString;

		if (instruction.compare("rect") == 0){
			inputFile >> fileString;
			strLength = fileString.length();
			space = fileString.find("x");

			sideX = stoi(fileString.substr(0, space));
			sideY = stoi(fileString.substr(space + 1, strLength - space - 1));

			for (int y = 0; y < sideY; y++){
				for (int x = 0; x < sideX; x++){
					grid[x][y] = "#";
				}
			}

			for (int y = 0; y < realNumY; y++){
				for (int x = 0; x < realNumX; x++){
					cout << grid[x][y];
				}
				cout << endl;
			}
		}

		else{
			inputFile >> fileString;
			instruction = fileString;
			if (instruction.compare("column") == 0){
				inputFile >> fileString;
				strLength = fileString.length();
				space = fileString.find("=");
				sideX = stoi(fileString.substr(space + 1, strLength - space - 1));
				inputFile >> fileString;
				inputFile >> fileString;
				sideY = stoi(fileString);

				for (int step = 0; step < realNumY; step++){
					spots[step] = grid[sideX][step];
				}

				int temp = sideY;
				for(int step = 0; step < realNumY; step ++){
					grid[sideX][temp] = spots[step];
					temp ++;
					if (temp > realNumY -1){
						temp = 0;
					}
				}

				for (int y = 0; y < realNumY; y++){
					for (int x = 0; x < realNumX; x++){
						cout << grid[x][y];
					}
					cout << endl;
				}

			}

			else{ //row
				inputFile >> fileString;
				strLength = fileString.length();
				space = fileString.find("=");
				sideX = stoi(fileString.substr(space + 1, strLength - space - 1));
				inputFile >> fileString;
				inputFile >> fileString;
				sideY = stoi(fileString);

				cout << endl;
				for (int step = 0; step < realNumX; step++){
					spots[step] = grid[step][sideX];
					cout << spots[step];
				}
				cout << endl << endl;

				int temp = sideY;
				for(int step = 0; step < realNumX; step ++){
					grid[temp][sideX] = spots[step];
					temp ++;
					if (temp > realNumX -1){
						temp = 0;
					}
				}

				for (int y = 0; y < realNumY; y++){
					for (int x = 0; x < realNumX; x++){
						cout << grid[x][y];
					}
					cout << endl;
				}
			}
		} 
	}

	for (int y = 0; y < realNumY; y++){
		for (int x = 0; x < realNumX; x++){
			if (grid[x][y].compare("#") == 0){
				count++;
			}
		}
	}

	cout << endl << count << endl;

	system("pause");
	exit(-1);

	//Part 01:  110
	//Part 02:  ZJHRKCPLYJ

}
