//////////////////// ** Author: Jared Parkinson 
//    List.cpp    // *** Date: 4/20/2016
//////////////////// **** Desc: Assignment 2

#include "List.hpp"
#include <iomanip>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Constructor - Builds array list with default size 4 and 0 items
/*---------------------------------------------------------------------------------*/
List::List() {
	numItemsOnList = 0; //Set number of items on list to 0
	numArraySlots = 4; //Set Array available slots to 4		
	itemList = new Item*[numArraySlots]; //Dynamic array of 4 default slots

	//Set 4 slots to NULL as there are no items yet
	for (int arraySlot = 0; arraySlot < 4; ++arraySlot) {		
		itemList[arraySlot] = NULL;	//Set Item Pointers to NULL
	}		
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
// Description: Cleans memory of the Dynamic Array
/*---------------------------------------------------------------------------------*/
List::~List() {
	delete [] itemList;
}
/*---------------------------------------------------------------------------------*/
// Function: addToList
// Description: Adds new Item to List
/*---------------------------------------------------------------------------------*/
void List::addToList(string nam, string uni, int numBuy, double uniPrice) {	
	Item *newItem = new Item(nam, uni, numBuy, uniPrice); //Make new Item using input
	if (itemExists(nam) == true) {		
		std::cout << "\n*****WARNING: That Item already exists!!*****\n\n" << std::endl;
	}
	else {
		//While array size is 4 but items on list is less
		if (numArraySlots > numItemsOnList) {			
			itemList[numItemsOnList] = newItem; //Add item pointer to List - no offset
			++numItemsOnList; //Increment Items on List
		}
		//Else new dynamic array +1 larger
		else {
			int newArraySize = numArraySlots + 1; //Set new Size
			resizeList(newArraySize); //Increae slot 1
			++numArraySlots; //increment Array Size		
			itemList[newArraySize-1] = newItem; //Add new item to List - offset -1
			++numItemsOnList; //Increment Items on List
		}		
	}	
}

/*---------------------------------------------------------------------------------*/
// Function: delFromList
// Description: Deletes desired Item from List
/*---------------------------------------------------------------------------------*/
void List::delFromList(string itemName) {
	bool itemExist = itemExists(itemName);
	//If Item is there (overload check)
	if (itemExist == true) {
		//Cycle Array
		for (int listSlot = 0; listSlot < numArraySlots; listSlot++) {
			//If item slot is occupied
			if (itemList[listSlot] != NULL) {
				//Check name then Null item slot
				if (itemList[listSlot]->getItemName() == itemName) {
					itemList[listSlot] = NULL; //Clear the item
					--numItemsOnList;
				}
			}
		}
	}	
}
/*---------------------------------------------------------------------------------*/
// Function: calcTotalPrice
// Description: Calculates the total price of items on List * their respective units
/*---------------------------------------------------------------------------------*/
double List::calcTotalPrice() {
	double listTotalPrice = 0; //Init to 0 price

	//Set listTotalPrice iterate through items
	for (int itemSlot = 0; itemSlot < numItemsOnList; itemSlot++) {
		if (itemList[itemSlot] != NULL) //If slot occupied
			listTotalPrice += itemList[itemSlot]->getExtPrice(); //Get Ext Price		
	}
	return listTotalPrice;
}
/*---------------------------------------------------------------------------------*/
// Function: resizeList
// Description: Make new array of size, copy original, set new list, delete old
/*---------------------------------------------------------------------------------*/
void List::resizeList(int newSiz) {
	Item **tempList = new Item*[newSiz];
	
	//Setup tempList
	for (int arraySlot = 0; arraySlot < newSiz; ++arraySlot)
		tempList[arraySlot] = NULL;	
	
	//Copy List	
	for (int listSlot = 0; listSlot < numArraySlots; listSlot++) {				
		tempList[listSlot] = itemList[listSlot];		
	}	
	itemList = tempList; //Set new itemList	
}
/*---------------------------------------------------------------------------------*/
// Function: printList
// Description: Print list to Console Display
/*---------------------------------------------------------------------------------*/
void List::printList() {	
	if (numItemsOnList <= 0) {
		std::cout << "\nYou have not items in your Cart!\n" << std::endl;
	}
	else {
		//Print Column Headers - Set max width of columns to make "pretty"
		std::cout << std::setw(25) << std::left << "NAME" << std::setw(10) << std::left << "TYPE";
		std::cout << std::setw(8) << std::left << "#BUY" << std::setw(10) << std::left << "PRICE" << std::endl;
		std::cout << "------------------------------------------------\n" << std::endl;

		for (int listSlot = 0; listSlot < numArraySlots; listSlot++) {			
			//If slot not NULL, begin print
			if (itemList[listSlot] != NULL) { 
				//Init variables for ease of Print
				string name = itemList[listSlot]->getItemName(); 
				string uniType = itemList[listSlot]->getUnitType(); 
				int numBuy = itemList[listSlot]->getNumToBuy(); 
				double price = itemList[listSlot]->getUniPrice(); 

				//Print in a Column Format
				std::cout << std::setw(25) << std::left << name << std::setw(10) << std::left << uniType;
				std::cout << std::setw(8) << std::left << numBuy << std::setw(10) << std::left << price << std::endl;
			}			
		}
		std::cout << "\nTOTAL COST: " << std::fixed << std::setprecision(2) << calcTotalPrice() << "\n\n";
	}	
}
/*---------------------------------------------------------------------------------*/
// Function: itemExists
// Description: Check if item exists
/*---------------------------------------------------------------------------------*/
bool List::itemExists(string name) {
	bool itemExists = false; //Default: name doesn't exist
	
	//Check possible Item name against current Item name in slot
	for (int listSlot = 0; listSlot < numArraySlots; listSlot++) {
		//If slot occupied
		if (itemList[listSlot] != NULL) {
			itemExists = itemList[listSlot]->operator==(name); //Use OVERLOADED == from Item Class
			if (itemExists)	return itemExists; //return if found to stop iteration
		}
	}
	return itemExists;
}
