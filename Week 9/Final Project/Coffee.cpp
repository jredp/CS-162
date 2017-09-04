//////////////////// ** Author: Jared Parkinson 
//  Coffee.cpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Coffee.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
/*---------------------------------------------------------------------------------*/
Coffee::Coffee() {
	N = NULL; //North Link
	S = NULL; //South Link
	E = NULL; //East Link
	W = NULL; //West Link	
	playerHere = NULL; //Player in Space
	specialComplete = false;

	//Item: Shield
	std::string tempName = "GreenGem";
	item = new Item(tempName);
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Coffee::~Coffee() {}
/*---------------------------------------------------------------------------------*/
// Function: printSpaceDesc
// Desc: Prints the Space Description to the screen
/*---------------------------------------------------------------------------------*/
void Coffee::printSpaceDesc() {
	//Description based on Special
	if (specialComplete == false) {
		std::cout << "\n***************************************************\n";
		std::cout << "HIPSTER COFFEE SHOP: (Green Gem)\n";
		std::cout << "You enter some sort of Tavern where ragged fellows appear\n";
		std::cout << "to be drinking dark swill. The crowd stares at you as you\n";
		std::cout << "make your way to the Tavern back room. A shiny white bowl\n";
		std::cout << "on the ground shimmers with a green light. It's the Green\n";
		std::cout << "Gem! Reach in the bowl and grab it?\n";
		std::cout << "\n***************************************************\n";
	}
	else {
		std::cout << "\n***************************************************\n";
		std::cout << "HIPSTER COFFEE SHOP: (Green Gem)\n";
		std::cout << "You have already picked up the Green Gem.\n";
		std::cout << "No time to waste! Move on!\n";
		std::cout << "***************************************************\n";
	}
}
/*---------------------------------------------------------------------------------*/
// Function: Special
// Desc: Does Special Actions / Prints if none
/*---------------------------------------------------------------------------------*/
void Coffee::Special() {
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
					std::cout << "\n**You pick up the Green Gem!.**\n";
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
void Coffee::spaceOptions() {
	std::cout << "1. Pick up the Green Gem!\n";
	std::cout << "2. Leave Area.\n";
	std::cout << "Enter Choice: ";
}