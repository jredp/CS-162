//////////////////// ** Author: Jared Parkinson 
//   Space.hpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Player.hpp"
#include "Item.hpp" //Needed to create Item in Derived

class Space {
protected:	
	Space* N; Space* S; //North - South	Links
	Space* E; Space* W; //East - West Links
	Player* playerHere; //Mark player in this space	
	//Multiple Derived Possible
	bool specialComplete; //Action Completed (All but 1 space type)
	Item* item; //Pointer to Item in this space	
	
public:	
	Space(); //Constructor
	virtual ~Space(); //Destructor		
	virtual void Special() = 0; //Pure Virtual Special Function
	int spaceInput(); //Space input (Identical across spaces)
	virtual void spaceOptions() = 0; //Space Menu item/action (unique)
	virtual void printSpaceDesc() = 0; //Print the Derived Space Desc
	//Getters	
	Space* getSpaceN(); //Get Space N
	Space* getSpaceS(); //Get Space S
	Space* getSpaceE(); //Get Space E
	Space* getSpaceW(); //Get Space W	
	//Setters	
	void setSpace(char dir, Space* set); //Set Space and Direction
	void setPlayerHere(Player* playPtr); //Sets the Player in this space
	void setPlayerLeave(); //Clears Player to NULL

};

#endif