/*************************************************
 * Program Name: sumArray.cpp
 * Author: Elizabeth Donato
 * Date: 2-11-2018
 * Description: This is the implementation file
 * 		for the sumArray function.
*************************************************/

#include "sumArray.hpp"

/*************************************************
 * 		sumArray			*
 * 						*
 * This function calculates the sum of an array	*
 * of integers.					*
 * 						*
 * Accepts: int * (pointer to dynamically 	*
 * 		   allocated array of integers) *
 *	    int (size of array)			*
 *						*
 * Returns: int (sum of integers in array)	*	    
*************************************************/
int sumArray(int *userArray, int size)
{
   int arrayVal = 0;		//Sum of values in the array

   //Base case:  If the array is empty, the sum of the values in the array is 0
   if(size == 0)
   {
	return 0;
   }

   //If the array is not empty, uses recursion to calculate the sum of the values in the array
   for(int a = 0; a < size; a++)
   {
	arrayVal = (userArray[size-1] + (sumArray(userArray, (size - 1))));
   }

   return arrayVal;
}
