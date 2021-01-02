#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	string name[10] = {};
	int fly[10] = {};
	int rest[10] = {};
	int max[10] = {};
	int inc[10] = {};
	int points[10] = {};
	int distance[10] = {};
	bool resting[10] = {};
	int winner = 0;
	int maxDist = 0;
	int second = 0;
	int deer = 0;

	for (int i = 0; i < 10; i++){
		name[i] = "";
		fly[i] = 0;
		rest[i] = 0;
		max[i] = 0;
		inc[i] = 0;
		points[i] = 0;
		resting[i] = false;
	}

	fileString = "C:/advent/2015/day14_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;

		if(name[deer].compare("") == 0){
			name[deer] = fileString;
		}

		if(fileString.compare("fly") == 0){
			inputFile >> fileString;
			fly[deer] = stoi(fileString);
			inputFile >> fileString;
			inputFile >> fileString;
			inputFile >> fileString;
			max[deer] = stoi(fileString);
			inc[deer] = stoi(fileString);
		}

		if(fileString.compare("rest") == 0){
			inputFile >> fileString;
			inputFile >> fileString;
			rest[deer] = stoi(fileString);
		}

		if(fileString.compare("seconds.") == 0){
			deer++;
		}
	}

	/*
	for (int i = 0; i < 9; i++){
	cout << "." << name[i];
	cout << "." <<fly[i];
	cout << "." <<rest[i];
	cout << "." <<max[i];
	cout << "." <<inc[i];
	cout << endl;
	}
	*/

	for(int seconds = 0; seconds < 2503; seconds++){
		for(int i = 0; i < 9; i++){
			if(!resting[i]){
				distance[i] = distance[i] + fly[i];
				inc[i]--;
				if(inc[i]==0){
					inc[i] = rest[i];
					resting[i] = true;
				}
			}
			else{
				inc[i]--;
				if(inc[i]==0){
					inc[i] = max[i];
					resting[i] = false;
				}
			}
		}
		maxDist = 0;
		for (int i = 0; i < 9; i++){
			if(distance[i] > maxDist){
				maxDist = distance[i];
				winner = i;
			}
		}
		points[winner]++;
		//for (int i = 0; i < 2; i++){
		//	cout << name[i] << " " << points[i] << endl;
		//}
		//system("pause");
	}

	for (int i = 0; i < 9; i++){
		cout << name[i] << " " << points[i] << endl;
	}

	system("pause");
	exit(-1);

	//Part 01:  2696
	//Part 02:  1084
}
