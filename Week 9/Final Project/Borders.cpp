//////////////////// ** Author: Jared Parkinson 
//  Borders.cpp   // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Borders.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
/*---------------------------------------------------------------------------------*/
Borders::Borders() {
	N = NULL; //North Link
	S = NULL; //South Link
	E = NULL; //East Link
	W = NULL; //West Link	
	playerHere = NULL; //Player in Space
	specialComplete = false;
	
	//Item: Red Time Gem
	std::string tempName = "RedGem";
	item = new Item(tempName);
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Borders::~Borders() {}
/*---------------------------------------------------------------------------------*/
// Function: printSpaceDesc
// Desc: Prints the Space Description to the screen
/*---------------------------------------------------------------------------------*/
void Borders::printSpaceDesc() {
	//Description based on Special	
	if (specialComplete == false) {
		std::cout << "\n***************************************************\n";
		std::cout << "BORDERS BOOKS: (Red Gem)\n";
		std::cout << "A vast Monastery of some sort contains many scholarly\n";
		std::cout << "scroll-like materials! The Monks seems to be mismatched\n";
		std::cout << "in their dress! There even is a woman Scholar here!?!\n";
		std::cout << "No time to waste with the Scholar wench! Carry On!\n";
		std::cout << "There is a red glow eminating from the shelf! The Red\n";
		std::cout << "Gem! Take it?\n";
		std::cout << "\n***************************************************\n";
	}
	else {
		std::cout << "\n***************************************************\n";
		std::cout << "BORDERS BOOKS: (Red Gem)\n";
		std::cout << "You have already picked up the Red Gem.\n";
		std::cout << "No time to waste! Move on!\n";
		std::cout << "***************************************************\n";
	}
}
/*---------------------------------------------------------------------------------*/
// Function: Special
// Desc: Does Special Actions / Prints if none
/*---------------------------------------------------------------------------------*/
void Borders::Special() {
	printSpaceDesc();
	if (specialComplete == false) {
		int choice;
		bool pickedUp; //Pickup Success!
		Knapsack* tempPack = playerHere->usePack();
		spaceOptions();
		do {
			switch (choice = spaceInput()) {
			case 1:
				//Pickup Item if pack not full
				pickedUp = tempPack->addPack(item);
				if (pickedUp) {
					std::cout << "\n**You pick up the Red Gem!**\n";
					specialComplete = true;
					item = NULL; //No item in space
				}
				break;
			case 2:
				std::cout << "\nYou decide to leave. What direction?";
				break;
			default:
				std::cout << "Invalid Menu Choice. Try again.\n\n";
				break;
			}
		} while ((choice != 1) && (choice != 2));
		std::cin.clear(); //Clear cin state
		std::cin.ignore(2, '\n'); //Clear Buffer
	}
}
/*---------------------------------------------------------------------------------*/
// Function: spaceOptions
// Desc: Show Special Options
/*---------------------------------------------------------------------------------*/
void Borders::spaceOptions() {
	std::cout << "1. Pick up the Red Gem!\n";
	std::cout << "2. Leave Area.\n";
	std::cout << "Enter Choice: ";
}