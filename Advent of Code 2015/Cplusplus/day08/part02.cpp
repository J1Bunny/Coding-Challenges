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
		stringCount = 2;
		for(int i = 0; i < strLength; i++){
			char first = fileString[i];
			if (first == 34){
				stringCount = stringCount +2;
			}
			else if(first == 92){
				stringCount = stringCount + 2;
			}
			else{
				stringCount++;
			}
		}
		charCount = charCount + stringCount;
		cout << stringCount << endl;
}

	cout << endl << endl;
	cout << "memory " << memCount  << endl;
	cout << "char " << charCount << endl;
	cout << "total " << charCount - memCount<< endl;

	system("pause");
	exit(-1);

	//Part 01:  1333
	//Part 02:  2046
}
