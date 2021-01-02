#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	string items[10] = {};
	int numbers[10] = {};
	string current = "";
	string winner = "";
	string potential[505] = {};
	int step = 0;
	int strLength = 0;
	int count = 0;
	int found = -1;
	bool match = true;
	string currentItem = "";

	items[0] = "children:";
	items[1] = "cats:"; 
	items[2] = "samoyeds:"; 
	items[3] = "pomeranians:"; 
	items[4] = "akitas:"; 
	items[5] = "vizslas:"; 
	items[6] = "goldfish:"; 
	items[7] = "trees:"; 
	items[8] = "cars:"; 
	items[9] = "perfumes:"; 

	numbers[0]=3;
	numbers[1]=7;
	numbers[2]=2;
	numbers[3]=3;
	numbers[4]=0;
	numbers[5]=0;
	numbers[6]=5;
	numbers[7]=3;
	numbers[8]=2;
	numbers[9]=1;

	fileString = "C:/advent/2015/day16_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;

		if(fileString.compare("Sue")==0){
			if(!match){
				potential[step] = "BAD";
			}
			match = true;
			inputFile >> fileString;
			current = fileString;
			step++;
		} 

		for(int i = 0; i < 10; i++){
			if(items[i].compare(fileString)==0){
				currentItem = fileString;
				inputFile >> fileString;
				strLength = fileString.length();
				if(fileString.substr(strLength,1).compare(",")==0){
					count = stoi(fileString.substr(0,strLength - 1));
				}
				else{
					count = stoi(fileString);
				}

				if((currentItem.compare("cats:") == 0) || (currentItem.compare("trees:") == 0)){
					if(numbers[i] < count){
						potential[step].append(current);
						cout << current << endl;
						//system("pause");
					}
					else{
						match = false;
					}
				}
				else if((currentItem.compare("pomeranians:") == 0) || (currentItem.compare("goldfish:") == 0)){
					if(numbers[i] > count){
						potential[step].append(current);
						cout << current << endl;
						//system("pause");
					}
					else{
						match = false;
					}
				}
				else if(numbers[i] == count){
					potential[step].append(current);
					//cout << current << endl;
				}
				else{
					potential[step].append("N");
					match = false;
					//cout << "Not" << endl;
				}
			}
		}
	}

	for(step = 0;step < 500; step++){
		if(potential[step].compare("BAD") !=0){
			cout << step << " " << potential[step] << endl;
		}
	}

	system("pause");
	exit(-1);

	//Part 01:  103
	//Part 02:  405
}


