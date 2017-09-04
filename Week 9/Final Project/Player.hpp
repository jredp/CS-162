//////////////////// ** Author: Jared Parkinson 
//  Player.hpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "Knapsack.hpp"

class Player {
private:
	bool gameWinScene; //Player has won the game
	Knapsack* pack; //Player owned pack
public:
	Player(); //Constructor
	~Player(); //Destructor
	Knapsack* usePack(); //Use the Pack
	void pickupItem(Item* pickup); //Player Picks up Item	
	bool getGameWinScene(); //Check Game Win Scene
	void setGameWin(bool setWin); //Set the Game win
};

#endif