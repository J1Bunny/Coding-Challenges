#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int addStep(int push);
int minusStep(int push);

int main(){
	string fileString;
	ifstream inputFile;
	double stringLength = 0;
	int x = 0;
	int y = 0;
	string step;
	int button = 0;

	fileString = "C:/advent/day02_input.txt";
	//fileString="C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		stringLength = fileString.length();
		for (int i = 0; i < stringLength; i++){
			step = fileString.substr(i, 1);

			if (step == "U"){
				y = addStep(y);
			}
			else if (step == "D"){
				y = minusStep(y);
			}
			else if (step == "R"){
				x = addStep(x);
			}
			else if (step == "L"){
				x = minusStep(x);
			}

		}

		if (x == -1){
			if (y == -1){
				button = 7;
			}
			else if (y == 0){
				button = 4;
			}
			else if (y == 1){
				button = 1;
			}
		}
		else if (x == 0){
			if (y == -1){
				button = 8;
			}
			else if (y == 0){
				button = 5;
			}
			else if (y == 1){
				button = 2;
			}
		}
		else if (x == 1){
			if (y == -1){
				button = 9;
			}
			else if (y == 0){
				button = 6;
			}
			else if (y == 1){
				button = 3;
			}
		}

		cout << button;
	}

	cout << endl << endl;

	system("pause");
	exit(-1);

	//Part 1:  12578

}

int addStep(int push){
	if (push < 1){
		push++;
	}

	return push;
}

int minusStep(int push){
	if (push > -1){
		push--;
	}

	return push;
}

