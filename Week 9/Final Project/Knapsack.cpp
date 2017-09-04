//////////////////// ** Author: Jared Parkinson 
//  Knapsack.cpp  // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Knapsack.hpp"

/*------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Generates Knapsack array, init to NULL
/*------------------------------------------------------------------------------*/
Knapsack::Knapsack() {
	//Init Pack size and totalItems
	packSize = 3;
	totalItems = 0;

	//Create Item Array
	packArray = new Item*[packSize]; //New array of size
	for (int arraySlot = 0; arraySlot < packSize; ++arraySlot) {
		packArray[arraySlot] = NULL;	//Set Item Pointers to NULL
	}
}
/*------------------------------------------------------------------------------*/
// Function: Destructor
// Description: Frees memory
/*------------------------------------------------------------------------------*/
Knapsack::~Knapsack() {
	for (int arraySlot = 0; arraySlot < packSize; ++arraySlot) {		
		if (packArray[arraySlot]) {
			delete packArray[arraySlot];	//Set Item Pointers to NULL
		}
	}
	delete [] packArray;
}
/*------------------------------------------------------------------------------*/
// Function: checkPackFull
// Description: Checks if Pack is Full
/*------------------------------------------------------------------------------*/
bool Knapsack::checkPackFull() {
	bool packFull = false;
	if (totalItems == packSize) {
		packFull = true;
	}
	return packFull;
}
/*------------------------------------------------------------------------------*/
// Function: checkPackInv
// Description: Checks pack inventory (print)
/*------------------------------------------------------------------------------*/
void Knapsack::checkPackInv() {
	std::cout << "................................\n";
	std::cout << "Using " << totalItems << " of " << packSize << " slots.\n";
	for (int arraySlot = 0; arraySlot < packSize; ++arraySlot) {
		if (packArray[arraySlot]) {
			std::string nam = packArray[arraySlot]->getItemName();						
			std::cout << arraySlot+1 << ". " << nam << " ";
		}
		else {
			std::cout << arraySlot + 1 << ". " << "<Nothing> ";
		}
	}
	std::cout << "\n................................\n";
}
/*------------------------------------------------------------------------------*/
// Function: addPack
// Description: Adds item to pack
/*------------------------------------------------------------------------------*/
bool Knapsack::addPack(Item* addPack) {
	bool packFull = checkPackFull();
	bool addSuccess = false;		
	
	//If not Full	
	if (packFull == false) {
		//Loop Pack
		for (int arraySlot = 0; arraySlot < packSize; ++arraySlot) {			
			if (packArray[arraySlot] == NULL) {
				packArray[arraySlot] = addPack;
				totalItems++; //Increment Items in Pack
				addSuccess = true;
				break;
			}				
		}			
	}		
	else {
		std::cout << "\n**The pack is full!\n";
		std::cout << "**(Hint: Deposit item(s) in Park, return here.)";
	}
	return addSuccess;
}
/*------------------------------------------------------------------------------*/
// Function: removeItem
// Description: Removes item from pack - checks name
/*------------------------------------------------------------------------------*/
int Knapsack::removeItem(std::string itemName) {
	std::string tempString; //Compare String	
	int remvSuccess = 0;

	//Loop array
	for (int arraySlot = 0; arraySlot < packSize; ++arraySlot) {
		//If slot not NULL, check name, return Item
		if (packArray[arraySlot]) {			
			tempString = packArray[arraySlot]->getItemName(); //Get Item Name
			if (tempString == itemName) {				
				delete packArray[arraySlot]; //Destroy it
				packArray[arraySlot] = NULL; //Reset Slot				
				std::cout << "**Removed " << tempString << ".** ";
				totalItems--;
				remvSuccess = 1;
			}
		}
	}	
	return remvSuccess;
}
/*------------------------------------------------------------------------------*/
// Function: searchPack
// Description: Searches for item in Pack, no remove
/*------------------------------------------------------------------------------*/
bool Knapsack::searchPack(std::string passName) {	
	std::string tempString; //Compare String
	bool itemHere = false;
	
	//Loop array
	for (int arraySlot = 0; arraySlot < packSize; ++arraySlot) {
		//If slot not NULL, check name
		if (packArray[arraySlot]) {
			tempString = packArray[arraySlot]->getItemName(); //Get Item Name
			if (tempString == passName) {
				itemHere = true;
			}
		}
	}	
	return itemHere;
}