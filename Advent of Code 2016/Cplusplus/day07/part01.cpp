#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	bool badFlag = false;
	int count = 0;
	string set = "";
	bool goodFound = false;

	fileString = "C:/advent/day07_input.txt";
	//fileString = "C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		strLength = fileString.length();
		cout << fileString << " ";
		goodFound = false;
		for (int i = 0; i < strLength - 3; i++){
			char step1 = fileString[i];
			//cout << goodFound << endl;

			if(!badFlag && step1 == 91){ 
				badFlag = true;
			}
			else if(badFlag && step1 == 93){
				badFlag = false;
			}
			else{
				char step2 = fileString[i+1];
				char step3 = fileString[i+2];
				char step4 = fileString[i+3];
			
				if (!badFlag){
					if (step1 == step4 && step2 == step3 && step1 != step2){
						goodFound = true;
					}
				}
				if (badFlag){
					if (step1 == step4 && step2 == step3){
						i = strLength - 4;
						badFlag = false;
						goodFound=false;
					}
				}
			}

			//cout << badFlag;
					
		}
		cout << endl;
		if(goodFound){
			count ++;
		}
	}

	cout << count << endl;
	cout << endl << endl;
	system("pause");
	exit(-1);

	//Part 1:  110
	//Part 2:  
}




