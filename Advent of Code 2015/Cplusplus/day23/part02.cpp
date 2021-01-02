#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	string instructions[50] = {};
	int step = -1;
	string strLine = "";
	int a = 1;
	int b = 0;
	string current = "";
	int strLength = 0;

	fileString = "C:/advent/2015/day23_input.txt";
	//fileString="C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		strLine = fileString;
		if((fileString.compare("hlf") == 0) || (fileString.compare("tpl") == 0) || 
			(fileString.compare("inc") == 0) || (fileString.compare("jmp") == 0)){
				step++;
				inputFile >> fileString;
				strLine.append(" " +fileString);
				instructions[step] = strLine;
		}
		else if((fileString.compare("jie") == 0) || (fileString.compare("jio") == 0)){
			step++;
			inputFile >> fileString;
			strLine.append(" " +fileString.substr(0,1));
			inputFile >> fileString;
			strLine.append(" " +fileString);
			instructions[step] = strLine;
		}
	}

	step++;

	for (int i = 0; i < step; i++){
		cout << instructions[i] << endl;
		current = instructions[i];
		strLength = current.length();

		if(current.substr(0,3).compare("hlf") == 0){
			a = a/2;
		}
		else if(current.substr(0,3).compare("tpl") == 0){
			a = a*3;
		}
		else if(current.substr(0,3).compare("jmp") == 0){
			if(current.substr(4,1).compare("+") == 0){
				i = i + stoi(current.substr(5,strLength-5)) - 1;
			}
			else{
				i = i - stoi(current.substr(5,strLength-5)) - 1;
			}
		}

		else if(current.substr(0,3).compare("jio") == 0){
			if(a==1){
				if(current.substr(6,1).compare("+") == 0){
					i = i + stoi(current.substr(7,strLength-7)) - 1;
				}
				else{
					i = i - stoi(current.substr(7,strLength-7)) - 1;
				}
			}
		}

		else if(current.substr(0,3).compare("jie") == 0){
			if(a % 2 ==0){
				if(current.substr(6,1).compare("+") == 0){
					i = i + stoi(current.substr(7,strLength-7)) - 1;
				}
				else{
					i = i - stoi(current.substr(7,strLength-7)) - 1;
				}
			}
		}

		else if(current.substr(0,3).compare("inc") == 0){
			if(current.substr(4,1).compare("a") == 0){
				a++;
			}
			else{
				b++;
			}
		}
		//cout << "A = " << a << endl;
		//cout << "B = " << b << endl;
	  //cout << "I = " << i << endl;
		//system("pause");
	}

	cout << "B= " << b << endl;

	system("pause");
	exit(-1);

	//Part 01:  184
	//Part 02:  231
}
