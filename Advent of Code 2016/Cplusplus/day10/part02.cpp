#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileString;
	ifstream inputFile;
	string command = "";
	int bots[300][2] = {};
	int output[30][10] = {};
	int outputCount[30] = {};
	string commands[300] = {};
	int commandStep = 0;
	int space = 0;
	int strLength = 0;
	int value1 = 0;
	int value2 = 0;
	int bot1 = 0;
	int out = 0;
	string outBot = "";

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 300; j++){
			commands[j] = "";
			bots[j][i] = -1;
		}
	}

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 30; j++){
			outputCount[j] = 0;
			output[j][i] = -1;
		}
	}

	fileString = "C:/advent/day10_input.txt";
	//fileString = "C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);

	while (!inputFile.eof()){
		inputFile >> fileString;

		//cout << fileString << endl;
		command = fileString +" ";
		if (fileString.compare("value") == 0){
			inputFile >> fileString; //get value
			command.append(fileString + " "); //store value
			inputFile >> fileString; //goes
			inputFile >> fileString; //to
			inputFile >> fileString; //bot
			inputFile >> fileString; //bot num
			command.append(fileString); //store bot number
		}
		else{
			inputFile >> fileString; //bot number
			command = fileString +" ";
			inputFile >> fileString; //gives
			inputFile >> fileString; //low
			inputFile >> fileString; //to 
			inputFile >> fileString; //bot or output
			command.append(fileString + " ");
			inputFile >> fileString; //number
			command.append(fileString + " ");
			inputFile >> fileString; //and
			inputFile >> fileString; //high
			inputFile >> fileString; //to
			inputFile >> fileString; //bot or output
			command.append(fileString + " ");
			inputFile >> fileString; //number
			command.append(fileString);
		}

		commands[commandStep] = command;
		commandStep ++;
	}






	//output[0][0] = -1;
	for (int k = 0; k < 30; k++){
		for (int i = 0; i < commandStep; i++){
			command = commands[i];
			//cout << "full: " << command << endl;
			strLength = command.length();
			space = command.find(" ");
			if(command.substr(0,space).compare("NULL")==0){
				//cout << "null " << endl;
			}

			else if(command.substr(0,space).compare("value")==0){
				command = command.substr(space+1, strLength - space - 1);
				space = command.find(" ");
				value1 = stoi(command.substr(0,space));
				strLength = command.length();
				//cout << "val " << value1 << endl;
				space = command.find(" ");
				command = command.substr(space+1, strLength - space - 1);
				space = command.find(" ");
				bot1 = stoi(command.substr(0, space));
				//cout << "bot " << bot1 << endl;
				if(bots[bot1][0] == -1){
					bots[bot1][0] = value1;
				}
				else{
					bots[bot1][1] = value1;
				}

				//cout << "bot "<< bot1 << "=" << value1 << endl;
				//cout << "slot0 = " << bots[bot1][0] << endl;
				//cout << "slot1 = " << bots[bot1][1] << endl;

				commands[i] = "NULL";
			}

			else{
				bot1 = stoi(command.substr(0,space));
				command = command.substr(space+1, strLength - space - 1);
				space = command.find(" ");
				outBot = command.substr(0,space);
				command = command.substr(space+1, strLength - space - 1);
				strLength = command.length();
				space = command.find(" ");
				out = stoi(command.substr(0,space));

				//cout << "test1 " << outBot << " " << out << " " << value2 << endl;

				//get values from original bot
				if(bots[bot1][0] >-1 && bots[bot1][1] >-1){
					//cout << "  all good " << endl;
					if(bots[bot1][0]<bots[bot1][1]){
						value1 = bots[bot1][0];
						value2 = bots[bot1][1];
					}
					else{
						value2 = bots[bot1][0];
						value1 = bots[bot1][1];
					}

					if (value1 == 17 && value2 == 61){
						cout << bot1 << endl;
						system("pause");
					}
					
					bots[bot1][0] = -1;
					bots[bot1][1] = -1;
					//cout << " bot values " << value1 << " " << value2 << endl;


					//cout << "bot2 " << bot1 << endl;
					if (outBot.compare("bot") == 0){
						if(bots[out][0] == -1){
							bots[out][0] = value1;
						}
						else{
							bots[out][1] = value1;
						}
					}
					else{
						output[out][outputCount[out]] = value1;
						outputCount[out] ++;
					}

					command = command.substr(space+1, strLength - space - 1);
					strLength = command.length();
					space = command.find(" ");
					outBot = command.substr(0,space);
					command = command.substr(space+1, strLength - space - 1);
					strLength = command.length();
					space = command.find(" ");
					out = stoi(command.substr(0,space));

					if (outBot.compare("bot") == 0){
						if(bots[out][0] == -1){
							bots[out][0] = value2;
						}
						else{
							bots[out][1] = value2;
						}
					}
					else{
						output[out][outputCount[out]] = value2;
						outputCount[out] ++;
					}

					commands[i] = "NULL";
				}
			}
    }
	}

	cout << "(5) output0 " << output[0][0] << endl;
	cout << "(2) output1 " << output[1][0] << endl;
	cout << "(3) output2 " << output[2][0] << endl;



	cout << endl  << endl;

	system("pause");
	exit(-1);

	//Part 01:  56
	//Part 02:  7847
}
