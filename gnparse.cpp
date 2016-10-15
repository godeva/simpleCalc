#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Allows program to recognizes readline*/
#include <readline/readline.h>
/*Allows program to recognizes readline*/
#include <readline/history.h>
/*Stores function prototype and classes for and gnparse.cpp & GeneralNumber.cpp*/
#include "GeneralNumber.h"

/** File stores functions Parse, Prompt, and Calculate to run calc.cpp for calc executable
*/

// Static methods:

/** Parses a string representing a GeneralNumber
* @param s The string to parse
* @return Pointer to a newly-allocated object of the correct subclass,
* or null pointer if unable to parse.
*/

GeneralNumber* GeneralNumber::parse(const char* s) { // Runs Program

  GeneralNumber* newobj = NULL;
  long n1, n2; // Numbers parsed from the command line
  int nconv; // Number of successful conversions

  // Try to match the input format, then create the right type object.

  // First look for GeneralRational format
  nconv = sscanf(s, " [ %ld / %ld ]", &n1, &n2);
  if (nconv == 2) { // Recognized!
    newobj = new GeneralRational(n1, n2);
    return newobj;
  }

  // Next look for GeneralDouble format
  if (strchr(s, '.') != NULL) { // Recognized!
    newobj = new GeneralDouble(atof(s));
    return newobj;
  }

  // Next look for GeneralLong format
  nconv = sscanf(s, "%ld", &n1);
  if (nconv == 1) { // Recognized!
    newobj = new GeneralLong(n1);
    return newobj;
  }

  return NULL; // Nothing recognized
}

/** Ask the user to enter two GeneralNumbers and an operation, exits if blank is entered for
* either prompts of GeneralNumbers and checks if the arguments entered for all three values are valid
* @return String of the calculated value and it's operation if correcttly entered, otherwise zero
*/

int GeneralNumber::Prompt() { // Runs program
  int inputCheck = 0; // Input not yet good
  char opperator; // String for operator

  char* numberOne = readline("Enter first argument (blank to exit): ");
  GeneralNumber* numValOne = GeneralNumber::parse(numberOne); // Converts string input to data type number

  if (strlen(numberOne) == 0) { // Terminates program if nothing is entered
    return 1;
  }

  if (numValOne == NULL) { // Loops first paramter if invalid number
    printf("Invalid number, please try again\n");
    return 0;
  }

  char* opp = readline("Enter operator: ");
  opperator = opp[0]; // Sets operator to first element of entered array

  if (opperator != '+' && opperator != '-' && opperator != '*' && opperator != '/') { // Terminates if invalid operator
    printf("Invalid operator, please try again\n");
    return 0;
  }

  char* numberTwo = readline("Enter second argument (blank to exit): ");
  GeneralNumber* numValtwo = GeneralNumber::parse(numberTwo); // Converts string input to data type number

  if (strlen(numberTwo) == 0) { // Terminates program if nothing is entered
    return 1;
  }

  if (numValtwo == NULL) {  // Loops first paramter if invalid number
    printf("Invalid number, please try again\n");
    return 0;
  }

  char* result = GeneralNumber::Calculate(numValOne, numValtwo, opperator); // Returns calculated value in string form
  printf("%s %c %s = %s\n", numberOne, opperator, numberTwo, result); // Prints calculation of values
  return 0;
}

/** Takes in two GeneralNumbers and an operator to determine which operation is selected
* it then perform this operation using the two GeneralNumbers and returns the printed result
* @param numValOne First GeneralNumber used in calculation
* @param numValTwo Second GeneralNumber being used to calculate result with numValOne
* @param opperator Method selected from user that determines calculation for the two GeneralNumbers
* @return String of the calculated value if correctly entered
*/

char* GeneralNumber::Calculate(GeneralNumber* numValOne, GeneralNumber* numValTwo, char opperator) { // Runs program
  char* resultPrint; // Stores string version of calculated value
  GeneralNumber* result; // Stores result of operation

  switch(opperator) { // Selects case based on user input on opperator from readline
    case '+':
    result = numValOne->addition(numValTwo); // Adds two GeneralNumbers
    resultPrint = result->toString(); // Converts result to string
    delete(result);
    return resultPrint; // Returns printed result
    break;

    case '-':
    result = numValOne->subtraction(numValTwo); // Subtracts two GeneralNumbers
    resultPrint = result->toString(); // Converts result to string
    delete(result);
    return resultPrint; // Returns printed result
    break;

    case '*':
    result = numValOne->multiply(numValTwo); // Multiplies two GeneralNumbers
    resultPrint = result->toString(); // Converts result to string
    delete(result);
    return resultPrint; // Returns printed result
    break;

    case '/':
    result = numValOne->division(numValTwo);  // Divides two GeneralNumbers
    resultPrint = result->toString(); // Converts result to string
    delete(result);
    return resultPrint; // Returns printed result
    break;

  }
}
