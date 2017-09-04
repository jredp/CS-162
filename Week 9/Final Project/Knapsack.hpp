//////////////////// ** Author: Jared Parkinson 
//  Knapsack.hpp  // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <string>
#include "Item.hpp"

class Knapsack {
private:	
	Item **packArray; //Array of pack Slots
	int packSize; //Pack Size
	int totalItems; //Items in Pack
	
public:
	Knapsack(); //Constructor
	~Knapsack(); //Destructor
	bool checkPackFull(); //Check if pack full
	void checkPackInv(); //Check Pack Inv (print)
	bool searchPack(std::string passName); //Search Pack for item, no remove
	bool addPack(Item* addItem); //Add item to pack
	int removeItem(std::string itemName); //Remove Item from pack
	
};

#endif