/*************************************************
 * Program Name: reverseString.cpp
 * Author: Elizabeth Donato
 * Date: 2-11-2018
 * Description: This is the implementation file 
 * 		for the reverseString function.
*************************************************/

#include "reverseString.hpp"
#include <string>


/*************************************************
 *	 	reverseString			*
 *	 					*
 * This function gets an input string from the	*
 * user and then uses recursion to print the  	*
 * string with the characters in reverse order.	*
 * 						*
 * Accepts: string (user-entered)		*
 * 						*
 * Returns: string (characters in reverse order)*
*************************************************/ 
std::string reverseString(std::string userString)
{
   //Base case: the string is empty or has only 1 character
   if(userString.length() <= 1)
   {
	return userString;
   }

   //Reverses the characters of the string
   else
   {
	return  ((userString.back() 						//Returns last character first
		+ (reverseString(userString.substr(1, userString.size() - 2)))  //Reverses middle characters
		+ (userString.front())));					//Returns first character last
   }
}

