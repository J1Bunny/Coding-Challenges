#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	double strLength = 0;
	int vowels = 0;
	bool doubleLetter = false;
	bool isNice = false;
	string first = "";
	string second = "";
	int totalNice = 0;

	fileString = "C:/advent/2015/day05_input.txt";
	//fileString="C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		vowels = 0;
		doubleLetter = false;
		inputFile >> fileString;
		strLength = fileString.length();
		isNice = false;

		for(int i = 0; i < strLength - 1; i++){
			first = fileString.substr(i,1);
			second = fileString.substr(i+1,1);

			if (first.compare(second) == 0){
				isNice = true;
			}
		}

		if(isNice){
			for(int i = 0; i < strLength - 1; i++){
				first = fileString.substr(i,1);
				second = fileString.substr(i+1,1);

				if((first + second).compare("ab") == 0){
					isNice = false;
				}
				else if((first + second).compare("cd") == 0){
					isNice = false;
				}
				else if((first + second).compare("pq") == 0){
					isNice = false;
				}
				else if((first + second).compare("xy") == 0){
					isNice = false;
				}
			}
		}

		if(isNice){
			for(int i = 0; i < strLength; i++){
				first = fileString.substr(i,1);
				if (first.compare("a") == 0){
					vowels = vowels ++;
				}
				else if (first.compare("e") == 0){
					vowels = vowels ++;
				}
				else if (first.compare("i") == 0){
					vowels = vowels ++;
				}
				else if (first.compare("o") == 0){
					vowels = vowels ++;
				}
				else if (first.compare("u") == 0){
					vowels = vowels ++;
				}
			}

			if(vowels < 3){
				isNice = false;
			}
		}

		if(isNice){
			totalNice ++;
		}
	}

	cout << totalNice << endl;
	system("pause");
	exit(-1);

	//Part 01:  255
	//Part 02:  
}
