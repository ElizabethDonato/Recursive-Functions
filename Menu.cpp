/************************************************
 * Program Name: menu.cpp
 * Author: Elizabeth Donato
 * Date: 1-20-2018
 * Description: This is the implementation file  
   for the menu class  This class can 
   easily be modified for use by different 
   programs.
************************************************/

#include "Menu.hpp"
#include "ValidInt.hpp"
#include <iostream>

/*************************************************
 * 		Menu::Menu			*
 * 						*
 * This is the constructor for the Menu class.	*
 * It initializes class variables.		*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
Menu::Menu()
{
   testString = "";
   validInput = false;		//Will change to true once valid input has been entered
   lowest = 1;
   highest = 4;		   
}

/*************************************************
 * 		Menu::get_choice		*
 * 						*
 * 						*
 * This function displays a menu of choices 	*
 * for the user and gets the user's choice.	*
 *						*
 * Accepts: Nothing				*
 *          					*
 * Returns: int (user's choice)			*
 * 						*
*************************************************/
int Menu::get_choice()
{
   validInput = false;

   //Gets and validates user's choice
   while(!validInput)
   {
	std::cout << "\n\n  Recursive Functions Menu";
	std::cout << "\n--------------------------------";
	std::cout << "\n1.  Print a String in Reverse";
	std::cout << "\n2.  Calculate the Sum of an Array of Integers";
	std::cout << "\n3.  Calculate the Triangular Number of an Integer";
	std::cout << "\n4.  Exit the Program";

      	std::cout << "\n\nPlease enter your choice:  ";
   	std::getline(std::cin, testString);
	validInput = userInput.is_valid_int_range(testString, lowest, highest);
   }

   //Returns user's choice to client program
   userChoice = userInput.get_int();

   return userChoice;
}


