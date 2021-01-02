#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	string first[50] = {};
	string last[50] = {};
	string tempString;
	string solutions[662] = {};
	string part;
	string part2;
	string possible;
	string formula;
	bool found;
	int final;
	int i;
	int k;
	int firstChar;
	int lastChar;
	int fullLength;
	int molLength;
	int count;


	fileString = "C:/advent/input.txt";
	//fileString = "C:/advent/testdata.txt";

	count = 0;
	k = 0;
	i = 0;
	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		last[i] = fileString;
		inputFile >> fileString;
		inputFile >> fileString;
		first[i] = fileString;
		i++;
	}

	formula = first[i - 1];
	final = i - 1;

	for (int j = 0; j<final - 1; j++){
		for (int i = 0; i < final - j - 1; i++){
			if (first[i].length() <= first[i + 1].length()){
				tempString = first[i];
				first[i] = first[i + 1];
				first[i + 1] = tempString;

				tempString = last[i];
				last[i] = last[i + 1];
				last[i + 1] = tempString;
			}
		}
	}

	fullLength = formula.length();
	bool goon;
	goon = true;

	while (goon){
		for (int i = 0; i < final; i++){
			//cout << "formula " << formula << endl;
			fullLength = formula.length();
			molLength = first[i].length();
			for (int j = 0; j - 1 < fullLength - molLength; j++){
				if (formula.substr(j, molLength).compare(first[i]) == 0){

					count++;
					//cout << endl;
					//cout << formula.substr(0, j) << "." << last[i] << "." << formula.substr(j + molLength, fullLength - (molLength));
					formula = formula.substr(0, j) + last[i] + formula.substr(j + molLength, fullLength - (molLength));

					//cout << endl;
					//cout << "new long " << formula << endl;
					//system("pause");
					j = 999;
					i = 999;
					if (formula.compare("e") == 0){
						goon = false;
					}
				}

			}

		}
	}


	cout << endl << "total " << count << endl;

	system("pause");
	exit(-1);

	//Part 01:  535
	//Part 02:  212

}
