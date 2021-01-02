#include <iostream>
#include <fstream>
#include <string>
#include "md5wrapper.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main(){
	md5wrapper md5;
	string input = "";
	string hash = "";
	int start = 0;
	bool found = false;

	input = "bgvyzdsv";
	//input = "abcdef"; //test input

	//start = 609043;

	while (!found){
		input = input + to_string(start);
		//cout << input << endl;
		hash = md5.getHashFromString(input);
		if(hash.substr(0,6) == "000000"){
			found = true;
		}

		start++;
		input = "bgvyzdsv";
	}

	if(found){
		cout << start - 1 << endl;
		cout << hash << endl;
	}


	system("pause");
	exit(-1);

	//Part 01:  254575
 	//Part 02:  1038736


}
