#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "md5wrapper.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main(){
	md5wrapper md5;
	string input = "";
	string hash = "";
	int start = 1776000;
	bool found = false;
	int count = 0;
	int max = 0;
	int spots[9] = {};
	int location = 0;

	input = "ugkcyxxp";
	cout << input << endl;
	//input = "abcdef"; //test input

	while(count < 15){
		input = input + to_string(start);
		hash = md5.getHashFromString(input);
		string special = hash.substr(0,5);
			char maybe = hash[5];
			if(special == "00000" && (int(maybe)>=48 && int(maybe)<=55)){
			cout << count << " - " << maybe << " - " << hash << endl;
			cout << start << endl;
			//spots[count] = stoi(hash.substr(6,1));
			count ++;
			found = true;
		}

		start++;
		input = "ugkcyxxp";
	}

	system("pause");
	exit(-1);

	//Part 01:  d4cd2ee1
 	//Part 02:  f2c730e5
}
