#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	double strLength = 0;
	int xSanta = 0;
	int ySanta = 0;
	int xRobo = 0;
	int yRobo = 0;
	char step = 'a';
	int i = 0;
	int max = 1;
	bool found = false;
	string houses[9999] = {};
	string newSanta = "";
	string newRobo = "";

	fileString = "C:/advent/2015/day03_input.txt";
	//fileString="C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
	}

	houses[0] = "0,0";
	strLength = fileString.length();
	for (int i = 0; i< strLength; i++){
		char step = fileString[i];
		//cout << i << endl;
		if (i % 2 == 0){
			if (step == '^'){
				ySanta++;
			}
			else if (step == 'v'){
				ySanta--;
			}
			else if (step == '>'){
				xSanta++;
			}
			else if (step == '<'){
				xSanta--;
			}

			newSanta = to_string(xSanta) + "," + to_string(ySanta);
			found = false;
		
			for(int j = 0; j < max; j++){
				if (houses[j] == newSanta){
					found = true;
				}
			}

			if(!found){
				houses[max] = newSanta;
				max++;
			}
		}
		else{
			if (step == '^'){
				yRobo++;
			}
			else if (step == 'v'){
				yRobo--;
			}
			else if (step == '>'){
				xRobo++;
			}
			else if (step == '<'){
				xRobo--;
			}

			newRobo = to_string(xRobo) + "," + to_string(yRobo);
			found = false;
		
			for(int j = 0; j < max; j++){
				if (houses[j] == newRobo){
					found = true;
				}
			}

			if(!found){
				houses[max] = newRobo;
				max++;
			}

		}

	}

	cout << max << endl;


	system("pause");
	exit(-1);

	//Part 01:  2081
	//Part 02:  2341
}
