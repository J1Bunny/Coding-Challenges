#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string input = "";
	string newInput = "";
	int strLength = 0;
	string character = "";
	int count = 0;

	input = "1113122113";
	//input = "11"; //test input
	newInput = input;

	for(int i = 0; i < 40; i++){
		cout << i << endl;
		input = newInput;
		newInput = "";
		//cout << "input " << endl;
		strLength = input.length();
		for(int k = 0; k < strLength; k++){
			character = input.substr(k,1);
			count = 1;
			while (character.compare(input.substr(k+1,1)) == 0){
				count = count+1;
				k++;
				//cout << "k=" << k << "count= " << count << endl;
			}
			newInput = newInput + to_string(count) + character;
		}
		//cout << newInput << endl;
	}

	//cout << "new " << newInput << endl;
	cout << newInput.length() << endl;

	system("pause");
	exit(-1);

	//Part 01:  360154
	//Part 02:  


}
