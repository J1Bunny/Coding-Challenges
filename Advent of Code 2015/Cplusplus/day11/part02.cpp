#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string original;
	int letters[8] = {};
	bool goodPassword=false;
	int last = 0;
	bool triFound=false;
	bool noI = false;
	bool match = false;

	original = "hepxcrrq";
	//original = "hepxxyzz";

	for(int i = 0; i<original.length(); i++){
		letters[i] = original[i];
		cout << letters[i] << endl;
	}

	while (!goodPassword){
		letters[7]++;
		triFound=false;
		noI = true;
		match = false;

	  for(int i = 0; i < 8; i++){
			if(letters[i] == 105 || letters[i] == 108 || letters[i] == 111){
				noI=false;
			}
		}

		for(int i = 0; i < 5; i++){
			if(letters[i]+1 == letters[i+1] && letters[i+1]+1 == letters[i+2]){
				triFound=true;
			}
		}

		for(int i = 7; i >0; i--){
			if(letters[i] == letters[i-1]){
				for(int j = 7; j>0; j--){
					if(letters[j] == letters[j-1] && letters[j] != letters[i]){
						match=true;
					}
				}
			}
		}


		if (triFound == true){
			if(noI == true){
				if(match == true){
					for(int k = 0; k< 8; k++){
						cout << (char)letters[k];
					}
					cout << endl;
					system("pause");
				}
			}
		}

		if(letters[7]==122){
			letters[7]=96;
			letters[6]++;

			for(int i = 6; i > -1; i --){
				if(letters[i]==122){
					letters[i]=97;
					letters[i-1]++;
				}
			}
		}
	}

	system("pause");
	exit(-1);

	//Part 01: hepxxyzz
	//Part 02: heqaabcc
}


