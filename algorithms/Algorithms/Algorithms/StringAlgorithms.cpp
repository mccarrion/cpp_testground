#include "StringAlgorithms.h"

/*
 * Algorithm #1 a method to reverse a String.
 */
std::string StringAlgorithms::reverseString(std::string in)
{
	std::string out;
	for (int i = in.length() - 1; i >= 0; i--)
	{
		std::string str(1, in.at(i));
		out.append(str);
	}
	return out;
}
