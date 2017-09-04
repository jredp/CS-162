//////////////////// ** Author: Jared Parkinson 
//  Medusa.cpp // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#include "Medusa.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Medusa::Medusa() {
	strength = 8;
	armor = 3;
	isDead = false;
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Medusa::~Medusa() {}
/*---------------------------------------------------------------------------------*/
// Function: atkDiceRoll
// Description: Roll # of Dice and Size for a Total Attack (Class Specific)
/*---------------------------------------------------------------------------------*/
int Medusa::atkDiceRoll() {
	//Dice 2d6, total damage dealing
	int diceAmt = 2, diceType = 6, total = 0;

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
int Medusa::defDiceRoll() {
	//Dice 1d6, total after applied damage
	int diceAmt = 1, diceType = 6, total = 0;

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
int Medusa::attack() {
	int atkRoll = atkDiceRoll();

	//Special *Glare
	if (atkRoll == 12) { 
		//Max out attk > any creature str/def/arm
		atkRoll = 99;
		std::cout << "\n***Medusa used *Glare for instant death!***\n";
	} 
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Medusa::defend(int attack) {

	//Incoming Attack
	std::cout << "Incoming Attack against Medusa: " << attack << std::endl;
	//Roll Defense
	int defRoll = defDiceRoll(); //Roll for defense	
	std::cout << "Medusa Defense roll: " << defRoll << std::endl;
	//Defend First
	int atkAfterDef = (attack - defRoll);
	std::cout << "Attack After Medusa Defend: " << atkAfterDef << std::endl;
	//Armor Second
	int atkAfterArmor = (atkAfterDef - armor); //Left over attack after armor removed, can be negative
	std::cout << "Attack After Medusa Armor: " << atkAfterArmor << std::endl;

	//If damage is less than Defended/Armor amt
	if (atkAfterArmor <= 0) std::cout << "\nZero Damage Dealt to Medusa." << std::endl;
	//If damage surpasses Defense and Armor
	if (atkAfterArmor > 0) {
		int damaged = (strength - atkAfterArmor);
		//Check for death
		if (damaged <= 0) {
			setIsDead(true); //Set Death
			std::cout << "\n*******************\n" << "Medusa is DEAD!\n" << "*******************\n";
			strength = 0; //Set STR to 0
		}
		else strength = damaged; //Set Strength to damaged amount
	}
}
//Setters
/*---------------------------------------------------------------------------------*/
// Function: setIsDead
// Description: Set the Dead Bool
/*---------------------------------------------------------------------------------*/
void Medusa::setIsDead(bool state) {
	isDead = state;
}
//Getters
/*---------------------------------------------------------------------------------*/
// Function: getStrength
// Description: Get the Current Strength
/*---------------------------------------------------------------------------------*/
int Medusa::getStrength() {
	int curStr = strength;
	return curStr;
}
/*---------------------------------------------------------------------------------*/
// Function: getIsDead
// Description: Get the Dead Bool
/*---------------------------------------------------------------------------------*/
bool Medusa::getIsDead() {
	return isDead;
}