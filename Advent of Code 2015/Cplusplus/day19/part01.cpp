#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	string first[50] = {};
	string last[50] = {};
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
		first[i] = fileString;
		inputFile >> fileString;
		inputFile >> fileString;
		last[i] = fileString;
		i++;
	}

	formula = last[i-1];

	final = i - 1;

	fullLength = formula.length();
	firstChar = 0;
	lastChar = 1;

	while (firstChar+lastChar <= fullLength){
		for (int j = 0; j < final; j++){
			part = formula.substr(firstChar, lastChar);
			part2 = formula.substr(firstChar, lastChar+1);
			if (part.compare(first[j]) == 0){
				possible = formula.substr(0, firstChar) + last[j] + formula.substr(lastChar + firstChar, fullLength - lastChar);
				//cout << possible << endl;
				if (k > 0){
					found = false;
					for (int q = 0; q < k; q++){
						//cout << q << " " << possible << "." << solutions[q] << "." << endl;
						if (possible.compare(solutions[q]) == 0){
							//cout << found << endl;
							found = true;
						}
					}
					if (!found){
						solutions[k] = possible;
						k++;
					}
					//cout << endl;
				}
				else {
					//cout << possible << " " << solutions[k] << endl;
					solutions[k] = possible;
					k++;
				}
			}

			else if (part2.compare(first[j]) == 0){
				lastChar++;
				possible = formula.substr(0, firstChar) + last[j] + formula.substr(lastChar + firstChar, fullLength - (lastChar));
				if (k > 0){
					found = false;
					for (int q = 0; q < k; q++){
						//cout << q << " " << possible << "." << solutions[q] << "." << endl;
						if (possible.compare(solutions[q]) == 0){
							//cout << found << endl;
							found = true;
						}
					}
					if (!found){
						solutions[k] = possible;
						k++;
					}
					//cout << endl;
				}
				else {
					//cout << possible << " " << solutions[k] << endl;
					solutions[k] = possible;
					k++;
				}
			}


		}

		firstChar = firstChar + lastChar;
		lastChar = 1;
	}


	ofstream myfile;
	myfile.open ("example.txt");

	for (int j = 0; j < k; j++){
		cout << j << " " << solutions[j] << endl;
	}

	myfile.close();
	cout << endl << "final " << k << endl;


	system("pause");
	exit(-1);

	//Part 01:  535
	//Part 02: 

}
