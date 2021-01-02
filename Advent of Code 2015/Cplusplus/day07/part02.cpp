#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;

	string command = "";
	string list[999] = {};
	int listStep = 0;
	string wires[9999];
	unsigned short int values[9999];
	int search = -1;
	int space = 0;
	int strLength = 0;
	int andFound = 0;
	int notFound = 0;
	int orFound = 0;
	int lFound = 0;
	int rFound = 0;
	int doneFound = 0;
	int max = 0;
	bool found = false;
	int location = 0;
	string temp = "";
	int count = 0;
	bool isFixed = false;
	int trueOne = 0;

	string binOp = "";

	for (int i = 0; i < 9999; i++){
		wires[i] = "";
	}

	wires[0] = "a";
	values[0] = 0;
	max = 1;

	fileString = "C:/advent/2015/day07_input.txt";
	//fileString = "C:/advent/2015/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;
		command.append(fileString + " ");
		char item = fileString[0];
		if (item == 45){
			inputFile >> fileString;
			command.append(fileString);
			list[listStep] = command;
			listStep++;
			command = "";
		}
	}

	for (int i = 0; i < listStep; i++){
		command = list[i];
		strLength = command.length();
		if(!isFixed){
			string tempString = command.substr(strLength -2, 2);
			if(tempString.compare(" b") == 0){
				cout << list[i] << endl;
				list[i] = "956 -> b";
				cout << "look " << list[i] << endl;
				isFixed = true;
			}
		}
	}

	//while(values[0] == 0){
		while(count < 30){
		//	cout << "a: " << values[0] << endl;
		//	cout << "?: " << values[10] << endl;
		for (int i = 0; i < listStep; i++){
			//cout << list[i] << " ";
			command = list[i];
			strLength = command.length();
			found = false;

			andFound = command.find("AND");
			notFound = command.find("NOT");
			orFound = command.find("OR");
			lFound = command.find("LSHIFT");
			rFound = command.find("RSHIFT");
			doneFound = command.find("DONE");

			if (andFound > -1){
				binOp = "AND";

				int firstValue = -1;
				int secondValue = -1;
				int lastValue = -1;

				space = command.find(" ");
				string first = command.substr(0, space);
				temp = command.substr(space+1,strLength - space);
				space = temp.find(" ");
				strLength = temp.length();
				temp = temp.substr(space+1,strLength - space);
				space = temp.find(" ");
				strLength = temp.length();
				string second = temp.substr(0, space);
				space = temp.find(">");
				string last = temp.substr(space+2, strLength - space);
				//cout << first << "." << second << "." << last << "." << endl;

				if(first == "1"){
					firstValue = 1;
				}
				else{

					for (int k = 0; k < max; k++){
						if (wires[k].compare(first) == 0){
							found = true;
							location = k;
						}
					}
					if (found){
						firstValue = values[location];
						//cout << "first" << firstValue << endl;
					}
				}


				for (int k = 0; k < max; k++){
					if (wires[k].compare(second) == 0){
						found = true;
						location = k;
					}
				}
				if (found){
					secondValue = values[location];
					//cout << "first" << firstValue << endl;
				}

				if(firstValue>-1 && secondValue>-1){
					values[max] = (firstValue&secondValue);
					wires[max] = last;
					max++;
					list[listStep] = "DONE";
				}



			}
			else if (notFound > -1){
				binOp = "NOT";
				int firstValue = -1;
				int lastValue = -1;

				space = command.find(">");
				string first = command.substr(4, space - 6);
				temp = command.substr(5,strLength - 4);
				strLength = temp.length();
				space = temp.find(">");
				temp = temp.substr(space, strLength - space);
				string last = temp.substr(2, strLength - space);
				//cout << "not ." << first << "." << last << "." << endl;

				//get values of beginning variable
				for (int k = 0; k < max; k++){
					if (wires[k].compare(first) == 0){
						found = true;
						location = k;
					}
				}
				if (found){
					firstValue = values[location];
					//cout << "first" << firstValue << endl;
				}
				if(firstValue>-1){
					values[max] = ~firstValue;
					wires[max] = last;
					max++;
					list[listStep] = "DONE";
				}

			}
			else if (orFound > -1){
				binOp = "OR";

				int firstValue = -1;
				int secondValue = -1;
				int lastValue = -1;

				space = command.find(" ");
				string first = command.substr(0, space);
				temp = command.substr(space+1,strLength - space);
				space = temp.find(" ");
				strLength = temp.length();
				temp = temp.substr(space+1,strLength - space);
				space = temp.find(" ");
				strLength = temp.length();
				string second = temp.substr(0, space);
				space = temp.find(">");
				string last = temp.substr(space+2, strLength - space);
				//cout << first << "." << second << "." << last << "." << endl;

				for (int k = 0; k < max; k++){
					if (wires[k].compare(first) == 0){
						found = true;
						location = k;
					}
				}
				if (found){
					firstValue = values[location];
					//cout << "first" << firstValue << endl;
				}

				for (int k = 0; k < max; k++){
					if (wires[k].compare(second) == 0){
						found = true;
						location = k;
					}
				}
				if (found){
					secondValue = values[location];
					//cout << "first" << firstValue << endl;
				}

				if(firstValue>-1 && secondValue>-1){
					values[max] = (firstValue|secondValue);
					wires[max] = last;
					max++;
					list[listStep] = "DONE";
				}

			}
			else if (lFound > -1){
				binOp = "LSHIFT";

				int firstValue = -1;
				int secondValue = -1;
				int lastValue = -1;

				space = command.find(" ");
				string first = command.substr(0, space);
				temp = command.substr(space+1,strLength - space);
				space = temp.find(" ");
				strLength = temp.length();
				temp = temp.substr(space+1,strLength - space);
				space = temp.find(" ");
				strLength = temp.length();
				string second = temp.substr(0, space);
				space = temp.find(">");
				string last = temp.substr(space+2, strLength - space);
				//cout << first << "." << second << "." << last << "." << endl;


				for (int k = 0; k < max; k++){
					if (wires[k].compare(first) == 0){
						found = true;
						location = k;
					}
				}
				if (found){
					firstValue = values[location];
					//cout << "first" << firstValue << endl;
				}

				secondValue = stoi(second);

				//cout << firstValue << " " << secondValue << endl;
				if(firstValue>-1 && secondValue>-1){
					values[max] = (firstValue<<secondValue);
					wires[max] = last;
					max++;
					list[listStep] = "DONE";
				}

			}
			else if (rFound > -1){
				binOp = "RSHIFT";

				int firstValue = -1;
				int secondValue = -1;
				int lastValue = -1;

				space = command.find(" ");
				string first = command.substr(0, space);
				temp = command.substr(space+1,strLength - space);
				space = temp.find(" ");
				strLength = temp.length();
				temp = temp.substr(space+1,strLength - space);
				space = temp.find(" ");
				strLength = temp.length();
				string second = temp.substr(0, space);
				space = temp.find(">");
				string last = temp.substr(space+2, strLength - space);
				//cout << first << "." << second << "." << last << "." << endl;

				for (int k = 0; k < max; k++){
					if (wires[k].compare(first) == 0){
						found = true;
						location = k;
					}
				}
				if (found){
					firstValue = values[location];
					//cout << "first" << firstValue << endl;
				}

				secondValue = stoi(second);
				//cout << firstValue << " " << secondValue << endl;
				if(firstValue>-1 && secondValue>-1){
					values[max] = (firstValue>>secondValue);
					wires[max] = last;
					max++;
					list[listStep] = "DONE";
				}



			}
			else if(doneFound > -1){
			}
			else{
				binOp = "MOVE";
				int firstValue = -1;
				space = command.find(" ");
				string first = command.substr(0, space);
				space = command.find(">");
				string last = command.substr(space + 2, strLength - (space + 2));
				//cout << first << endl << last << "." << endl;

				//if not a number
				char firstOne = first[0];
				if (firstOne > 57){
					for (int k = 0; k < max; k++){
						if (wires[k].compare(first) == 0){
							found = true;
							location = k;
						}
					}
					if (found){
						firstValue = values[location];
						if(firstValue > -1){
							values[max] = firstValue;
							wires[max] = last;
							max++;
							list[listStep] = "DONE";
							
							if(last.compare("a") == 0 && firstValue>-1){
								cout << "a: " << firstValue << endl;
								system("pause");

							}
							
							//cout << "first" << firstValue << endl;
						}
					}

				}
				else{
					values[max] = stoi(first);
					wires[max] = last;
					max++;
					list[listStep] = "DONE";
				}
			}
			//cout << binOp << endl;

		}
		count++;
		cout << "count: " << count << endl;
	}

	/*
	for (int i = 0; i < max; i++){
		cout << endl << i << " " << values[i] << " " << wires[i];
	}
	*/

	cout << endl <<endl << values[0] << endl;

	cout << endl  << endl;

	system("pause");
	exit(-1);

	//Part 01:  956
	//Part 02:  40149
}
