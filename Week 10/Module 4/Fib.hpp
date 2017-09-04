//////////////////// ** Author: Jared Parkinson 
//    Fib.hpp     // *** Date: 6/2/2016
//////////////////// **** Desc: Mod 4  

#ifndef FIB_HPP
#define FIB_HPP

#include <iostream>

//Non recursive
class FibonacciNR {
public:
	FibonacciNR();	
	virtual ~FibonacciNR();
	void PrintFibonacci(unsigned long long int printN);
private:	
	unsigned long long int Fibonacci(unsigned long long int passN);	
};

//Recursive
class FibonacciR {
public:
	FibonacciR();
	virtual ~FibonacciR();
	void PrintFibonacci(unsigned long long int printN);
private:	
	unsigned long long int Fibonacci(unsigned long long int passN);
};

#endif