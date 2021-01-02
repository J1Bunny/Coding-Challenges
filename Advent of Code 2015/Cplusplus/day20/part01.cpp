#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	//int input = 100;
	int input = 29000000;
	int house = 750000;
	int value = 0;
	int lowHouse = 0;
	//input = input / 10;

	while(house <= 750000){
		value = 0;
		for (int i = 1; i < house+1; i++){
			if(house % i == 0){
				value = value + (i*10);
			}
		}
		if(house % 1000 == 0){
			cout << "h " << house << endl;
		}

		if(value >= input){
			cout << house << endl;
			lowHouse = house;
		}
		house = house -10;
	}

	cout << lowHouse << endl;

	system("pause");
	exit(-1);

	//Part 01:  665280
	//Part 02:  
}
