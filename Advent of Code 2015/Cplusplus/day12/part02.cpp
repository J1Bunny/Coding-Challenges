#include <iostream>
#include <fstream>
#include <string>
#include "json/json.h"

using namespace std;
int calculateTotal(Json::Value newObj);

int total = 0;

int main(){
	string fileString;
	ifstream inputFile;
	int strLength = 0;
	string tempNum = "";

	fileString = "C:/advent/2015/day12_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	ifstream ifs(fileString);
	Json::Reader reader;
	Json::Value obj;
	reader.parse(ifs,obj);
	int next = calculateTotal(obj);

	cout << "Total: " << total << endl;

	system("pause");
	exit(-1);

	//Part 01:  111754
	//Part 02:  65402

	//38885 too low
}

int calculateTotal(Json::Value newObj){
	Json::Value checkObj = newObj;

	bool redFound = false;
	if (checkObj.isObject()){
		for(Json::Value::iterator it=checkObj.begin(); it!=checkObj.end(); ++it){
			if((*it).isString()){
				if((*it).compare("red") == 0){
					redFound = true;
				}
			}
		}
	}

	if(!redFound){
		for(Json::Value::iterator it=newObj.begin(); it!=newObj.end(); ++it){
			//cout << *it << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
			if((*it).isInt()){
				total = total + (*it).asInt();
				//cout << total << endl;
			}
			else{
				int next = calculateTotal(*it);
			}
		}
	}

	return 0;
}
