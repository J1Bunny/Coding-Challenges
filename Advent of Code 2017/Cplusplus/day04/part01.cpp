#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
	string fileString;
	ifstream inputFile;
	string line;
	int strLength;
	string list[9999];
	int i;
	int j;
	int step;
	string numberChar;
	int max;
	string blank = " ";
	int pos;
	string tempString;
	int valid;
	int error;

	fileString = "C:/advent/input.txt";
	//fileString = "C:/advent/testdata.txt";

	ifstream fileName(fileString);
	i = 0;
	step = 0;
	valid = 0;
	error = 0;

	while (!fileName.eof()){
		error = 0;
		pos = 99;
		tempString = "";
		getline(fileName, line);
		step = 0;
		max = 0;
		//cout << line << endl;

		while (pos > 0){
			strLength = line.length();
			//cout << line << endl;
			pos = line.find(" ");
			tempString = line.substr(0, pos);
			line = line.substr(pos + 1, strLength - pos - 1);
			list[step] = tempString;
			step++;
		}
		//system("pause");

		max = step;
		for (i = 0; i < max; i++){
			tempString = list[i];
			for (j = i + 1; j < max; j++){
				if (strcmp(tempString.c_str(), list[j].c_str()) == 0){
					error = 1;
				}
			}
		}

		if (error == 0){
			valid++;
		}
	}

	fileName.close();

	cout << "valid " << valid << endl;

	system("pause");
	exit(-1);

	//Part 1:   337
	//Part 2:  
}
