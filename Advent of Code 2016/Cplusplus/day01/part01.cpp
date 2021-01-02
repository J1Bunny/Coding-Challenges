#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int xArray [999] = {};
int yArray [999] = {};
int k = 0;
double x = 0;
double y = 0;
bool found;

double addXStep(double startSteps, double pathSteps);
double minusXStep(double startSteps, double pathSteps);
double addYStep(double startSteps, double pathSteps);
double minusYStep(double startSteps, double pathSteps);

int main(){
	string fileString;
	ifstream inputFile;
	string steps [9999] = {};
	int max;
	max = 0;
	string direction = "N";
	string turn = "";
	double path = 0;
	int point;
	point = 0;
	int stringLength = 0;
	xArray[0] = 0;
	yArray[0] = 0;
	found = false;

	fileString="C:/advent/day01_input.txt";
	//fileString="C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		stringLength = fileString.size();

		if (fileString.substr(stringLength - 1,stringLength - 1) == ","){
			point = stringLength - 1;
		}
		else{
			point = stringLength;
		}

		steps[max] = fileString.substr (0, point);
		max++;
	}

	for (int i = 0; i<max; i++){
		if (steps[i]!=""){
			turn = steps[i].substr(0,1);
			path = atof((steps[i].substr(1,point + 1)).c_str());

			if (direction == "N"){
				if (turn == "R"){
					direction = "E";
					x = addXStep(x, path);
				}
				else{
					direction = "W";
					x = minusXStep(x, path);
				}
			}

			else if (direction == "S"){
				if (turn == "R"){
					direction = "W";
					x = minusXStep(x, path);
				}
				else{
					direction = "E";
					x = addXStep(x, path);
				}
			}

			else if (direction == "E"){
				if (turn == "R"){
					direction = "S";
					y = minusYStep(y, path);
				}
				else{
					direction = "N";
					y = addYStep(y, path);
				}
			}

			else if (direction == "W"){
				if (turn == "R"){
					direction = "N";
					y = addYStep(y, path);
				}
				else{
					direction = "S";
					y = minusYStep(y, path);
				}
			}
		}
	}

	cout << x << "," << y << endl;

	system("pause");
	exit(-1);

	//Part 1:  301

}

double addXStep(double startSteps, double pathSteps){
	double finalSteps = 0;
	for (int j = 0; j < pathSteps; j++){
		startSteps = startSteps + 1;
	}

	finalSteps = startSteps;
	return finalSteps;
}

double minusXStep(double startSteps, double pathSteps){
	double finalSteps = 0;
	for (int j = 0; j < pathSteps; j++){
		startSteps = startSteps - 1;
	}

	finalSteps = startSteps;
	return finalSteps;
}

double addYStep(double startSteps, double pathSteps){
	double finalSteps = 0;
	for (int j = 0; j < pathSteps; j++){
		startSteps = startSteps + 1;
	}

	finalSteps = startSteps;
	return finalSteps;
}

double minusYStep(double startSteps, double pathSteps){
	double finalSteps = 0;
	for (int j = 0; j < pathSteps; j++){
		startSteps = startSteps - 1;
	}

	finalSteps = startSteps;
	return finalSteps;
}







