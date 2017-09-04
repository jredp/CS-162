//////////////////// ** Author: Jared Parkinson 
//    Item.hpp    // *** Date: 4/20/2016
//////////////////// **** Desc: Assignment 2

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
using std::string;

class Item
{
private:
	string itemName; //Item Name
	string unitType; //Unit Type (box, can, pounds, ounces) / Choose Unit 1,2,3,4
	int numToBuy; //Number of units of this item to buy
	double uniPrice; //Price per unit of Item
	double extPrice; //Extended Price (price)*(amount to buy)

public:
	Item(); //Default Constructor
	Item(string nam, string uni, int numBuy, double uniPrice); //Constructor
	~Item(); //Destructor
	bool operator==(string); //Overload

	//Getters
	string getItemName(); //Get Item Name
	string getUnitType(); //Get Unit Type
	int getNumToBuy(); //Get Number of Units to Buy
	double getUniPrice(); //Get Price Per Unit
	double getExtPrice(); //Return ext Price	

	//Setters
	void setItemName(string nameOf); //Set Item Name
	void setUnitType(string type); //Set Unit Type as String
	void setNumToBuy(int numBuy); //Set num to buy
	void setUnitPrice(double price); //Set Unit Price
};

#endif