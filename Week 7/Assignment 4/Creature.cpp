//////////////////// ** Author: Jared Parkinson 
//  Creature.cpp  // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#include "Creature.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
/*---------------------------------------------------------------------------------*/
Creature::Creature() {}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Creature::~Creature() {}
//Setters
/*---------------------------------------------------------------------------------*/
// Function: setIsDead
// Description: Set the Dead Bool
/*---------------------------------------------------------------------------------*/
void Creature::setIsDead(bool state) {
	isDead = state;
}
/*---------------------------------------------------------------------------------*/
// Function: setIsDead
// Description: Set the Dead Bool
/*---------------------------------------------------------------------------------*/
void Creature::setFighterID() {
	std::string tempString;

	std::cout << "Enter a FighterID or Name:\n";
	std::cin.ignore(256, '\n');
	std::getline(std::cin, tempString); //Intake String	
	fighterID = tempString; //Set ID
}
/*---------------------------------------------------------------------------------*/
// Function: incWins
// Description: Increment Wins
/*---------------------------------------------------------------------------------*/
void Creature::incWins() {
	totalWins++;
}
/*---------------------------------------------------------------------------------*/
// Function: incWins
// Description: Increment Wins
/*---------------------------------------------------------------------------------*/
void Creature::restoreHP() {
	int tempCurStr = strength;
	int maxStr = fixedHP;
	int theDifference = maxStr - tempCurStr;
	//Negative Difference
	if (theDifference < 1) {
		//Specifically Baba Yaga
		strength = maxStr;
	}
	//Positive Difference
	else if (theDifference > 0) {
		//Restore 50% of damage taken
		int restore = (theDifference * .5);
		strength = (tempCurStr + restore);
	}
}
//Getters
/*---------------------------------------------------------------------------------*/
// Function: getStrength
// Description: Get the Current Strength
/*---------------------------------------------------------------------------------*/
int Creature::getStrength() {
	int curStr = strength;
	return curStr;
}
/*---------------------------------------------------------------------------------*/
// Function: getWins
// Description: Get the total Wins
/*---------------------------------------------------------------------------------*/
int Creature::getWins() {
	return totalWins;
}
/*---------------------------------------------------------------------------------*/
// Function: getClassType
// Description: Get the Class Type
/*---------------------------------------------------------------------------------*/
std::string Creature::getClassType() {
	return classType;
}
/*---------------------------------------------------------------------------------*/
// Function: getFighterScore
// Description: Set the Fighter Score
/*---------------------------------------------------------------------------------*/
int Creature::getFighterScore() {
	int tempScore = totalWins + totalAttackDealt;
	return tempScore;
}
/*---------------------------------------------------------------------------------*/
// Function: getIsDead
// Description: Get the Dead Bool
/*---------------------------------------------------------------------------------*/
bool Creature::getIsDead() {
	return isDead;
}
/*---------------------------------------------------------------------------------*/
// Function: getFighterID
// Description: Get the Fighter ID / Name
/*---------------------------------------------------------------------------------*/
std::string Creature::getFighterID() {
	return fighterID;
}
/*---------------------------------------------------------------------------------*/
// Function: atkDiceRoll
// Description: Roll # of Dice and Size for a Total Attack (Class Specific)
/*---------------------------------------------------------------------------------*/
int Creature::atkDiceRoll() {
	int diceAmt = atkDice, diceType = atkDiceType, total = 0;

	//Random roll for each Die
	for (int i = 0; i < diceAmt; i++) {
		std::uniform_int_distribution<> diceRoll(0, diceType);
		auto singleRoll = diceRoll(engine);
		total += singleRoll;
	}
	return total;
}
/*---------------------------------------------------------------------------------*/
// Function: defDiceRoll
// Description: Roll # of Dice and Size for a Total Defense (Class Specific)
/*---------------------------------------------------------------------------------*/
int Creature::defDiceRoll() {
	int diceAmt = defDice, diceType = defDiceType, total = 0;

	//Random roll for each Die
	for (int i = 0; i < diceAmt; i++) {
		std::uniform_int_distribution<> diceRoll(0, diceType);
		auto singleRoll = diceRoll(engine);
		total += singleRoll;
	}
	return total;
}