//////////////////// ** Author: Jared Parkinson 
//   Recur.hpp    // *** Date: 4/26/2016
//////////////////// **** Desc: Module 1

#ifndef RECUR_HPP
#define RECUR_HPP

#include <string>
#include "Utility.hpp" //Input Checker

class Recur
{
private:
	//Problem 1 - Enter a string
	std::string prob1Str;

	//Problem 2 - Enter Array of Ints
	int *prob2arr; //Ptr to array	

	//Problem 3 - Enter Rows
	int prob3Rows;

public:
	Utility utilA; //Utility Obj
	Recur(); //Constructor

	//Problem 1 Reverse String
	void reverseString(std::string aString);	
	
	//Problem 2 Calculate Sum - Array/Elements
	int calcSum(int *arr, int elems);
	int* getProb2Arr(); //Get prob 2 array	

	//Problem 3 Triangle Number - Integer
	int triangleNum(int rows);	
};
#endif