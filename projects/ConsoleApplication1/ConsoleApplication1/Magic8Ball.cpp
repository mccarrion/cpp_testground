#include "Magic8Ball.h"
#include <unordered_map>

std::string Magic8Ball::fortune(std::string question)
{
	std::unordered_map<int, std::string> fortune_teller;
	fortune_teller[1] = "No";
	fortune_teller[2] = "Maybe";
	fortune_teller[3] = "Yes";
	fortune_teller[4] = "Someday";
	fortune_teller[5] = "Probably";
	fortune_teller[6] = "Probably Not";
	fortune_teller[7] = "Who knows?";
	fortune_teller[8] = "Nothing";
	fortune_teller[9] = "Something";
	fortune_teller[10] = "Most likely";

	// Opened debugger and rand() is no good. 
	// Need to do more research
	int dice = std::rand() % 10 + 1;

	return fortune_teller[dice];
}
