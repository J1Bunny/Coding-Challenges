#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	//int input = 100;
	int input = 29000000;
	int house = 7500000;
	int value = 0;
	int lowHouse = 0;
	//input = input / 10;

	while(house > 699999){
		value = 0;
		for (int i = 1; i < house+1; i++){
				if(house % i == 0 && house / i < 51){
					value = value + (i*11);
			}
		}
		
		if(value >= input){
			cout << house << endl;
			lowHouse = house;
			system("pause");
		}
		house--;
	}

	cout << lowHouse << endl;

	system("pause");
	exit(-1);

	//Part 01:  665280
	//Part 02:  705600
}
