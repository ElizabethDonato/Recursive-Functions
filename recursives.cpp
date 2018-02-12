/*************************************************
 * Program Name: recursives.cpp
 * Author: Elizabeth Donato
 * Date: 2-11-2018
 * Description: This program allows the user to
 * 		implement one of 3 recursive
 * 		functions.
*************************************************/

#include "Menu.hpp"
#include "ValidInt.hpp"
#include "UserInput.hpp"
#include "reverseString.hpp" 
#include "sumArray.hpp"	
#include "triangularNumber.hpp"

#include <iostream>
#include <string>

int main()
{
   //Instantiates needed objects
   Menu userMenu;
   UserInput arrayInt;
   UserInput numInts;
   UserInput triNum;

   //Variables to manage program
   bool runProgram = true;			//Indicates exit status of program
   int menuChoice;				//User-entered menu choice

   //Variables for reverseString funciton
   std::string myString;		

   //Variables for sumArray function
   int currentArraySize = 0;	
   int maxArraySize = 0;
   int *myArray;
   std::string newInt;

   //Variables for triangularNumber function
   int myTriInt = 0;				
   int calcTriInt = 0;


   //Loops to run program until the user chooses to exit
   while(runProgram)
   {
	menuChoice = userMenu.get_choice();
   
   	switch(menuChoice)
   	{
		//User chooses to print a user-entered string in reverse
   		case 1: std::cout << "\nPlease enter a string and I will print it in reverse." << std::endl;
			std::getline(std::cin, myString);
			std::cout << "\nYou entered this string:      " << myString << std::endl;
			std::cout << "This is your reversed string: " << reverseString(myString) << std::endl;
			break;

		case 2: std::cout << "\nEnter between 0 and 50 integers and I will tell you their sum." << std::endl;
			//Gets and validates user input
			std::cout << "How many integers would you like to enter?" << std::endl;
			maxArraySize = numInts.get_input(0, 50);
			
			//Dynamically allocates array of ints
			myArray = new int[maxArraySize];

			std::cout << "\nEnter integers between 0 and 500,000 to fill the array." << std::endl;
			std::cout << "Press enter after entering each integer." << std::endl;

			//While array is not full and user is entering valid integers
			for(int a = 0; a < maxArraySize; a++)
			{
			   //Get and validate integers and store in array
			   myArray[currentArraySize] = arrayInt.get_input();
			   currentArraySize++;	
			}
			
			//Prints values entered into array and then the sum of all values entered into the array
			std::cout << "\nYou entered the following values into the array:  " << std::endl;
			for(int v = 0; v < currentArraySize; v++)
			{
		   	   std::cout << myArray[v] << " ";
			}
			
			std::cout << "\n\nSum of values stored in array:  " << sumArray(myArray, currentArraySize) << std::endl;
			//Resets array counters so function can be called again
			currentArraySize = 0;
			maxArraySize = 0;
			break;

			//Deletes dynamic array
			delete []myArray;
			myArray = 0;
			
		case 3: std::cout << "\nPlease enter an integer between 1 and 100 and I will tell you it's triangular number." << std::endl;
			//Gets user input
			myTriInt = triNum.get_input(1,100);
			//Calculates triangular number
			calcTriInt = triangularNumber(myTriInt);
			//Prints results
			std::cout << "\nThe triangular number for " << myTriInt << " is " 
				  << calcTriInt << "." << std::endl;
			break;

		case 4: std::cout << "\nYou have chosen to exit the program.  Good Bye." << std::endl << std::endl;
			//Sets boolean value so program will terminate
			runProgram = false;
			break;
   	}
   }

   return 0;
}	
