#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int battle(int pHP, int pArm, int pDam, int bHP, int bArm, int bDam, int gold);

int main(){
	string fileString;
	ifstream inputFile;
	int weapon[5][2] = {};
	int armor[6][2] = {};
	int ring[8][2] = {};
	int bossDamage = 0;
	int bossHP = 0;
	int bossArmor = 0;
	int playerDamage = 0;
	int playerHP = 100;
	int playerArmor = 0;
	int goldSpent = 0;
	int minSpent = 0;
	int returnVal = 0;

	//damage only
	weapon[0][0] = 8;
	weapon[0][1] = 4;
	weapon[1][0] = 10;
	weapon[1][1] = 5;
	weapon[2][0] = 25;
	weapon[2][1] = 6;
	weapon[3][0] = 40;
	weapon[3][1] = 7;
	weapon[4][0] = 74;
	weapon[4][1] = 8;

	//armor only
	armor[0][0] = 0;
	armor[0][1] = 0;
	armor[1][0] = 13;
	armor[1][1] = 1;
	armor[2][0] = 31;
	armor[2][1] = 2;
	armor[3][0] = 53;
	armor[3][1] = 3;
	armor[4][0] = 75;
	armor[4][1] = 4;
	armor[5][0] = 102;
	armor[5][1] = 5;

	//nothing
	ring[0][0] = 0;
	ring[0][1] = 0;
	ring[1][0] = 0;
	ring[1][1] = 0;

	//damage
	ring[2][0] = 25;
	ring[2][1] = 1;
	ring[3][0] = 50;
	ring[3][1] = 2;
	ring[4][0] = 100;
	ring[4][1] = 3;

	//armor
	ring[5][0] = 20;
	ring[5][1] = 1;
	ring[6][0] = 40;
	ring[6][1] = 2;
	ring[7][0] = 80;
	ring[7][1] = 3;

	fileString = "C:/advent/2015/day21_input.txt";
	//fileString="C:/advent/testdata.txt";

	//opens the file
	inputFile.open(fileString);
	while (!inputFile.eof()){
		inputFile >> fileString;
		if(fileString.compare("Hit") == 0){
			inputFile >> fileString;
			inputFile >> fileString;
			bossHP = stoi(fileString);
		}
		if(fileString.compare("Damage:") == 0){
			inputFile >> fileString;
			bossDamage = stoi(fileString);
		}
		if(fileString.compare("Armor:") == 0){
			inputFile >> fileString;
			bossArmor = stoi(fileString);
		}
	}

	cout << bossHP << " " << bossDamage << " " << bossArmor << endl;
	/*
	int playerDamage = 0;
	int playerHP = 100;
	int playerArmor = 0;
	int goldSpent = 0;
	int minSpent = 0;
	*/


	for(int i = 0; i < 5; i++){
		goldSpent = 0;
		playerHP = 100;
		playerDamage = 0;
		playerDamage = weapon[i][1];

		for(int j = 0; j < 6; j++){
			playerArmor = 0;
			playerArmor = armor[j][1];

			for(int k = 0; k < 8; k++){
				for(int l = 0; l < 8; l++){
					if(k != l){
						playerDamage = weapon[i][1];
						playerArmor = armor[j][1];

						if(k>=2 && k<5){
							playerDamage = weapon[i][1] + ring[k][1];
						}
						else if(k >=5){
							playerArmor = armor[j][1] + ring[k][1];
						}

						if(l>=2 && l<5){
							playerDamage = playerDamage + ring[l][1];
						}
						else if(l >=5){
							playerArmor = playerArmor + ring[l][1];
						}

						cout << "items " << i << " " << j << " " << k << " " << l << endl;
						goldSpent = weapon[i][0] + armor[j][0] + ring[k][0] + ring[l][0];
						returnVal = battle(playerHP, playerArmor, playerDamage, bossHP, bossArmor, bossDamage, goldSpent);
					}
				}
			}
		}
	}


	system("pause");
	exit(-1);

	//Part 01:  78
	//Part 02:  148
}

int battle(int pHP, int pArm, int pDam, int bHP, int bArm, int bDam, int gold){
	int playerAttack = pDam - bArm;
	if (playerAttack < 1){
		playerAttack = 1;
	}
	int bossAttack = bDam - pArm;
	if(bossAttack < 1){
		bossAttack = 1;
	}

	while(pHP > 0 && bHP > 0){

		bHP = bHP - playerAttack;
		//cout << "boss " << bHP << endl;
		if(bHP <= 0){
			cout << "***PLAYER WINS***" << endl;
		}
		pHP = pHP - bossAttack;
		//cout << "player " << pHP << endl;
		if(pHP <= 0 && bHP > 0){
			cout << "***BOSS WINS***" << endl;
			cout << "Gold " << gold <<endl;
			system("pause");
		}
	}

	return 0;
}
