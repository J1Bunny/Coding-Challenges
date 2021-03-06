#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int stringLength = 0;
	int letterCount[27] = {};
	string sector = "";
	int totalChars = 0;
	int max = 0;
	char actual = 'a';
	int columns = 0;
	string lines[999] = {};
	int step = 0;

	fileString = "C:/advent/day06_input.txt";
	//fileString = "C:/advent/testdata.txt";
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		lines[step] = fileString;
		step++;
	}

	while (columns < 8){
		max = 9999;
		for (int i = 0; i < 27; i++){
			letterCount[i] = 0;
		}

		for (int i = 0; i < step; i++){
			char charLetter = lines[i][columns];
			//cout << charLetter << endl;
			letterCount[int(charLetter) - 96] = letterCount[int(charLetter) - 96] + 1;
		}

		for (int i = 0; i < 27; i++){
			if (letterCount[i] < max && letterCount[i] > 0){
				max = letterCount[i];
			}
		}

		cout << max << endl;

		for (int j = 1; j < 27; j++){
			//cout << j << " " << letterCount[j] << endl;
			//cout << max << endl;
			if (letterCount[j] == max){
				//cout << char(j + 96) << " " << letterCount[j] << " " << max << endl;
				sector.append(1, char(j + 96));
				//cout << sector << endl;
			}
		}
		columns++;
	}
		
	cout << sector << endl;
	cout << endl << endl;
	system("pause");
	exit(-1);

	//Part 1:  wkbvmikb
	//Part 2:  evakwaga
}



	
