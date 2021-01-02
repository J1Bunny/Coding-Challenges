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
	int count = 0;

	input = "ugkcyxxp";
	cout << input << endl;
	//input = "abcdef"; //test input

	while (count < 8){
		input = input + to_string(start);
		hash = md5.getHashFromString(input);
		if(hash.substr(0,5) == "00000"){
			cout << hash << endl;
			count ++;
		}

		start++;
		input = "ugkcyxxp";
	}

	system("pause");
	exit(-1);

	//Part 01:  d4cd2ee1
 	//Part 02:  


}
