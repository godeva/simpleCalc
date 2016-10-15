#include <stdio.h>
#include <stdlib.h>
/*Stores function prototype and classes for GeneralNumber.cpp*/
#include "GeneralNumber.h"


/** Program runs a simple calculator which lets a user type in GeneralNumbers and operators for manipulating them.
*/

int main() { // Runs calculator program
  int inputCheck = 0; // Input not yet good
  printf("Simple GeneralNumber Calculator\n"); // Tells user what the program is!

  while(!inputCheck) { //Terminates when no value is entered for first argument
    inputCheck = GeneralNumber::Prompt(); // Allows for function to loop if zero is returned because of error
  }

  printf("Thank You for using my calculator, GoodBye!\n"); // Indicate to the user that the program has exited
}
