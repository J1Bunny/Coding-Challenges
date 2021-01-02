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
  char A1 = '1';
	char A2 = '1';
  bool matchFound = false;

	fileString = "C:/advent/day07_input.txt";
	//fileString = "C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		strLength = fileString.length();
		cout << fileString << " ";
		goodFound = false;
		matchFound = false;
		for (int i = 0; i < strLength - 2; i++){
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
			
				if (!badFlag){
					if (step1 == step3 && step2 != 91 && step2 != 93){
						A1 = step1;
						A2 = step2;

						cout << A1 << A2 << A1 << " ";

						for(int k = 0; k < strLength - 2; k++){
							char match1 = fileString[k];

							if(!badFlag && match1 == 91){ 
								badFlag = true;
							}
							else if(badFlag && match1 == 93){
								badFlag = false;
							}
							else{
								char match2 = fileString[k+1];
								char match3 = fileString[k+2];

								if (badFlag){
									if(match1 == A2 && match3 == A2 && match2 == A1){
										matchFound = true;
										cout << match1 << match2 << match3;
									}
								}
							}
						}
					}
				}
			}	
		}
		cout << endl;
		if(matchFound){
			count ++;
		}
	}

	cout << count << endl;
	cout << endl << endl;
	system("pause");
	exit(-1);

	//Part 1:  110
	//Part 2:  242
}
