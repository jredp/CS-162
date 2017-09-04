//////////////////// ** Author: Jared Parkinson 
//  Bluemen.cpp  // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#include "Bluemen.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Bluemen::Bluemen() {
	strength = 12;
	armor = 3;
	defDice = 3;
	isDead = false;
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Bluemen::~Bluemen() {}
/*---------------------------------------------------------------------------------*/
// Function: atkDiceRoll
// Description: Roll # of Dice and Size for a Total Attack (Class Specific)
/*---------------------------------------------------------------------------------*/
int Bluemen::atkDiceRoll() {
	//Dice 2d10, total damage dealing
	int diceAmt = 2, diceType = 10, total = 0;

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
int Bluemen::defDiceRoll() {
	//Dice 3d6, total after applied damage
	int diceAmt = defDice, diceType = 6, total = 0;

	//Random roll for each Die
	for (int i = 0; i < diceAmt; i++) {
		std::uniform_int_distribution<> diceRoll(0, diceType);
		auto singleRoll = diceRoll(engine);
		total += singleRoll;
	}
	return total;
}
/*---------------------------------------------------------------------------------*/
// Function: attack
// Description: Returns an Attack Roll
/*---------------------------------------------------------------------------------*/
int Bluemen::attack() {
	int atkRoll = atkDiceRoll();
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Bluemen::defend(int attack) {			
	//Incoming Attack
	std::cout << "Incoming Attack against Blue: " << attack << std::endl;
	//Roll Defense
	int defRoll = defDiceRoll(); //Roll for defense	
	std::cout << "Blue Defense roll: " << defRoll << std::endl;
	//Defend First
	int atkAfterDef = (attack - defRoll);
	std::cout << "Attack After Blue Defend: " << atkAfterDef << std::endl;
	//Armor Second
	int atkAfterArmor = (atkAfterDef - armor); //Left over attack after armor removed, can be negative
	std::cout << "Attack After Blue Armor: " << atkAfterArmor << std::endl;
	//If damage is less than Defended/Armor amt
	if (atkAfterArmor <= 0) std::cout << "\nZero Damage Dealt to Blue." << std::endl;
	//If damage surpasses Defense and Armor
	if (atkAfterArmor > 0) {
		int damaged = (strength - atkAfterArmor);		
		if (damaged <= 0) { //Check for death
			setIsDead(true); //Set Death
			std::cout << "\n*******************\n" << "Blue Men have DIED!\n" << "*******************\n";
			strength = 0; //Set STR to 0
		}
		else strength = damaged; //Set Strength to damaged amount
	}
	//Special!! *Mob - Take damage taken/4
	if ((atkAfterArmor > 4) && (defDice != 0)) {
		int divide = atkAfterArmor / 4;
		std::cout << "\nBlue Men used *Mob!" << std::endl;				
		defDice -= divide;
		std::cout << "\nBlue Men # Dice after removal: " << defDice << std::endl;
		if (defDice < 0) defDice = 0;
	}
}
//Setters
/*---------------------------------------------------------------------------------*/
// Function: setIsDead
// Description: Set the Dead Bool
/*---------------------------------------------------------------------------------*/
void Bluemen::setIsDead(bool state) {
	isDead = state;
}
//Getters
/*---------------------------------------------------------------------------------*/
// Function: getStrength
// Description: Get the Current Strength
/*---------------------------------------------------------------------------------*/
int Bluemen::getStrength() {
	int curStr = strength;
	return curStr;
}
/*---------------------------------------------------------------------------------*/
// Function: getIsDead
// Description: Get the Dead Bool
/*---------------------------------------------------------------------------------*/
bool Bluemen::getIsDead() {
	return isDead;
}