#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	double strLength = 0;
	int x = 0;
	int y = 0;
	char step = 'a';
	int i = 0;
	int max = 1;
	bool found = false;
	string houses[9999] = {};
	string newSpot = "";

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
		//cout << step << endl;
		if (step == '^'){
			y++;
		}
		else if (step == 'v'){
			y--;
		}
		else if (step == '>'){
			x++;
		}
		else if (step == '<'){
			x--;
		}
		else{
			cout << "stop" << endl;
		}

		newSpot = to_string(x) + "," + to_string(y);
		found = false;
		
		for(int j = 0; j < max; j++){
			if (houses[j] == newSpot){
				found = true;
			}
		}

		if(!found){
			houses[max] = newSpot;
			max++;
		}
	}

	cout << max << endl;


	system("pause");
	exit(-1);

	//Part 01:  2081
	//Part 02:  
}
