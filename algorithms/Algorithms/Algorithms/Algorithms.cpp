// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ArrayAlgorithms.h"

/*
 * The idea is to import any class in this solution that has various algorithms in them and 
 * run them through this "main" method to see what input-output looks like.
 */
int main()
{
	ArrayAlgorithms arrayAlgos;
	std::vector<int> nums = { 0, 1, 2, 0, 5, 2, 1 };
	int index = arrayAlgos.dominantIndex(nums);
    std::cout << index;
}
