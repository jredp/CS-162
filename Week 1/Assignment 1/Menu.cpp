  //////////////////// ** Author: Jared Parkinson
 //   Menu.cpp     // ** Date: 4/10/2016
//////////////////// ** Desc: Assignment 1

#include <iostream>
#include "Menu.hpp"
using std::cout;

/*------------------------------------------------------------------------------*/
// Functions: Validators - validSize, 
// Description: Is the Grid Size valid?
/*------------------------------------------------------------------------------*/
bool Menu::validInput(int size) {
	bool valid = true;
	if (size < 1) valid = false;
	return valid;
}
bool Menu::validStartX(int xMax, int startX) {
    bool valid = true;
        if (startX < 1 || startX > xMax) {
			valid = false;
		    //std::cout << "You must choose a starting row from 1 to " << xMax << std::endl;		    
	    }
	return valid;
}
bool Menu::validStartY(int yMax, int startY) {
    bool valid = true;
        if (startY < 1 || startY > yMax) {
			valid = false;
            //std::cout << "You must choose a starting row from 1 to " << yMax << std::endl;		    			
	    }
	return valid;
}
bool Menu::validOption(int chosenOption) {
	bool option = true;	
	    if (chosenOption < 1 || chosenOption > 2) option = false;
	return option;
}