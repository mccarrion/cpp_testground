// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StringAlgorithms.h"

/*
 * The idea is to import any class in this solution that has various algorithms in them and 
 * run them through this "main" method to see what input-output looks like.
 */
int main()
{
	StringAlgorithms stringAlgos;
	std::string hi = stringAlgos.reverseString("!dlroW olleH");
    std::cout << hi;
}
