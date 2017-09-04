//////////////////// ** Author: Jared Parkinson 
//    Main.cpp    // *** Date: 5/3/2016
//////////////////// **** Desc: Mod E

#include <iomanip>
#include "State.hpp"

int main() {
	/*--------------------------------------------------------------------*/
	//Initializations:	
	/*--------------------------------------------------------------------*/
	int desiredRuns = 0; //Runs	
	int timeUnit=0; //Time is in 4 Minutes per Cycle. 1 minute per light change
	
	//Traffic depart totals for lanes
	int totNCarsDep = 0, totSCarsDep = 0, totECarsDep = 0, totWCarsDep = 0;
	
	//4 States of lights	
	State GreenRed('G','R'), YellowRed('Y','R'), RedGreen('R','G'), RedYellow('R','Y');
	
	//Setup Node Link Cycle
	GreenRed.setNextStateNode(YellowRed);
	YellowRed.setNextStateNode(RedGreen);
	RedGreen.setNextStateNode(RedYellow);
	RedYellow.setNextStateNode(GreenRed);
	
	//Current State
	State *currentState = NULL;
	//First State
	currentState = &GreenRed; 

	/*--------------------------------------------------------------------*/
	//User input
	/*--------------------------------------------------------------------*/
	std::cout << "Please choose desired runs of simulation: 4-8 recommended." << std::endl;
	std::cout << "Each cycle of 4 states is a 4 minutes. 1 min per light change." << std::endl;
	std::cin >> desiredRuns;
	//Valid number?
	while (!std::cin) {
		std::cout << "\nNot a valid number! \nChoose again: ";
		std::cin.clear(); std::cin.ignore(256, '\n');
		std::cin >> desiredRuns;
	}	
	/*--------------------------------------------------------------------*/
	//Loop that goes through Cycle of the states
	//Do this 4 times to complete a 'Whole Cycle'
	//GreenRed is Starting currentState	
	/*--------------------------------------------------------------------*/	
	//Temp Vehicle holders for lanes
	int tempNcars = 0, tempEcars = 0, tempScars = 0, tempWcars = 0;
	int fullCycle = (desiredRuns * 4);	
	for (int i = 0; i < fullCycle; i++) {				
		//Calls both Arrive and Depart and calculates/sets appropriate int
		currentState->setGreenTraffic(); 

		//Print state info
		currentState->printLanes();				

		//Total Departed Cars for each lane
		totNCarsDep += currentState->getNumVehDepart('N');
		totSCarsDep += currentState->getNumVehDepart('S');
		totECarsDep += currentState->getNumVehDepart('E');
		totWCarsDep += currentState->getNumVehDepart('W');		

		//Copy Cars in Lane		
		tempNcars = currentState->getNorLightNumVeh(); //North
		tempScars = currentState->getSouLightNumVeh(); //South
		tempEcars = currentState->getEasLightNumVeh(); //East
		tempWcars = currentState->getWesLightNumVeh(); //West

		//Set Next Node
		currentState = currentState->getNextState();

		//Send Cars in Lane to Next(now current) Node
		currentState->setNorLightNumVeh(tempNcars); //North
		currentState->setSouLightNumVeh(tempScars); //South
		currentState->setEasLightNumVeh(tempEcars); //East
		currentState->setWesLightNumVeh(tempWcars); //West

		timeUnit++;		
	}
	/*--------------------------------------------------------------------*/
	//Time Statistics
	//Per Terry on Forum, using total time/total cars departed is ok
	//4 timeUnits(mins) per cycle.
	/*--------------------------------------------------------------------*/	
	int timeInSec = (timeUnit * 60);  //timUnits*60 = Seconds
	std::cout << "\nTotal Cars Dept North Lane: " << totNCarsDep;
	std::cout << "\nTotal Cars Dept South Lane: " << totSCarsDep;
	std::cout << "\nTotal Cars Dept East Lane: " << totECarsDep;
	std::cout << "\nTotal Cars Dept West Lane: " << totWCarsDep << std::endl;
	std::cout << "\nAverage Time Per N Lane: " << (timeInSec / totNCarsDep) << " seconds.";
	std::cout << "\nAverage Time Per S Lane: " << (timeInSec / totSCarsDep) << " seconds.";
	std::cout << "\nAverage Time Per E Lane: " << (timeInSec / totECarsDep) << " seconds.";
	std::cout << "\nAverage Time Per W Lane: " << (timeInSec / totWCarsDep) << " seconds." << std::endl;
	/*--------------------------------------------------------------------*/

	return 0;
}