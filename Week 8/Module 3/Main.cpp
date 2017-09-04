//////////////////// ** Author: Jared Parkinson 
//    Main.cpp    // *** Date: 5/25/2016
//////////////////// **** Desc: Mod 3

#include <iomanip>
#include "State.hpp"
#include "Queue.hpp"

int main() {
	/*--------------------------------------------------------------------*/
	//Initializations:		
	/*--------------------------------------------------------------------*/
	int desiredRuns = 0; //Runs	
	int timeUnit; //Time is in 4 Minutes per Cycle. 1 minute per light change

	//4 States of lights	
	State GreenRed('G', 'R'), YellowRed('Y', 'R'),
		  RedGreen('R', 'G'), RedYellow('R', 'Y');

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
	std::cout << "Each cycle of 4 states is a 4 minutes. 1 min(time unit) per light change." << std::endl;
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
	int totNCarsDep = 0, totSCarsDep = 0, totECarsDep = 0, totWCarsDep = 0;
	int fullCycle = (desiredRuns * 4);
	for (timeUnit =0; timeUnit < fullCycle; timeUnit++) {
		//Calls both Arrive and Depart and calculates/sets appropriate ints
		currentState->setGreenTraffic(timeUnit);

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
	}
	/*--------------------------------------------------------------------*/
	//Time Statistics
	//Per Terry, this is Total Wait Sum: (iteration - timeStamp removed) 
	// for each car summed over the life of the run.
	// Then: Lane Wait Sum / Total Cars Departed
	// * 60 on wait due to each wait # being 1 minute (seconds)
	/*--------------------------------------------------------------------*/
	//Wait Sums
	int waitN, waitS, waitE, waitW;
	waitN = GreenRed.getWaitSumLane1();
	waitS = GreenRed.getWaitSumLane2();
	waitE = RedGreen.getWaitSumLane1();
	waitW = RedGreen.getWaitSumLane2();

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Time Units: " << timeUnit << " Cycles (4 time units): " << (timeUnit / 4);
	std::cout << "\n--------------------------------" << std::endl;
	std::cout << "Total Cars Dept North Lane: " << totNCarsDep;
	std::cout << "\nTotal Cars Dept South Lane: " << totSCarsDep;
	std::cout << "\nTotal Cars Dept East Lane: " << totECarsDep;
	std::cout << "\nTotal Cars Dept West Lane: " << totWCarsDep << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "North Wait Sum: " << waitN;
	std::cout << "\nSouth Wait Sum: " << waitS;
	std::cout << "\nEast Wait Sum: " << waitE;
	std::cout << "\nWest Wait Sum: " << waitW;
	std::cout << "\n--------------------------------" << std::endl;
	std::cout << "Avg Wait North Lane: " << ((waitN * 60) / totNCarsDep) << " seconds.";
	std::cout << "\nAvg Wait South Lane: " << ((waitS * 60) / totSCarsDep) << " seconds.";
	std::cout << "\nAvg Wait East Lane: " << ((waitE * 60) / totECarsDep) << " seconds.";
	std::cout << "\nAvg Wait West Lane: " << ((waitW * 60) / totWCarsDep) << " seconds." << std::endl;
	std::cout << "--------------------------------" << std::endl;
	/*--------------------------------------------------------------------*/

	return 0;
}