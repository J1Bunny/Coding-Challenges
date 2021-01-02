#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	double strLength = 0;
  bool match = false;
	bool isNice = false;
	string first = "";
	string second = "";
	int totalNice = 0;

	fileString = "C:/advent/2015/day05_input.txt";
	//fileString="C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		strLength = fileString.length();
		isNice = false;

		for(int i = 0; i < strLength - 1; i++){
			first = fileString.substr(i,2);

			for (int j = i +2; j < strLength; j++){
				second = fileString.substr(j,2);
				if (first.compare(second) == 0){
					isNice = true;
				}
			}
		}


		if(isNice){
			match = false;
			for(int i = 0; i < strLength - 1; i++){
				first = fileString.substr(i,1);
				second = fileString.substr(i+2,1);
				if (first.compare(second) == 0){
					match = true;
					//cout << first << " " << second << " " << match << endl;
				}
			}
		}

		if (match == false){
			isNice = false;
		}

		if(isNice){
			totalNice ++;
		}

		//cout << fileString << " " << isNice << endl;
	}

	cout << totalNice << endl;
	system("pause");
	exit(-1);

	//Part 01:  255
	//Part 02:  55
}
