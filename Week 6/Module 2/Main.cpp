//////////////////// ** Author: Jared Parkinson 
//    Main.cpp    // *** Date: 5/11/2016
//////////////////// **** Desc: Mod 2

#include <iostream>
#include <unistd.h> //Linux
#include "Menu.hpp"

int main() 
{
	Menu simpleMenu; //Menu Object
	simpleMenu.showSimpleMenu(); //Call Simple Main Menu	
	simpleMenu.runNodeDemo(); //Run the Demo

	return 0;
}