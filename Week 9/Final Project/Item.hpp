//////////////////// ** Author: Jared Parkinson 
//    Item.hpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>

class Item {
private:	
	std::string itemName; //Item Name
public:	
	Item(std::string itName); //Constructor
	~Item(); //Destructor
	std::string getItemName(); //Return item name
};

#endif