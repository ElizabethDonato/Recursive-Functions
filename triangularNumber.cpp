/*************************************************
 * Program Name: triangularNumber.cpp
 * Author: Elizabeth Donato
 * Date: 2-12-2018
 * Description: This is tha implementation file 
 * 		for the triangularNumber function
*************************************************/

#include "triangularNumber.hpp"
/*************************************************
 * 		triangularNumber		*
 * 						*
 * This function uses recursion to calculate 	*
 * the triangular number for a user-entered 	*
 * integer.					*
 * 						*
 * Accepts: int (user-entered)			*
 * 						*
 * Returns: int (triangular number)		*
*************************************************/
int triangularNumber(int userInt)
{
   //Base case:  User enters 1
   if(userInt == 1)
   {
	return 1;
   }

   else
   {
	return (userInt + triangularNumber(userInt - 1));
   }
}

