// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
 * Algorithm #1 a method to reverse a String.
 */
std::string reverseString(std::string in)
{
	std::string out;
	for (int i = in.length() - 1; i >= 0; i--)
	{
		std::string str(1, in.at(i));
		out.append(str);
	}
	return out;
}

/*
 * The idea is to import any class in this solution that has various algorithms in them and 
 * run them through this "main" method to see what input-output looks like.
 */
int main()
{
	std::string hi = reverseString("!dlroW olleH");
    std::cout << hi;
}
