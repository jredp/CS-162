//////////////////// ** Author: Jared Parkinson 
//    Main.cpp    // *** Date: 4/10/2016
//////////////////// **** Desc: modB week2

#include <iostream>
#include "Grid.hpp"

int main()
{
	//Initialization		
	int gridXsize; //User input Grid X Size
	int gridYsize; //User input Grid Y Size
	int desiredCritters; //User input: Amount of Critters desired
	int maxCrittersAllowed; //Critters cannot be > than Grid Size (xSize*ySize)
	int desiredRuns; //User input: How many moves to make?		

	/*--------------------------------*/

	//Ask for Grid Size
	std::cout << "Please enter the Grid Size." << std::endl;
	std::cout << "Enter the number of Rows (Height)" << std::endl;
	std::cin >> gridXsize;
	//X Size Catch
	while (gridXsize < 1) {
		std::cout << "You must choose a size of 1 or higher." << std::endl;
		std::cout << "Enter the number of Rows (Height)" << std::endl;
		std::cin >> gridXsize;
	}

	std::cout << "Enter the number of Columns (Width)" << std::endl;
	std::cin >> gridYsize;
	//Y Size Catch
	while (gridYsize < 1) {
		std::cout << "You must choose a size of 1 or higher." << std::endl;
		std::cout << "Enter the number of Columns (Width)" << std::endl;
		std::cin >> gridYsize;
	}

	/*--------------------------------*/

	//Choose Critter Amount
	maxCrittersAllowed = gridXsize*gridYsize; //Set max Critters
	std::cout << "Please choose how many Critters you would like." << std::endl;
	std::cout << "You have from 1 to " << maxCrittersAllowed << " Critters allowed." << std::endl;
	std::cin >> desiredCritters;
	//X Axis Catch
	while (desiredCritters > maxCrittersAllowed) {
		std::cout << "You must choose from 1 to " << maxCrittersAllowed << " Critters" << std::endl;
		std::cin >> desiredCritters;
	}

	/*--------------------------------*/

	//Choose desired Runs
	std::cout << "Please choose how many runs you would like the program to make. (1 or greater)" << std::endl;
	std::cin >> desiredRuns;
	//Runs Catch
	while (desiredCritters < 0) {
		std::cout << "You must choose 1 or greater runs." << std::endl;
		std::cin >> desiredRuns;
	}

	/*--------------------------------*/

	//Create Grid Object 
	Grid critterGrid(gridXsize, gridYsize, desiredCritters, desiredRuns);	

	return 0;
}