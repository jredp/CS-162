//////////////////// ** Author: Jared Parkinson 
//    List.hpp    // *** Date: 4/20/2016
//////////////////// **** Desc: Assignment 2

#ifndef LIST_HPP
#define LIST_HPP

#include "Item.hpp"

class List
{
private:		
	Item **itemList; //Array of 4 Item Object Pointers	
	int numItemsOnList; //Track number of Items on List
	int numArraySlots; //Track Array Slots available for comparison on addToList
public:
	List(); //Default 4 Objects
	~List(); //Destructor
	void addToList(string nam, string uni, int numBuy, double uniPrice); //Using ItemObj to insert
	void delFromList(string itemName); //Using Name for Lookup	
	void resizeList(int newSize); //Resize new array
	void printList(); //Print current List
	double calcTotalPrice(); //Calculate Total Price of items on list
	bool itemExists(string); //Check for existence using OVERLOAD
};

#endif