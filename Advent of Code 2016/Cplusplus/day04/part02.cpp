#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	int stringLength = 0;
	int letterCount [27] = {};
	int sectorID = 0;
	char charLetter;
	int startID = 0;
	int endID = 0;
	string sector = "";
	string checksum = "";
	bool startFound = false;
	int totalChars = 0;
	int max = 0;
	bool isReal = false;
	int step = 0;
	char actual = 'a';
	int totalSector = 0;
	int finalAnswer = 0;
	string newString = "";
	int intOfLetter = 0;


	fileString = "C:/advent/day04_input.txt";
	//fileString="C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		//cout << fileString << endl;
		stringLength = fileString.length();
		sector = "";
		sectorID = 0;
		startFound = false;
		checksum = "";
		totalChars = 0;

		for (int i = 0; i < 27; i ++){
			letterCount[i] = 0;
		}

		for (int i = 0; i < stringLength; i++){
			charLetter = fileString[i];

			if (int(charLetter)==91){
				startFound=true;
			}

			//add letter count to array
			if (startFound == false){
				if (int(charLetter)>=97 && int(charLetter)<=122){
					letterCount[int(charLetter)-96]=letterCount[int(charLetter)-96]+1;
				}
			}
			else{
				if (int(charLetter)>=97 && int(charLetter)<=122){
					checksum.append(1,charLetter);
				}
			}

			if (int(charLetter)>=48 && int(charLetter)<=57){
				sector.append(1,charLetter);
				sectorID = stoi(sector);
			}

			//cout << int(charLetter) << endl;


		}

		max = 0;
		step = 0;
		isReal = true;
		newString = "";


		for (int j = 1; j < 27; j++){
			if (letterCount[j] > max){
				max = letterCount[j];
			}
		}

		while (isReal == true && step < 5 && max > 0){
			for (int i = 0; i < 27; i ++){
				if(letterCount[i] == max && step < 5){
					actual = char (i + 96);
					if (actual == checksum[step]){
						//cout << actual << " " << checksum[step] << endl;
						//cout << isReal << endl;
						step ++;
					}
					else{
						isReal = false;
						step = 5;
						i = 27;
					}
				}
			}
			max --;
		}

		if (isReal){
			finalAnswer = sectorID;
			while (finalAnswer > 26){
				finalAnswer = finalAnswer - 26;
			}
			//cout << finalAnswer << endl;
			for (int i = 0; i < stringLength; i++){
				charLetter = fileString[i];
				if (int(charLetter)>=97 && int(charLetter)<=122){
					intOfLetter = int(charLetter);
					for (int q = 1; q <= finalAnswer; q ++){
						intOfLetter++;
						if (intOfLetter == 123){
							intOfLetter = 97;
						}
					}
					//cout << intOfLetter << " ";
				}
				else{
					intOfLetter = 32;
				}

				char newLetter = intOfLetter;
				newString.append(1,newLetter);

			}
			//cout << endl << newString << endl;
			int found = -1;
			found = newString.find("north");
			if(found >= 0){
        cout << fileString << endl;
				cout << newString << endl;
			}

			totalSector = totalSector + sectorID;
		}
	}


	//cout << totalSector << endl;
	cout << endl << endl;
	system("pause");
	exit(-1);

	//Part 1:  409147
	//Part 2:  991
}

