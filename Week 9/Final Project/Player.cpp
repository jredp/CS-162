//////////////////// ** Author: Jared Parkinson 
//  Player.cpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Player.hpp"

/*-------------------------------------------------*/
// Function: Constructor
/*-------------------------------------------------*/
Player::Player() {
	//Create Dynamic Pack
	pack = new Knapsack();
	gameWinScene = false;
}
/*-------------------------------------------------*/
// Function: Destructor
/*-------------------------------------------------*/
Player::~Player() {
	delete pack;
}
//Setters
/*-------------------------------------------------*/
// Function: pickupItem
// Description: Pick up Item in space
/*-------------------------------------------------*/
void Player::pickupItem(Item* pickup) {	
	pack->addPack(pickup);
}
/*-------------------------------------------------*/
// Function: setGameWin
// Description: Set Player has won the game!
/*-------------------------------------------------*/
void Player::setGameWin(bool setWin) {
	gameWinScene = setWin;
}
//Getters
/*-------------------------------------------------*/
// Function: usePack
// Description: Use Pack Functions
/*-------------------------------------------------*/
Knapsack* Player::usePack() {
	return pack;
}
/*-------------------------------------------------*/
// Function: getGameWinScene
// Description: Tigger final scene!
/*-------------------------------------------------*/
bool Player::getGameWinScene() {
	return gameWinScene;
}
