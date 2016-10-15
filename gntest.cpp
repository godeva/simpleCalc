#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/*Stores function prototype and classes for GeneralNumber.cpp*/
#include "GeneralNumber.h"

/** Program to demonstrate the GeneralNumber class and its subclasses.
* @param argc Number of words on the command line.
* @param argv Arrray of pointers to these words.
*/

int main(int argc, char* argv[]) {

  // GeneralNumber* g1 = new GeneralNumber();
  // char* gs = g1->toString(); // Generate string version.
  // printf("%s\n", gs);
  // // We don't need the string any more.
  // free(gs);
  // gs = g1->foo(); // Test non-virtual function
  // printf("%s\n/*Stores function prototype and classes for GeneralNumber.cpp*/", gs);
  // free(gs);

  GeneralLong* g2 = new GeneralLong(2000L);
  char* gs = g2->toString(); // Generate string version.
  printf("%s\n", gs);
  free(gs);
  gs = g2->foo(); // Test non-virtual function
  printf("%s\n", gs);
  free(gs);

  GeneralNumber* g3 = new GeneralLong(5000L);
  gs = g3->toString(); // Generate string version.
  printf("Long: %s\n", gs);
  free(gs);
  gs = g3->foo(); // Test non-virtual function
  printf("%s\n", gs);
  free(gs);

  GeneralNumber* g4 = new GeneralRational(4000L, 3000L);
  gs = g4->toString(); // Generate string version.
  printf("Rational: %s\n", gs);
  free(gs);
  gs = g4->foo(); // Test non-virtual function
  printf("%s\n", gs);
  free(gs);

  // Now for some conversions!
  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Converting Long to Rational\n"); // conversions
  GeneralNumber* g5 = g2->toGeneralRational();
  gs = g5->toString(); // Generate string version.
  printf("%s\n", gs);
  free(gs);

  printf("Converting Rational to Long\n"); // conversions
  GeneralNumber* g6 = g4->toGeneralLong();
  gs = g6->toString(); // Generate string version.
  printf("%s\n", gs);
  free(gs);

  // Testing and practicing ways demonstrate the various conversion methods (part 4)
  // Choose some values, instantiate objects, convert them, and print them out.

  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing values and instantiate objects!\n"); // conversions

  // Testing GeneralLong
  GeneralNumber* prac1 = new GeneralLong(2500L);
  char* pracS = prac1->toString(); //Generates value to string
  printf("Testing GeneralLong: %s\n", pracS);
  free(pracS);
  pracS = prac1->foo(); // Test non-virtual function
  printf("%s\n", pracS);
  free(pracS);

  GeneralNumber* prac2 = new GeneralRational(5000L, 2000L);
  pracS = prac2->toString(); // Generating string
  printf("Testing GeneralRational: %s\n", pracS);
  free(pracS);
  pracS = prac2->foo(); // Test non-virtual function
  printf("%s\n", pracS);
  free(pracS);

  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing conversions!\n");

  GeneralNumber* prac3 = prac1->toGeneralRational();
  pracS = prac3->toString(); //  Generate string version
  printf("Converting GeneralLong to GeneralRational: %s\n", pracS);
  free(pracS);

  GeneralNumber* prac4 = prac2->toGeneralLong();
  pracS = prac4->toString();
  printf("Converting GeneralRational to GeneralLong: %s\n", pracS);
  free(pracS);



  // Creating values to test cannonRational function

  GeneralRational* prac5 = new GeneralRational(500L, -300L);
  pracS = prac5->toString(); // Generating string
  free(pracS);
  pracS = prac5->foo(); // Test non-virtual function
  free(pracS);

  GeneralRational* prac7 = new GeneralRational(501L, -300L);
  pracS = prac7->toString(); // Generating string
  free(pracS);
  pracS = prac7->foo(); // Test non-virtual function
  free(pracS);

  GeneralRational* prac9 = new GeneralRational(503L, 300L);
  pracS = prac9->toString(); // Generating string
  free(pracS);
  pracS = prac9->foo(); // Test non-virtual function
  free(pracS);
  /*Stores function prototype and classes for GeneralNumber.cpp*/
  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing function that canonicalize a GeneralRational!\n"); // conversions

  GeneralNumber* prac6 = prac5->toGeneralRational();
  pracS = prac6->toString(); //  Generate string version
  printf("Original form:%s\n", pracS);
  free(pracS);
  prac5->cannonRational();
  pracS = prac5->toString(); //  Generate string version
  printf("Canonical form:%s\n", pracS);
  free(pracS);

  GeneralNumber* prac8 = prac7->toGeneralRational();
  pracS = prac8->toString(); //  Generate string version
  printf("Original form:%s\n", pracS);
  free(pracS);
  prac7->cannonRational();
  pracS = prac7->toString(); //  Generate string version
  printf("Canonical form:%s\n", pracS);
  free(pracS);

  GeneralNumber* prac10 = prac9->toGeneralRational();
  pracS = prac10->toString(); //  Generate string version
  printf("Original form:%s\n", pracS);
  free(pracS);
  prac9->cannonRational();
  pracS = prac9->toString(); //  Generate string version
  printf("Canonical form:%s\n", pracS);
  free(pracS);

  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing adding values method!\n");

  printf("Rational 500/700 plus Rational 500/800!\n");
  GeneralRational* prac11 = new GeneralRational(500L, 700L);
  GeneralRational* prac12 = new GeneralRational(500L, 800L);
  prac11->addition(prac12); // Adds the two rationals
  pracS = prac11->toString(); // Converts added value to string for printing
  printf("%s\n", pracS);
  free(pracS);

  printf("Long 500 plus Rational 1300/800!\n");
  GeneralLong* prac13 = new GeneralLong(500L);
  GeneralRational* prac14 = new GeneralRational(1300L, 800L);
  prac13->addition
  (prac14); // Adds the long and rational and should return long
  pracS = prac13->toString(); // Converts added value to string for printing
  printf("%s\n", pracS);

  printf("Rational 1300/800 plus Long 500!\n");
  GeneralRational* prac15 = new GeneralRational(1300L, 800L);
  GeneralLong* prac16 = new GeneralLong(500L);
  prac15->addition(prac16); // Adds the rational and long and should return rational
  pracS = prac15->toString(); // Converts added value to string for printing
  printf("%s\n", pracS);
  free(pracS);

  printf("Long 800 plus Long 500!\n");
  GeneralLong* prac17 = new GeneralLong(800L);
  GeneralLong* prac18 = new GeneralLong(500L);
  prac17->addition(prac18); // Adds the two longs
  pracS = prac17->toString(); // Converts added value to string for printing
  printf("%s\n", pracS);
  free(pracS);

  // We don't need the objects any more.
  // delete(g1);
  delete(g2);
  delete(g3);
  delete(g4);

  delete(prac1);
  delete(prac2);
  delete(prac5);
  delete(prac7);
  delete(prac9);
  delete(prac12);
  delete(prac11);
  delete(prac13);
  delete(prac14);
  delete(prac15);
  delete(prac16);
  delete(prac17);
  delete(prac18);

  printf("\n"); // Adds blank space line in terminal to make program easier to view

  GeneralNumber* prac19 = GeneralNumber::parse("1234567");
  pracS = prac19->toString(); //  Generate string version
  printf("Original form:%s\n", pracS);
  free(pracS);

  GeneralNumber* prac20 = GeneralNumber::parse(" [7 / 2] ");
  pracS = prac20->toString(); //  Generate string version
  printf("Original form:%s\n", pracS);
  free(pracS);

  GeneralNumber* prac21 = GeneralNumber::parse(" [] ");
  //pracS = prac21->toString(); //  Generate string version
  if (prac21 == NULL) {
    printf("It's NULL\n");
  }
//  free(pracS);

  delete(prac19);
  delete(prac20);
  delete(prac21);

}
