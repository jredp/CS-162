//////////////////// ** Author: Jared Parkinson 
//    Item.cpp    // *** Date: 4/20/2016
//////////////////// **** Desc: Assignment 2

#include "Item.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Default Constructor
// Description: Constructor - Build temp placeholder Item for Dynamic array work
/*---------------------------------------------------------------------------------*/
Item::Item() {
	//Set Item Data Members
	itemName = "";
	unitType = "";
	numToBuy = 0;
	uniPrice = 0;
	extPrice = 0;
}
/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Constructor - Builds item to specifications of User
/*---------------------------------------------------------------------------------*/
Item::Item(string name, string unitTyp, int numBuy, double unitPrice) {
	//Set Item Data Members
	itemName = name;
	unitType = unitTyp;
	numToBuy = numBuy;
	uniPrice = unitPrice;
	extPrice = unitPrice*numBuy;
}
/*---------------------------------------------------------------------------------*/
// Function: Desructor
// Description: Destructor
/*---------------------------------------------------------------------------------*/
Item::~Item() {		
}
/*---------------------------------------------------------------------------------*/
// Function: OVERLOAD operator ==
// Description: Overloads the == operator to check for duplicates
/*---------------------------------------------------------------------------------*/
bool Item::operator== (string name) {
	bool nameSame = false;	
	string passName = name;
	string origName = itemName;
	//Check for name
	if (passName == origName) {
		nameSame = true;
	}
	return nameSame;
}

//Getters
/*---------------------------------------------------------------------------------*/
// Function: getItemName
// Description: Gets the Item Name
/*---------------------------------------------------------------------------------*/
string Item::getItemName() {
	return itemName;
}
/*---------------------------------------------------------------------------------*/
// Function: getUnitType
// Description: Gets the unit type of the Item
/*---------------------------------------------------------------------------------*/
string Item::getUnitType() {
	return unitType;
}
/*---------------------------------------------------------------------------------*/
// Function: getNumToBuy
// Description: Gets the number of items to buy
/*---------------------------------------------------------------------------------*/
int Item::getNumToBuy() {
	return numToBuy;
}
/*---------------------------------------------------------------------------------*/
// Function: getUnitPrice
// Description: Gets the unit price of the Item
/*---------------------------------------------------------------------------------*/
double Item::getUniPrice() {
	return uniPrice;
}
/*---------------------------------------------------------------------------------*/
// Function: getExtPrice
// Description: Gets total (price)*(amount to buy) of item
/*---------------------------------------------------------------------------------*/
double Item::getExtPrice() {	
	return extPrice;
}

//Setters
/*---------------------------------------------------------------------------------*/
// Function: setItemName
// Description: Sets the Item Name
/*---------------------------------------------------------------------------------*/
void Item::setItemName(string name) {
	itemName = name;
}
/*---------------------------------------------------------------------------------*/
// Function: setUnitType
// Description: Sets the Item Unit Type
/*---------------------------------------------------------------------------------*/
void Item::setUnitType(string typ) {
	unitType = typ;
}
/*---------------------------------------------------------------------------------*/
// Function: setNumToBuy
// Description: Sets the Item Number to Buy
/*---------------------------------------------------------------------------------*/
void Item::setNumToBuy(int toBuy) {
	numToBuy = toBuy;
}
/*---------------------------------------------------------------------------------*/
// Function: setUniPrice
// Description: Sets the Item Unit Price
/*---------------------------------------------------------------------------------*/
void Item::setUnitPrice(double unitPrice) {
	uniPrice = unitPrice;
}