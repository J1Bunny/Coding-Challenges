//not yet working

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	int charCount = 0;
	int totalCount = 0;
	string newString = "";
	string tempString = "";
	bool flag = false;
	char step = 'a';
	int space = 0;
	int letters = 0;
	int repeat = 0;
	int xSpot = 0;

	fileString = "C:/advent/day09_input.txt";
	//fileString = "C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		cout << endl;
		inputFile >> fileString;
		cout << fileString << endl;
		strLength = fileString.length();
		newString = "";

		while(strLength>0){
			step = fileString[0];
			if(step!=40){
				newString.append(fileString.substr(0,1));
				//cout << newString << endl;
				fileString = fileString.substr(1,strLength - 1);
				strLength = fileString.length();
				//cout << strLength << endl;
			}
			else{
				space = fileString.find(")");
				tempString = fileString.substr(1,space - 1);
				fileString = fileString.substr(space+1, strLength -(space + 1));
				strLength = fileString.length();
				xSpot = tempString.find("x");
				letters = stoi(tempString.substr(0,xSpot));
				repeat = stoi(tempString.substr(xSpot+1,tempString.length() - xSpot));

				tempString = fileString.substr(0,letters);
				for(int j = 0; j < repeat; j++){
					newString.append(tempString);
				}

				fileString = fileString.substr(letters, strLength - letters);
				strLength = fileString.length();
			}
		}

		cout << "new " << newString << endl;
		totalCount = totalCount + newString.length();
	}

	cout << endl << totalCount << endl;

	system("pause");
	exit(-1);

	//Part 01:  123908
	//Part 02:  

}
