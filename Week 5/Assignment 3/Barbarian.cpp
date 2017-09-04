//////////////////// ** Author: Jared Parkinson 
//  Barbarian.cpp // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#include "Barbarian.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Barbarian::Barbarian() {
	strength = 12;
	armor = 0;	
	isDead = false;
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Barbarian::~Barbarian() {}
/*---------------------------------------------------------------------------------*/
// Function: atkDiceRoll
// Description: Roll # of Dice and Size for a Total Attack (Class Specific)
/*---------------------------------------------------------------------------------*/
int Barbarian::atkDiceRoll() {
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
int Barbarian::defDiceRoll() {
	//Dice 2d6, total after applied damage
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
// Function: attack
// Description: Returns an Attack Roll
/*---------------------------------------------------------------------------------*/
int Barbarian::attack() {	
	int atkRoll = atkDiceRoll();
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Barbarian::defend(int attack) {
	
	//Incoming Attack
	std::cout << "Incoming Attack against Barb: " << attack << std::endl;
	//Roll Defense
	int defRoll = defDiceRoll(); //Roll for defense	
	std::cout << "Barb Defense roll: " << defRoll << std::endl;
	//Defend First
	int atkAfterDef = (attack - defRoll);
	std::cout << "Attack After Barb Defend: " << atkAfterDef << std::endl;
	//Armor Second
	int atkAfterArmor = (atkAfterDef - armor); //Left over attack after armor removed, can be negative
	std::cout << "Attack After Barb Armor: " << atkAfterArmor << std::endl;

	//If damage is less than Defended/Armor amt
	if (atkAfterArmor <= 0) std::cout << "\nZero Damage Dealt to Barb." << std::endl;
	//If damage surpasses Defense and Armor
	if (atkAfterArmor > 0) {
		int damaged = (strength - atkAfterArmor);
		//Check for death
		if (damaged <= 0) {
			setIsDead(true); //Set Death
			std::cout << "\n*******************\n" << "Barbarian has DIED!\n" << "*******************\n";
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
void Barbarian::setIsDead(bool state) {
	isDead = state;
}
//Getters
/*---------------------------------------------------------------------------------*/
// Function: getStrength
// Description: Get the Current Strength
/*---------------------------------------------------------------------------------*/
int Barbarian::getStrength() {
	int curStr = strength;
	return curStr;
}
/*---------------------------------------------------------------------------------*/
// Function: getIsDead
// Description: Get the Dead Bool
/*---------------------------------------------------------------------------------*/
bool Barbarian::getIsDead() {
	return isDead;
}