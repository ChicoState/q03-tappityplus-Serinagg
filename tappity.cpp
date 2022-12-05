#include "tappity.h"
#include <stdexcept>
#include <cmath>
using namespace std;
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(string reference)
{
	if(reference.length() != 0)
	{
		refer = reference;
		user_in = "";
	}
	else
		throw invalid_argument("no reference phrase inputed.");
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
	if(user_in.length() == 0)
		user_in = input;
	else
		throw invalid_argument("input already gathered.");
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  return abs(int(refer.length() - user_in.length()));
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
	double matches = 0;
	double total = 0;
	double accurate = 0;
	if(length_difference() == 0 || refer.length() < user_in.length())
	{
		total = user_in.length();
		for(int i = 0; i < refer.length(); i++)
		{
			if(refer[i] == user_in[i])
				matches++;
		}
	}
	else
	{
		if(user_in.length() < refer.length())
		{
			total = refer.length();
			for(int i = 0; i < user_in.length(); i++)
			{
				if(user_in[i] == refer[i])
					matches++;
			}
		}
	}
	accurate = ((matches/total) *100);
  return accurate;
}
