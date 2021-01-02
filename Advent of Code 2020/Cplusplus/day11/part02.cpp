#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileString;
	ifstream inputFile;
	string seat[99][99];
	string work[99][99];
	int row = 0;
	int column = 0;
	int maxRow = 0;
	int maxColumn = 0;
	bool firstRow = true;
	int checkSeat = 0;
	int oldCount = 0;
	int newCount = 0;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		//cout << fileString << endl;
		for (row = 0; row < fileString.length() + 2; row++) {
			seat[row][0] = ".";
		}
		if (firstRow) {
			column++;
			firstRow = false;
		}

		seat[0][column] = ".";
		for (row = 1; row < fileString.length() + 1; row++) {
			seat[row][column] = fileString.substr(row - 1, 1);
			maxRow = row + 1;
		}
		seat[maxRow][column] = ".";
		column++;
	}
	for (row = 0; row < fileString.length() + 2; row++) {
		seat[row][column] = ".";
	}
	column++;
	maxColumn = column;

	//maxColumn = maxColumn;
	maxRow = maxRow + 1;

	//top row, column = 0
	//bottom row, column = maxColumn - 1
	//far left, row = 0
	//far right, row = maxRow - 1

	//for each round
	//display seat (current seating)
	//run change against work (read from seat)
	//copy work into seat

	//initial seating
	cout << "initial seating " << endl << endl;
	for (column = 0; column < maxColumn; column++) {
		for (row = 0; row < maxRow; row++) {
			cout << seat[row][column];
			work[row][column] = seat[row][column];
		}
		cout << endl;
	}

	//seat[row][column] = "X";
	//(0,0)(1,0)(2,0)
	//(0,1)(1,1)(2,1)
	//(0,2)(1,2)(2,2)

	int x = 0;
	int y = 0;
	for (int i = 0; i < 5; i++) {

		//run the rules
		cout << endl << endl;
		for (column = 0; column < maxColumn; column++) {
			for (row = 0; row < maxRow; row++) {
				checkSeat = 0;
				//ignore floor spots
				if (seat[row][column].compare(".") != 0) {

					x = row - 1;
					y = column - 1;
					while (x > -1 && y > -1) {
						if (seat[x][y].compare("#") == 0) {
							checkSeat++; //up-left
							x = -1;
							y = -1;
						} else if (seat[x][y].compare("L") == 0) {
							x = -1;
							y = -1;
						}
						x--;
						y--;
					}

					x = row;
					y = column - 1;
					while (y > -1) {
						if (seat[x][y].compare("#") == 0) {
							checkSeat++; //up-up
							y = -1;
						} else if (seat[x][y].compare("L") == 0) {
							y = -1;
						}
						y--;
					}

					x = row + 1;
					y = column - 1;
					while (x < maxRow + 1 && y > -1) {
						if (seat[x][y].compare("#") == 0) {
							checkSeat++; //up-right
							x = maxRow + 1;
							y = -1;
						} else if (seat[x][y].compare("L") == 0) {
							x = maxRow + 1;
							y = -1;
						}
						x++;
						y--;
					}

					x = row + 1;
					y = column;
					while (x < maxRow + 1) {
						if (seat[x][y].compare("#") == 0) {
							checkSeat++; //right
							x = maxRow + 1;
						} else if (seat[x][y].compare("L") == 0) {
							x = maxRow + 1;
						}
						x++;
					}

					x = row + 1;
					y = column + 1;
					while (x < maxRow + 1 && y < maxColumn + 1) {
						if (seat[x][y].compare("#") == 0) {
							checkSeat++; //down-right
							x = maxRow + 1;
							y = maxColumn + 1;
						} else if (seat[x][y].compare("L") == 0) {
							x = maxRow + 1;
							y = maxColumn + 1;
						}
						x++;
						y++;
					}

					x = row;
					y = column + 1;
					while (y < maxColumn) {
						if (seat[x][y].compare("#") == 0) {
							checkSeat++; //up-up
							y = maxColumn + 1;
						} else if (seat[x][y].compare("L") == 0) {
							y = maxColumn + 1;
						}
						y++;
					}

					x = row - 1;
					y = column + 1;
					while (x > -1 && y < maxColumn + 1) {
						if (seat[x][y].compare("#") == 0) {
							checkSeat++; //down-right
							x = -1;
							y = maxColumn + 1;
						} else if (seat[x][y].compare("L") == 0) {
							x = -1;
							y = maxColumn + 1;
						}
						x--;
						y++;
					}

					x = row - 1;
					y = column;
					while (x > -1) {
						if (seat[x][y].compare("#") == 0) {
							checkSeat++; //right
							x = -1;
						} else if (seat[x][y].compare("L") == 0) {
							x = -1;
						}
						x--;
					}
				}

				if (checkSeat >= 5 && seat[row][column].compare("#") == 0) {
					work[row][column] = "L";
				}
				if (checkSeat == 0 && seat[row][column].compare("L") == 0) {
					work[row][column] = "#";
				}
			}
		}

		for (column = 0; column < maxColumn; column++) {
			for (row = 0; row < maxRow; row++) {
				//cout << work[row][column];
				seat[row][column] = work[row][column];
			}
		}

		newCount = 0;
		cout << "final seating " << endl << endl;
		for (column = 0; column < maxColumn; column++) {
			for (row = 0; row < maxRow; row++) {
				cout << seat[row][column];
				if (seat[row][column].compare("#") == 0) {
					newCount++;
				}
			}
			cout << endl;
		}

		if (newCount != oldCount) {
			i--;
		}
		oldCount = newCount;
	}

	cout << endl << "total seats " << newCount << endl;
}

//part 01:  2194
//part 02:  1944
