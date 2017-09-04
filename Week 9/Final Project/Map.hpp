//////////////////// ** Author: Jared Parkinson 
//    Map.hpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef MAP_HPP
#define MAP_HPP

#include "Afitch.hpp"
#include "Borders.hpp"
#include "Coffee.hpp"
#include "Final.hpp"
#include "Park.hpp"
#include "Space.hpp"
#include "Statue.hpp"
#include "Street.hpp"

#include <random> //Randomizer
#include <memory> //Random Memory Engine Usage

static std::random_device rd; /* http://www.cplusplus.com/reference/random/random_device/operator()/ */
static std::mt19937 engine(rd()); /* http://www.cplusplus.com/reference/random/mt19937/ */

class Map {
private:		
	//Data Mem
	int noSpecS,A,B,C,P,S; //Generate# (Statue, Park, Coffee, Borders, Afitch)
	Space* curSpace; //Currently occupied Space
	Space ***mapArray; //Map Grid of Space Pointers	
	Space* finalSpace; //Final Morphing Space
	Player* player; //Player on the map
	//Func
	Space ***createMapArray(); //Dynamic Creation of 2d Map Array	
	void randSpaceGenerate(); //Generate Spaces in Random Array Slots
	void makeLinkedStruc(); //Make the Linked Structure
	void addLinkSpace(Space* add); //Add
	void remvLinkSpace(Space* remove); //Clear the space and retain the location		
	
public:
	Map(); //Constructor
	~Map(); //Destructor		
	void morphToFinalSpace();//Morph Park space, ***add/remove				
	//Getters
	Space* getDirSpace(char dir); //Get the Space in that direction
	Space* getCurSpace(); //Get the Current Space
	Player* getPlayer(); //Get the Player
	//Setters
	void setCurSpace(Space* setSpace); //Set the Current Space
};

#endif