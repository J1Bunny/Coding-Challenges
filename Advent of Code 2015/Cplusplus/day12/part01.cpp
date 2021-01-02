#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	int total = 0;
	string tempNum = "";
	bool subtract = false;

	fileString = "C:/advent/2015/day12_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		strLength = fileString.length();
	}

	//cout << "len " << strLength << endl;

	for(int i = 0; i < strLength; i++){
		char step = fileString[i];
		//cout << step << endl;

		if(fileString[i] == 45){
			subtract = true;
			for(int k = i+1; k < strLength; k++){
				char step = fileString[k];
				if(step>=48 && step<=57){
					tempNum.append(fileString.substr(k,1));
				}
				else{
					i = k;
					k = strLength;

					if(tempNum.length()>0){
						//cout << "temp " <<tempNum << endl;
						total = total - stoi(tempNum);
						//cout << "total " << total << endl;
						//system("pause");
						tempNum = "";
						subtract = false;
					}
				}
			}
		}

		if(step>=48 && step<=57){
			tempNum.append(fileString.substr(i,1));
		}
		else{
			if(tempNum.length()>0){
						total = total + stoi(tempNum);
				tempNum = "";
			}
		}
	}

	if(tempNum.length()>0){
		if(subtract){
			total = total - stoi(tempNum);
		}
		else{
			total = total + stoi(tempNum);
		}

		tempNum = "";
	}

	cout << total  << endl;

	system("pause");
	exit(-1);

	//Part 01:  111754
	//Part 02:  
}
