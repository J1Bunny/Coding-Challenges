#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int addStep(int push, int alt);
int minusStep(int push, int alt);

int main(){
	string fileString;
	ifstream inputFile;
	double stringLength = 0;
	int x = -2;
	int y = 0;
	string step;
	string button = "";

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
				y = addStep(y, x);
			}
			else if (step == "D"){
				y = minusStep(y, x);
			}
			else if (step == "R"){
				x = addStep(x, y);
			}
			else if (step == "L"){
				x = minusStep(x, y);
			}

		}

		if (x == -1){
			if (y == -1){
				button = "A";
			}
			else if (y == 0){
				button = "6";
			}
			else if (y == 1){
				button = "2";
			}
		}
		else if (x == 0){
			if (y == -1){
				button = "B";
			}
			else if (y == 0){
				button = "7";
			}
			else if (y == 1){
				button = "3";
			}
		}
		else if (x == 1){
			if (y == -1){
				button = "C";
			}
			else if (y == 0){
				button = "8";
			}
			else if (y == 1){
				button = "4";
			}
		}
		else{
			button = "";
		}
			cout << x << " " << y << endl;
			cout << button << endl;
	}

	cout << endl << endl;

	system("pause");
	exit(-1);

	//Part 1:  12578
	//Part 2:  516DD
	
}

int addStep(int push, int alt){
	if (abs(alt) == 1){
		if (push < 1){
			push++;
		}
	}
	else if (alt == 0){
		if (push < 2){
			push++;
		}
	}

	return push;
}

int minusStep(int push, int alt){
	if (abs(alt) == 1){
		if (push > -1){
			push--;
		}
	}
	else if (alt == 0){
		if (push > -2){
			push--;
		}
	}

	return push;
}
