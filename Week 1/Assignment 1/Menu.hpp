  //////////////////// ** Author: Jared Parkinson 
 //   Menu.hpp     // *** Date: 4/10/2016
//////////////////// **** Desc: Assignment 1

#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
public:
    //Validation
    bool validInput(int size);
	bool validStartX(int xMax, int startX);
	bool validStartY(int yMax, int startY);
	bool validOption(int chosenOption);	
};

#endif