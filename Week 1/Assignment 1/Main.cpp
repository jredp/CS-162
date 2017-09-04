  //////////////////// ** Author: Jared Parkinson 
 //    Main.cpp    // *** Date: 4/10/2016
//////////////////// **** Desc: Assignment 1

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;

#include "Menu.hpp"
#include "Grid.hpp"

int main()
{
	//Initialization
	Ant AntA; //Create Ant
	Menu MenuA; //Create Menu
	int xSize; //User input Grid X Size
	int ySize; //User input Grid Y Size	
	int startX; //If choosing starting X
	int startY; //If choosing starting Y
	int desiredRuns; //Ant Moves
	int optionChosen; //Menu Option

	/*--------------------------------*/

	//Ask for Grid Size
	std::cout << "Please enter the Grid Size. Recommend at least 80x80 fullscreen console." << std::endl;
	std::cout << "Enter the number of Rows (Height)" << std::endl;
	std::cin >> xSize;	
	//X Size Catch
	while (MenuA.validInput(xSize) == false) {
		std::cout << "You must choose a size of 1 or higher. Recommend at least 80x80 fullscreen console." << std::endl;
		std::cout << "Enter the number of Rows (Height)" << std::endl;
		std::cin >> xSize;
	}
	std::cout << "Enter the number of Columns (Width)" << std::endl;
	std::cin >> ySize;
	//Y Size Catch
	while (MenuA.validInput(ySize) == false) {
		std::cout << "You must choose a size of 1 or higher. Recommend at least 80x80 fullscreen console." << std::endl;
		std::cout << "Enter the number of Columns (Width)" << std::endl;
		std::cin >> ySize;
	}	

	/*--------------------------------*/

	//Choose desired Runs
	std::cout << "Please choose how many runs you would like the program to make. (1 or greater). Recommend 12,000." << std::endl;
	std::cin >> desiredRuns;	
	//Runs Catch
	while (MenuA.validInput(desiredRuns) == false) {
		std::cout << "You must choose 1 or greater runs. Recommend at least 11000+ fullscreen console." << std::endl;
		std::cin >> desiredRuns;
	}

	//Create Grid Object after desiredRuns and Size are input
	Grid GridA(xSize, ySize, desiredRuns); //Create and initialize to white squares

	/*--------------------------------*/

	//Choose Random or Chosen Start
	std::cout << "Please choose 1: Random Start Location or 2: User Chosen Location." << std::endl;
	std::cin >> optionChosen;
	while (std::cin.fail()) {
		std::cout << "You must choose a digit 1 or 2." << std::endl;
		std::cin >> optionChosen;
	}
	while (MenuA.validOption(optionChosen) == false) {
		std::cout << "You must choose 1 or 2 as an option." << std::endl;
		std::cin >> optionChosen;
	}
    	if (optionChosen == 1) {
			std::cout << "Random Start: Program will begin now." << std::endl;
			//Random Ant Start			
			GridA.setRandStartAntGrid(AntA);
		}
		else if (optionChosen == 2) {
			//Choose Ant '*' Starting location: X(start row #) and Y(start column #)
			std::cout << "Please choose your Ant(*) Starting Location. Must be 1/1 or greater." << std::endl;
			//X Axis Starting Location
			std::cout << "What Row? (X Axis - Height)" << std::endl;
			std::cout << "You have from 1 to " << xSize << " rows to choose from." << ". Recommend middle of Grid." << std::endl;
			std::cin >> startX;
			//Catch using Menu Function
			while (MenuA.validStartX(xSize, startX) == false) {
				std::cout << "You must choose a starting row from 1 to " << xSize << ". Recommend middle of Grid." << std::endl;
				std::cin >> startX;
			}
			//Y Axis Starting Location
			std::cout << "What Column? (Y Axis - Width)" << std::endl;
			std::cout << "You have from 1 to " << ySize << " columns to choose from." << ". Recommend middle of Grid." << std::endl;
			std::cin >> startY;
			//Catch using Menu Function
			while (MenuA.validStartY(ySize, startY) == false) {
				std::cout << "You must choose a starting row from 1 to " << ySize << ". Recommend middle of Grid." << std::endl;
				std::cin >> startY;
			}
			//Set User Chosen Ant Start
			GridA.setUserStartAntGrid(AntA, startX, startY);
		}
	

	/*--------------------------------*/

	//Begin Runs
	GridA.makeMoves(AntA);	

	return 0;
}