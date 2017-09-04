//////////////////// ** Author: Jared Parkinson 
//    Main.cpp    // *** Date: 6/2/2016
//////////////////// **** Desc: Mod 4

#include <iostream>
#include <string>
#include <time.h>
/*-----------------------------------*/
#include "Fib.hpp" //Borrowed Code
/*------------------------------------------------------------------------------*/
// Fib.hpp and Fib.cpp are modified versions of code from:
// http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
// This code was mainly written by joseph.arul83@gmail.com
/*------------------------------------------------------------------------------*/

//Quick Declares
unsigned long long int rfactorial(unsigned long long int n);
unsigned long long int factorialHelper(unsigned long long int n, unsigned long long int result);
unsigned long long int factorial(unsigned long long int n);
double clockCheck(double start);
int getInput();
void showMainMenu();

/*------*/
// MAIN
/*------*/
int main()
{	
	unsigned long long int n = 0; //Per Diana Bacon Forum
	unsigned long long int fact = 0;
	unsigned long long int rfact = 0;

	//Enter N
	std::cout << "Enter desired N: " << std::endl;
	n = getInput();

	//Choose Menu
	showMainMenu();	
	//Clock Setup
	clock_t startTime;
	double totalTime;
	int input = 0;	

	do {		
		switch (getInput()) {		
		case 1:
			for (unsigned int iter = 1; iter < n; iter++) {
				std::cout << "--------\n";
				std::cout << iter << "\n--------\n";
				//Fib Non Rec
				startTime = clock(); //Set Starting Clock
				FibonacciNR nonRec = FibonacciNR(); //Create NonRecursive
				nonRec.PrintFibonacci(iter);
				totalTime = clockCheck(startTime);
				std::cout << "Fib Non Rec Time: " << totalTime << std::endl;
				//Fib Rec	
				startTime = clock(); //Set Starting Clock
				FibonacciR rec = FibonacciR(); //Create Recursive
				rec.PrintFibonacci(iter);
				totalTime = clockCheck(startTime);
				std::cout << "Fib Rec Time: " << totalTime << std::endl;
			}
			input = 3;
			break;
		case 2:
			std::cout << "\n--------\n";
			std::cout << "FACTORIALS\n";
			std::cout << "--------\n";
			//rfactorial
			startTime = clock();			
			rfact = rfactorial(n);			
			totalTime = clockCheck(startTime);
			std::cout << "rfactorial Time: " << totalTime << " Num: " << rfact << std::endl;
			//factorial
			startTime = clock();			
			fact = factorial(n);
			totalTime = clockCheck(startTime);
			std::cout << "factorial Time: " << totalTime << " Num: " << fact << std::endl;
			input = 3;
			break;
		default:			
			std::cout << "Invalid Menu Choice. Try again.\n\n";
			showMainMenu();
			break;
		}
	} while (input != 3);		

	return 0;
}

/*-----------------------------------*/
// Functions: factorials
// Desc: Code by Terry - Minor Changes
/*-----------------------------------*/
unsigned long long int rfactorial(unsigned long long int n) {
	if (n == 1)
		return 1;
	else
		return n * rfactorial(n - 1);
}
unsigned long long int factorialHelper(unsigned long long int n, unsigned long long int result) {
	if (n == 1)
		return result;
	else
		return factorialHelper(n - 1, n*result);
}
unsigned long long int factorial(unsigned long long int n) {
	return factorialHelper(n, 1);
}
/*-----------------------------------*/
// Functions: clockCheck
// Desc: Checks the Clock
/*-----------------------------------*/
double clockCheck(double start) {
	double timeChunk = (clock() - start);
	double totTime = timeChunk / (double)CLOCKS_PER_SEC;
	return totTime;
}
/*-----------------------------------*/
// Functions: getInput
// Desc: Menu Num
/*-----------------------------------*/
int getInput() {
	int inputs = 0;
	std::cin >> inputs;
	//Valid number?
	while (!std::cin) {
		std::cout << "\nNot a valid number! \nChoose again: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> inputs;
	}		
	return inputs;
}
/*---------------------------------------------------------------------------------*/
// Function: showMainMenu
// Description: Show the Main Menu
/*---------------------------------------------------------------------------------*/
void showMainMenu() {
	std::cout << "\n-----MAIN MENU-----\n";
	std::cout << "Choose from the following options:\n";
	std::cout << "1. Fib Numbers\n";
	std::cout << "2. Factorials\n";
	std::cout << "Enter Choice: ";
}