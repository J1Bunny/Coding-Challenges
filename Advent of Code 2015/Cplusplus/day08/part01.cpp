#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	int memCount = 0;
	int charCount = 0;
	int stringCount = 0;

	fileString = "C:/advent/2015/day08_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		strLength = fileString.length();
		cout << fileString << " ";
		memCount = memCount + strLength;
		stringCount = 0;
		for(int i = 0; i < strLength; i++){
			if(i > 0 && i < strLength){
			char first = fileString[i];
			if (first>=97 && first <=122){
				stringCount = stringCount + 1;
			}
			else if(first == 92){
				stringCount = stringCount + 1;
				if(fileString[i+1] == 120){
					i = i+3;
				}
				else if(fileString[i+1] == 92){
					i ++;
				}
				else if(fileString[i+1] == 34){
					i ++;
				}
			}
		}
	}
				charCount = charCount + stringCount;
		cout << stringCount << endl;
}

	cout << endl << endl;
	cout << "memory " << memCount  << endl;
	cout << "char " << charCount << endl;
	cout << "total " << memCount - charCount << endl;

	system("pause");
	exit(-1);

	//Part 01:  1333
	//Part 02:  
}
