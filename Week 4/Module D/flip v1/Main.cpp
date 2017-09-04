//////////////////// ** Author: Jared Parkinson 
//    Main.cpp    // *** Date: 4/28/2016
//////////////////// **** Desc: modD

#include <iostream>
#include "Grid.hpp"

int main()
{
	//Initialization		
	int gridXsize; //User input Grid X Size
	int gridYsize; //User input Grid Y Size
	//int desiredCritters; //User input: Amount of Critters desired
	int desiredAnts; //User input: Amount of Ants desired
	int desiredDbugs; //User input: Amount of Dbugs desired
	int maxDbugsAllowed; //Left over slots after Ants chosen
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

	//Choose Ant Amount
	maxCrittersAllowed = gridXsize*gridYsize; //Set max Critters
	std::cout << "Please choose how many Ants you would like." << std::endl;
	std::cout << "You have from 1 to " << maxCrittersAllowed << " Ants allowed." << std::endl;
	std::cin >> desiredAnts;
	//X Axis Catch
	while (desiredAnts > maxCrittersAllowed) {
		std::cout << "You must choose from 1 to " << maxCrittersAllowed << " Critters" << std::endl;
		std::cin >> desiredAnts;
	}

	/*--------------------------------*/	

	//Choose Doodlebug Amount
	maxCrittersAllowed = gridXsize*gridYsize; //Set max Critters
	maxDbugsAllowed = (maxCrittersAllowed - desiredAnts);
	std::cout << "Please choose how many Doodlebugs you would like." << std::endl;
	std::cout << "You have from 1 to " << maxDbugsAllowed << " Doodlebugs allowed." << std::endl;
	std::cin >> desiredDbugs;
	//X Axis Catch
	while (desiredDbugs > maxCrittersAllowed) {
		std::cout << "You must choose from 1 to " << maxCrittersAllowed << " Critters" << std::endl;
		std::cin >> desiredDbugs;
	}

	/*--------------------------------*/

	//Choose desired Runs
	std::cout << "Please choose how many runs you would like the program to make. (1 or greater)" << std::endl;
	std::cin >> desiredRuns;
	//Runs Catch
	while (desiredRuns < 0) {
		std::cout << "You must choose 1 or greater runs." << std::endl;
		std::cin >> desiredRuns;
	}

	/*--------------------------------*/

	//Create Grid Object 
	Grid critterGrid(gridXsize, gridYsize, desiredAnts, desiredDbugs, desiredRuns);

	system("PAUSE");

	return 0;
}