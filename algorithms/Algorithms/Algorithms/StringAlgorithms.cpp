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

int StringAlgorithms::countLetters(std::string sentence, char letter)
{
	int count = 0;
	for (int i = 0; i < sentence.length(); i++)
	{
		if (letter == sentence.at(i))
		{
			count += 1;
		}
	}
	return count;
}
