#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int ingredients[4][5] = {};
	string maybeNum = "";
	int space = 0;
	int type = 0;
	int prop = 0;
	int sugar = 0;
	int sprinkles = 0;
	int candy = 0;
	int chocolate = 0;
	int score[4] = {};
	int total = 0;
	int highScore = 0;

	fileString = "C:/advent/2015/day15_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		space = fileString.find(",");
		if(space>0){
			maybeNum = fileString.substr(0,space);
			ingredients[type][prop] = stoi(maybeNum);
			prop++;
		}
		if(prop == 4){
			inputFile >> fileString;
			inputFile >> fileString;
			maybeNum = fileString.substr(0,1);
			ingredients[type][prop] = stoi(maybeNum);
			type++;
			prop = 0;
		}
	}

	/*
	for (int x = 0; x < 4; x++){
	for (int y = 0; y < 5; y++){
	cout << ingredients[x][y] << " " ;
	}
	cout << endl;
	}
	*/


	for (int i = 1; i < 101; i++){
		for (int j = 1; j < 101-i; j++){
			for (int k = 0; k < 100-i-j; k++){
				int l = 100-i-j-k;
				//cout << i << " " << j << " " << k << " " << l << endl;
				total = 0;
				score[0] = i * ingredients[0][0] + j * ingredients[1][0] + k * ingredients[2][0] + l * ingredients[3][0];
				score[1] = i * ingredients[0][1] + j * ingredients[1][1] + k * ingredients[2][1] + l * ingredients[3][1];
				score[2] = i * ingredients[0][2] + j * ingredients[1][2] + k * ingredients[2][2] + l * ingredients[3][2];
				score[3] = i * ingredients[0][3] + j * ingredients[1][3] + k * ingredients[2][3] + l * ingredients[3][3];

				for (int q = 0; q<4; q++){
					if (score[q] < 0){
						score[q] = 0;
					}
				}

				total = score[0] * score[1] * score[2] * score[3];

				if(total > highScore){
					highScore = total;
				}
			}
		}
	}

	cout << highScore << endl;

	system("pause");
	exit(-1);

	//Part 01:  222870
	//Part 02:  
}
