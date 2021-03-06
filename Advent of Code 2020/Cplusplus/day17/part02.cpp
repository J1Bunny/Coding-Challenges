#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//it's only checking the current layer cube - need to check the others

int main() {
	string fileString;
	ifstream inputFile;
	int seat[25][25][25][25];
	int work[25][25][25][25];
	int row = 0;
	int column = 0;
	int cube = 6;
	int maxRow = 0;
	int maxColumn = 0;
	bool firstRow = true;
	int checkSeat = 0;
	int oldCount = 0;
	int newCount = 0;
	int rounds = 6;
	int beginCube = 0;
	int endCube = 0;
	int what = 6;
	int beginWhat = 0;
	int endWhat = 0;

	fileString = "/Users/sarahbier/Desktop/testdata.txt";
	fileString = "/Users/sarahbier/Desktop/realdata.txt";

	inputFile.open(fileString);
	while (!inputFile.eof()) {
		getline(inputFile, fileString);
		cout << fileString << endl;

		for (row = 0; row < fileString.length() + (rounds * 2); row++) {
			seat[row][0][beginCube][beginWhat] = 0;
		}
		if (firstRow) {
			column += rounds;
			firstRow = false;
		}

		int step = 0;
		for (int i = 0; i < rounds; i++) {
			seat[i][column][beginCube][beginWhat] = 0;
			step++;
		}
		for (row = step; row < fileString.length() + step; row++) {
			if (fileString.substr(row - step, 1).compare(".") == 0) {
				seat[row][column][beginCube][beginWhat] = 0;
			} else {
				seat[row][column][beginCube][beginWhat] = 1;
			}
			maxRow = row + rounds;
		}
		seat[maxRow][column][beginCube][beginWhat] = 0;
		column++;

	}

	for (row = 0; row < fileString.length() + (rounds * 2); row++) {
		seat[row][column][beginCube][beginWhat] = 0;
	}

	column += rounds;
	maxColumn = column;

	//maxColumn = maxColumn;
	maxRow = maxRow + 1;

	cout << "maxC " << maxColumn << endl;
	cout << "maxR " << maxRow << endl;

	/*
	 Initial State = active
	 Remains active if 2 or 3 neighbors are active
	 Otherwise becomes inactive

	 Initial State = inactive
	 Becomes active if 3 neighbors are active
	 Otherwise remains inactive
	 */

	//top row, column = 0
	//bottom row, column = maxColumn - 1
	//far left, row = 0
	//far right, row = maxRow - 1
	//for each round
	//display seat (current seating)
	//run change against work (read from seat)
	//copy work into seat
	//initial seating
	/*
	 cout << "initial seating " << endl << endl;
	 for (column = 0; column < maxColumn; column++) {
	 for (row = 0; row < maxRow; row++) {
	 cout << seat[row][column][beginCube];
	 work[row][column][beginCube][beginWhat] = seat[row][column][0][0];
	 }
	 cout << endl;
	 }
	 */

	//seat[row][column][cube] = "X";
	//(0,0)(1,0)(2,0)
	//(0,1)(1,1)(2,1)
	//(0,2)(1,2)(2,2)
	endCube = cube + 1;
	beginCube = cube * -1;
	endWhat = what + 1;
	beginWhat = what * -1;
	for (int i = 0; i < rounds; i++) {

		//run the rules
		cout << endl << endl;
		for (what = beginWhat; what < endWhat; what++) {

			for (cube = beginCube; cube < endCube; cube++) {
				for (column = 0; column < maxColumn; column++) {
					for (row = 0; row < maxRow; row++) {
						checkSeat = 0;
						//ignore floor spots

						if (seat[row - 1][column - 1][cube - 1][what - 1]
								== 1) {
							checkSeat++; //up-left
						}
						if (seat[row - 1][column + 1][cube - 1][what - 1]
								== 1) {
							checkSeat++; //down-left
						}
						if (seat[row - 1][column][cube - 1][what - 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row][column - 1][cube][what - 1] == 1) {
							checkSeat++; //up-up
						}
						if (seat[row - 1][column + 1][cube + 1][what + 1]
								== 1) {
							checkSeat++; //down-left
						}
						if (seat[row - 1][column][cube + 1][what + 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row - 1][column - 1][cube][what - 1] == 1) {
							checkSeat++; //up-left
						}
						if (seat[row - 1][column + 1][cube][what - 1] == 1) {
							checkSeat++; //down-left
						}
						if (seat[row - 1][column][cube][what - 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row - 1][column - 1][cube + 1][what - 1]
								== 1) {
							checkSeat++; //up-left
						}
						if (seat[row - 1][column + 1][cube][what + 1] == 1) {
							checkSeat++; //down-left
						}
						if (seat[row - 1][column][cube][what + 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row - 1][column - 1][cube + 1][what + 1]
								== 1) {
							checkSeat++; //up-left
						}
						if (seat[row - 1][column + 1][cube + 1][what - 1]
								== 1) {
							checkSeat++; //down-left
						}
						if (seat[row - 1][column][cube + 1][what - 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row - 1][column - 1][cube - 1][what] == 1) {
							checkSeat++; //up-left
						}
						if (seat[row - 1][column + 1][cube - 1][what] == 1) {
							checkSeat++; //down-left
						}
						if (seat[row - 1][column][cube - 1][what] == 1) {
							checkSeat++; //left
						}
						if (seat[row - 1][column + 1][cube + 1][what] == 1) {
							checkSeat++; //down-left
						}
						if (seat[row - 1][column][cube + 1][what] == 1) {
							checkSeat++; //left
						}
						if (seat[row - 1][column - 1][cube - 1][what + 1]
								== 1) {
							checkSeat++; //up-left
						}
						if (seat[row - 1][column + 1][cube - 1][what + 1]
								== 1) {
							checkSeat++; //down-left
						}
						if (seat[row - 1][column - 1][cube][what + 1] == 1) {
							checkSeat++; //up-left
						}
						if (seat[row - 1][column][cube - 1][what + 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row - 1][column - 1][cube][what] == 1) {
							checkSeat++; //up-left
						}
						if (seat[row - 1][column + 1][cube][what] == 1) {
							checkSeat++; //down-left
						}
						if (seat[row - 1][column][cube][what] == 1) {
							checkSeat++; //left
						}
						if (seat[row - 1][column - 1][cube + 1][what] == 1) {
							checkSeat++; //up-left
						}

						if (seat[row][column][cube + 1][what] == 1) {
							checkSeat++; //left
						}
						if (seat[row][column][cube - 1][what] == 1) {
							checkSeat++; //left
						}
						if (seat[row][column - 1][cube][what] == 1) {
							checkSeat++; //up-up
						}
						if (seat[row][column - 1][cube + 1][what] == 1) {
							checkSeat++; //up-up
						}
						if (seat[row][column + 1][cube][what] == 1) {
							checkSeat++; //down-down
						}
						if (seat[row][column - 1][cube - 1][what + 1] == 1) {
							checkSeat++; //up-up
						}

						if (seat[row][column + 1][cube - 1][what + 1] == 1) {
							checkSeat++; //down-down
						}
						if (seat[row][column][cube - 1][what + 1] == 1) {
							checkSeat++; //left
						}

						if (seat[row][column - 1][cube][what + 1] == 1) {
							checkSeat++; //up-up
						}
						if (seat[row][column][cube + 1][what - 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row][column][cube][what - 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row][column - 1][cube + 1][what - 1] == 1) {
							checkSeat++; //up-up
						}
						if (seat[row][column + 1][cube + 1][what - 1] == 1) {
							checkSeat++; //down-down
						}

						if (seat[row][column - 1][cube - 1][what - 1] == 1) {
							checkSeat++; //up-up
						}
						if (seat[row][column + 1][cube - 1][what - 1] == 1) {
							checkSeat++; //down-down
						}
						if (seat[row][column][cube - 1][what - 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row][column][cube + 1][what + 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row][column][cube][what + 1] == 1) {
							checkSeat++; //left
						}
						if (seat[row][column - 1][cube - 1][what] == 1) {
							checkSeat++; //up-up
						}

						if (seat[row][column + 1][cube - 1][what] == 1) {
							checkSeat++; //down-down
						}
						if (seat[row][column - 1][cube + 1][what + 1] == 1) {
							checkSeat++; //up-up
						}
						if (seat[row][column + 1][cube + 1][what + 1] == 1) {
							checkSeat++; //down-down
						}
						if (seat[row][column + 1][cube][what + 1] == 1) {
							checkSeat++; //down-down
						}
						if (seat[row][column + 1][cube + 1][what] == 1) {
							checkSeat++; //down-down
						}

						if (seat[row][column + 1][cube][what - 1] == 1) {
							checkSeat++; //down-down
						}
						if (seat[row + 1][column - 1][cube - 1][what + 1]
								== 1) {
							checkSeat++; //up-right
						}
						if (seat[row + 1][column - 1][cube][what] == 1) {
							checkSeat++; //up-right
						}
						if (seat[row + 1][column][cube][what] == 1) {
							checkSeat++; //right
						}
						if (seat[row + 1][column + 1][cube][what] == 1) {
							checkSeat++; //down-right
						}
						if (seat[row + 1][column - 1][cube + 1][what + 1]
								== 1) {
							checkSeat++; //up-right
						}
						if (seat[row + 1][column][cube + 1][what + 1] == 1) {
							checkSeat++; //right
						}
						if (seat[row + 1][column + 1][cube + 1][what + 1]
								== 1) {
							checkSeat++; //down-right
						}
						if (seat[row + 1][column - 1][cube - 1][what - 1]
								== 1) {
							checkSeat++; //up-right
						}
						if (seat[row + 1][column][cube - 1][what - 1] == 1) {
							checkSeat++; //right
						}
						if (seat[row + 1][column + 1][cube - 1][what - 1]
								== 1) {
							checkSeat++; //down-right
						}
						if (seat[row + 1][column - 1][cube + 1][what - 1]
								== 1) {
							checkSeat++; //up-right
						}
						if (seat[row + 1][column][cube + 1][what - 1] == 1) {
							checkSeat++; //right
						}
						if (seat[row + 1][column + 1][cube + 1][what - 1]
								== 1) {
							checkSeat++; //down-right
						}
						if (seat[row + 1][column - 1][cube][what - 1] == 1) {
							checkSeat++; //up-right
						}
						if (seat[row + 1][column][cube][what - 1] == 1) {
							checkSeat++; //right
						}
						if (seat[row + 1][column + 1][cube][what - 1] == 1) {
							checkSeat++; //down-right
						}
						if (seat[row + 1][column - 1][cube - 1][what] == 1) {
							checkSeat++; //up-right
						}
						if (seat[row + 1][column][cube - 1][what] == 1) {
							checkSeat++; //right
						}
						if (seat[row + 1][column + 1][cube - 1][what] == 1) {
							checkSeat++; //down-right
						}

						if (seat[row + 1][column][cube - 1][what + 1] == 1) {
							checkSeat++; //right
						}
						if (seat[row + 1][column + 1][cube - 1][what + 1]
								== 1) {
							checkSeat++; //down-right
						}
						if (seat[row + 1][column - 1][cube][what + 1] == 1) {
							checkSeat++; //up-right
						}
						if (seat[row + 1][column][cube][what + 1] == 1) {
							checkSeat++; //right
						}
						if (seat[row + 1][column + 1][cube][what + 1] == 1) {
							checkSeat++; //down-right
						}
						if (seat[row + 1][column - 1][cube + 1][what] == 1) {
							checkSeat++; //up-right
						}
						if (seat[row + 1][column][cube + 1][what] == 1) {
							checkSeat++; //right
						}
						if (seat[row + 1][column + 1][cube + 1][what] == 1) {
							checkSeat++; //down-right
						}

						//end section
						if (seat[row][column][cube][what] == 1) {
							if (checkSeat == 2 || checkSeat == 3) {
								work[row][column][cube][what] = 1;
							} else {
								work[row][column][cube][what] = 0;
							}
						} else {
							if (checkSeat == 3) {
								work[row][column][cube][what] = 1;
							}
						}

					}

					/*
					 Initial State = active
					 Remains active if 2 or 3 neighbors are active
					 Otherwise becomes inactive

					 Initial State = inactive
					 Becomes active if 3 neighbors are active
					 Otherwise remains inactive
					 */

				}
			}
		}

		for (what = beginWhat; what < endWhat; what++) {
			for (cube = beginCube; cube < endCube; cube++) {
				for (column = 0; column < maxColumn; column++) {
					for (row = 0; row < maxRow; row++) {
						//cout << seat[row][column];
						seat[row][column][cube][what] =
								work[row][column][cube][what];
					}
				}
			}
		}

		//end here

		newCount = 0;
		for (what = beginWhat; what < endWhat; what++) {
			for (cube = beginCube; cube < endCube; cube++) {
				//cout << "Round " << i << endl;
				//cout << "Z= " << cube << ",  W= " << what << endl << endl;
				for (column = 0; column < maxColumn; column++) {
					for (row = 0; row < maxRow; row++) {
						//cout << seat[row][column][cube][what];
						if (seat[row][column][cube][what] == 1) {
							newCount++;
						}
					}
				}
			}
		}
		cout << "Round " << i << endl;
		cout << newCount << endl;
	}

	cout << endl << "total active " << newCount << endl;
}

//part 01:  276
//part 02:  2136

//2137 too high

