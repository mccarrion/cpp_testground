#include "ArrayAlgorithms.h"

/*
 * This is a solution for LeetCode problem 747:
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/
 */
int ArrayAlgorithms::dominantIndex(std::vector<int>& nums)
{
	// Track size
	int biggest = 0;
	int second_biggest = 0;

	// Track location
	int loc_biggest = 0;

	for (int i = 0; i < nums.size(); i++) 
	{
		if (biggest < nums[i])
		{
			second_biggest = biggest;

			biggest = nums[i];
			loc_biggest = i;
		}

		if (nums[i] < biggest && nums[i] > second_biggest) 
		{
			second_biggest = nums[i];
		}
	}

	if (biggest >= (second_biggest * 2)) 
	{
		return loc_biggest;
	}
	else 
	{
		return -1;
	}
}
