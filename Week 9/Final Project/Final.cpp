//////////////////// ** Author: Jared Parkinson 
//  Final.cpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Final.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
/*---------------------------------------------------------------------------------*/
Final::Final() {
	N = NULL; //North Link
	S = NULL; //South Link
	E = NULL; //East Link
	W = NULL; //West Link	
	playerHere = NULL; //Player in Space
	specialComplete = false;
	//Special is Final Battle!		
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Final::~Final() {}
/*---------------------------------------------------------------------------------*/
// Function: printSpaceDesc
// Desc: Prints the Space Description to the screen
/*---------------------------------------------------------------------------------*/
void Final::printSpaceDesc() {
	//Description based on Special
	std::cout << "\n--------------------------------------------------------\n";	
	std::cout << "Final: (BATTLE)\n";
	std::cout << " \n*Your surroundings have changed!\n";
	std::cout << "You have been transported back in time to the Evil Mage\n";
	std::cout << "Castle! You must use your Sword and skill to defeat the\n";
	std::cout << "Evil Nefarious Mage!\n";		
	std::cout << "--------------------------------------------------------\n";
}
/*---------------------------------------------------------------------------------*/
// Function: Special
// Desc: Does Special Actions / Prints if none
/*---------------------------------------------------------------------------------*/
void Final::Special() {
	printSpaceDesc();
	if (specialComplete == false) {
		int choice;				
		spaceOptions();
		do {
			switch (choice = spaceInput()) {
			case 1:				
				//Battle!
				std::cout << "\n**************************************************************\n";
				std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
				std::cout << "<]] FINAL BATTLE!! [[>\n";
				std::cout << " **You equip your sword and begin the battle!\n";
				std::cout << "The mage shoots a fireball at you and you dodge to the side!\n";
				std::cout << "You sprint towards Nefarious and as you do he hurls a\n";
				std::cout << "lightning bolt at you! You do a barrel roll to the side\n";
				std::cout << "and lunge forward with a slash! Your sword fells him\n";
				std::cout << "in one blow! You have won!!\n";
				std::cout << "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
				std::cout << "**************************************************************\n";
				specialComplete = true;				
				break;			
			default:
				std::cout << "Invalid Menu Choice. Try again.\n\n";
				break;
			}
		} while (choice != 1);
		std::cin.clear(); //Clear cin state
		std::cin.ignore(2, '\n'); //Clear Buffer
	}
}
/*---------------------------------------------------------------------------------*/
// Function: spaceOptions
// Desc: Show Special Options
/*---------------------------------------------------------------------------------*/
void Final::spaceOptions() {
	std::cout << "\n1. Battle the Mage with your Sword!\n";	
	std::cout << "Ready??? Enter 1 to Battle! ";
}