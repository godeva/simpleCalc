#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Stores function prototype and classes for GeneralNumber.cpp*/
#include "GeneralNumber.h"

/** Default constructor for GeneralNumber
*/

GeneralNumber::GeneralNumber() {
  // Just a placeholder for now -- nothing to do.
}

/* Note: During the Lab I commented this out instead of deleting to see
the placeholder code if needed for an error. */

//
// /** Generates a printable representation of the object.
// * @return Freshly-allocated C-stype string
// */
// char* GeneralNumber::toString() const {
//   char* rep; // String representation of the vlaue.
//   rep = strdup("Never instantiate a plain GeneralNumber!");
//   return rep;
// }
//

/** Demonstrates a non-virtual function.
* @return Freshly-allocated C-stype string
*/

char* GeneralNumber::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralNumber!");
  return rep;
}


// /** Generates an equivalent GeneralLong
// * @return Pointer to a freshly-allocated GeneralLong object
// */
// GeneralLong* GeneralNumber::toGeneralLong() const {
//   GeneralLong* g = new GeneralLong();
//   return g;
// }

// /** Generates an equivalent GeneralRational
// * @return Pointer to a freshly-allocated GeneralRational object
// */
// GeneralRational* GeneralNumber::toGeneralRational() const {
//   GeneralRational* g = new GeneralRational();
//   return g;
// }
//

// /** Demonstrates adding values of objects for GeneralNumber
// * @param number object value thats being added and accept a parameter of type GeneralNumber
// * @return new added object value which is a pointer to GeneralNumber
// */

// GeneralNumber* GeneralNumber::addition(GeneralNumber* number) const { // Runs Program
//   GeneralNumber* result = new GeneralNumber(); // allows invoking this method upon an object
//   return result;
// }


/** Default constructor for GeneralLong
*/
GeneralLong::GeneralLong() {
  value = 0L; // Default value is a long zero
}

/** Constructor for GeneralLong
* @param value Number to store in the object
*/
GeneralLong::GeneralLong(long value) {
  this->value = value;
  // "this->value" means the field inside the object.
  // Just "value" means the parameter.
}

// See header comment in GeneralNumber
char* GeneralLong::toString() const {
  // Allocate enough space for largest possible number.
  char* rep = (char*) malloc(MAX_DIGITS_IN_LONG + 1);

  sprintf(rep, "%ld", value); // convert to printable form.
  return rep;
}

/** Demonstrates a non-virtual function.
* @return Freshly-allocated C-stype string
*/
char* GeneralLong::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralLong!");
  return rep;
}

/** Generates an equivalent GeneralLong
* @return Pointer to a freshly-allocated GeneralLong object
*/
GeneralLong* GeneralLong::toGeneralLong() const {
  GeneralLong* g = new GeneralLong(value); // Very simple!
  return g;
}

/** Generates an equivalent GeneralRational
* @return Pointer to a freshly-allocated GeneralRational object
*/
GeneralRational* GeneralLong::toGeneralRational() const {
  GeneralRational* g = new GeneralRational(value, 1L);
  // Slightly more complicated!
  return g;
}

/** Generates an equivalent GeneralDouble
* @return Pointer to a freshly-allocated GeneralDouble object
*/
GeneralDouble* GeneralLong::toGeneralDouble() const {
  GeneralDouble* g = new GeneralDouble(value); // Very simple!
  return g;
}

/** Demonstrates adding values of objects for GeneralLong
* @param number object value thats being added accept a parameter of type GeneralNumber
* @return new added object value that returns pointer to a GeneralLong, no matter the type of the parameter.
*/

GeneralNumber* GeneralLong::addition(GeneralNumber* number) { // Runs program
  GeneralLong* result = number->toGeneralLong(); // Convert the parameter to GeneralLong
  this->value = value;  // Sets value to be added
  value += result->value; // Additon process occurs and produces new added value
  delete(result); // Deletes old result after using it since we don't need it anymore
  return this;
}

/** Demonstrates subtracting values of objects for GeneralLong
* @param number object value thats being subtracted accept a parameter of type GeneralNumber
* @return new subtracted object value that returns pointer to a GeneralLong, no matter the type of the parameter.
*/

GeneralNumber* GeneralLong::subtraction(GeneralNumber* number) { // Runs program
  GeneralLong* result = number->toGeneralLong(); // Convert the parameter to GeneralLong
  long gn = this->value-result->value;
  delete(result); // Deletes old result after using it since we don't need it anymore
  result = new GeneralLong(gn);
  return result; // Returns added result
}

/** Demonstrates multiplying values of objects for GeneralLong
* @param number object value thats being multiplied accept a parameter of type GeneralNumber
* @return new multiplied object value that returns pointer to a GeneralLong, no matter the type of the parameter.
*/

GeneralNumber* GeneralLong::multiply(GeneralNumber* number) { // Runs program
  GeneralLong* result = number->toGeneralLong(); // Convert the parameter to GeneralLong
  long gn = this->value*result->value;
  delete(result); // Deletes old result after using it since we don't need it anymore
  result = new GeneralLong(gn);
  return result; // Returns added result
}

/** Demonstrates dividing values of objects for GeneralLong
* @param number object value thats being subtracted accept a parameter of type GeneralNumber
* @return new divided object value that returns pointer to a GeneralLong, no matter the type of the parameter.
*/

GeneralNumber* GeneralLong::division(GeneralNumber* number) { // Runs program
  GeneralLong* result = number->toGeneralLong(); // Convert the parameter to GeneralLong
  long gn = this->value/result->value;
  delete(result); // Deletes old result after using it since we don't need it anymore
  result = new GeneralLong(gn);
  return result; // Returns added result
}

/** Default constructor for GeneralRational
*/
GeneralRational::GeneralRational() {
  top = 0L;
  bottom = 1L;// Default value is a long zero over a long one
}

/** Constructor for GeneralRational
* @param top Numerator to store in the object
* @param bottom Denominator to store in the object
*/
GeneralRational::GeneralRational(long top, long bottom) {
  this->top = top;
  this->bottom = bottom;
  // "this->something" means the field inside the object.
  // Just "something" means the parameter.
}

// See header comment in GeneralNumber
char* GeneralRational::toString() const {
  // Allocate enough space for largest possible number.
  char* rep = (char*) malloc((2 * MAX_DIGITS_IN_LONG) + 6);

  sprintf(rep, "[%ld / %ld]", top, bottom); // convert to printable form.
  return rep;
}

/** Demonstrates a non-virtual function.
* @return Freshly-allocated C-stype string
*/
char* GeneralRational::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralRational!");
  return rep;
}

/** Generates an equivalent GeneralLong
* @return Pointer to a freshly-allocated GeneralLong object
*/

GeneralLong* GeneralRational::toGeneralLong() const {
  GeneralLong* g = new GeneralLong(top / bottom);
  return g;
}

/** Generates an equivalent GeneralRational
* @return Pointer to a freshly-allocated GeneralRational object
*/
GeneralRational* GeneralRational::toGeneralRational() const {
  GeneralRational* g = new GeneralRational(top, bottom);
  return g;
}

/** Generates an equivalent GeneralDouble
* @return Pointer to a freshly-allocated GeneralDouble object
*/
GeneralDouble* GeneralRational::toGeneralDouble() const {
  GeneralDouble* g = new GeneralDouble((double)top / (double)bottom); // Very simple!
  return g;
}

/** Demonstrates adding values of objects for GeneralRational
* @param number object value thats being added accept a parameter of type GeneralNumber
* @return new added object value that returns pointer to a GeneralRational, no matter the type of the parameter.
*/

GeneralNumber* GeneralRational::addition(GeneralNumber* number) { // Runs Program
  GeneralRational* result = number->toGeneralRational(); // Convert the parameter to GeneralRational

  long n = top*(result->bottom)+(result->top)*bottom; // Setting numerator via addition
  long d1 = bottom; // Instantiating denominator
  long d2 = result->bottom; // Setting other denominator
  long d3 = (result -> bottom * bottom)/helperLCD(d1,d2); // Sets added denominator result

  bottom = (helperLCD(d1,d2)); // Sets bottom to final added denominator
  top = (n/d3); // Sets top to final added numerator
  delete(result); // Deletes old result after using it since we don't need it anymore
  result = new GeneralRational(top, bottom);
  result -> cannonRational(); // Simplifies the added fraction
  return result; // Returns added result
}

/** Demonstrates subtracting values of objects for GeneralRational
* @param number object value thats being added accept a parameter of type GeneralNumber
* @return new object value that returns pointer to a GeneralRational, no matter the type of the parameter.
*/

GeneralNumber* GeneralRational::subtraction(GeneralNumber* number) { // Runs Program
  GeneralRational* result = number->toGeneralRational(); // Convert the parameter to GeneralRational

  long n = top*(result->bottom)-(result->top)*bottom; // Setting numerator via subtraction
  long d1 = bottom; // Instantiating denominator
  long d2 = result->bottom; // Setting other denominator
  long d3 = (result -> bottom * bottom)/helperLCD(d1,d2); // Sets added denominator result

  top = (n/d3); // Sets top to final numerator
  bottom = (helperLCD(d1,d2)); // Sets bottom to final denominator
  delete(result); // Deletes old result after using it since we don't need it anymore
  result = new GeneralRational(top, bottom);
  result -> cannonRational(); // Simplifies the subtracted fraction
  return result; // Returns subtracted result
}

/** Demonstrates multiplying values of objects for GeneralRational
* @param number lobject value thats being multiplied accept a parameter of type GeneralNumber
* @return new object value that returns pointer to a GeneralRational, no matter the type of the parameter.
*/

GeneralNumber* GeneralRational::multiply(GeneralNumber* number) { // Runs Program
  GeneralRational* result = number->toGeneralRational(); // Convert the parameter to GeneralRational
  long n = this->top*result->top; // Set multiplied Numerators
  long d = this->bottom*result->bottom; // Sets multiplied Denominators
  delete(result); // Deletes old result after using it since we don't need it anymore
  result = new GeneralRational(n, d);
  result -> cannonRational(); // Simplifies the multiplied fraction
  return result; // Returns multiplied result
}

/** Demonstrates dividing values of objects for GeneralRational
* @param number object value thats being divided accept a parameter of type GeneralNumber
* @return new object value that returns pointer to a GeneralRational, no matter the type of the parameter.
*/

GeneralNumber* GeneralRational::division(GeneralNumber* number) { // Runs Program
  GeneralRational* result = number->toGeneralRational(); // Convert the parameter to GeneralRational
  long n = this->top*result->bottom; // Set divided Numerators
  long d = this->bottom*result->top; // Set divided Denominators
  delete(result); // Deletes old result after using it since we don't need it anymore
  result = new GeneralRational(n, d);
  result -> cannonRational(); // Simplifies the divided fraction
  return result; // Returns divided result
}

/** Canonicalizes a GeneralRational object. In other words, converts the contents
* of the object so it represents the same value, but in its canonical form.
*/

void GeneralRational::cannonRational() { // Runs Program
  long polarity = 1;

  if (top < 0) { // Changes polarity so that numerator is negative if bottom is negative to canonicalize
    polarity *= -1;
    top *= -1;
  }
  if (bottom < 0) { // Works with top if statement to canonicalize polarity of rational number
    polarity *= -1;
    bottom *= -1;
  }

  long tmp = helperGCD(top, bottom); // Sets tmp to the greatest common denominator
  top = top/tmp*polarity; // Simplifies numerator
  bottom = bottom/tmp; // Simplifies denominator
}

/** Returns the Greatest Common Divisor of two long integers
* Note: algorithm used was a modfied version of what I found here
* http://www.codeproject.com/Tips/157560/Fast-Greatest-Common-Divisor-GCD-Algorithm
* @param top Numerator long integer
* @param bottom Denominator long integer
* @return The Greatest Common Divisor
*/

long helperGCD(long top, long bottom) { // Runs Program
  long gcd;
  int i;

  if(bottom > top) {  /* Checks and swaps variables if bottom is greater than top*/
    long temp = bottom;
    bottom = top;
    top = temp;
  }

  for(i = 1; i <= bottom; ++i) { /* Terminates till highest Common Divisor is found */
    if (top % i == 0 && bottom % i == 0) { /*Checks if i value is divisable by both long integer*/
      gcd = i; // Sets value as gcd and overides if higher gcd is found
    }
  }

  return gcd;
}

/** Returns the Least Common Divisor of two long integers
* Note: algorithm used was a modfied version of what I found here
* http://stackoverflow.com/questions/36279198/calculate-lcm-of-2-numbers-using-templates/36280040
* @param n Numerator long integer
* @param d Denominator long integer
* @return The Least Common Divisor
*/

long helperLCD(long n, long d) { // Runs Program
  long lcd;

  lcd = (n > d) ? n : d; /* Uses algorithm to store the max value between two values in lcd */

  do { // Checks and stops when both values have a common multiple
    if (lcd%n == 0 && lcd%d == 0) { // Checks and sets lcd when first common multiple is found
      return lcd;
      break;
    } else { // Continues loop until common multiple is found
      ++lcd;
    }
  }
  while (true); // This continues the loop until the conditon meet is true
}





/** Default constructor for GeneralDouble
*/

GeneralDouble::GeneralDouble() {
  value = 0.0; // Default value is a Double zero
}

/** Constructor for GeneralDouble
* @param value Number to store in the object
*/

GeneralDouble::GeneralDouble(double value) {
  this->value = value;
  // "this->value" means the field inside the object.
  // Just "value" means the parameter.
}

// See header comment in GeneralNumber
char* GeneralDouble::toString() const {
  // Allocate enough space for largest possible number.
  char* rep = (char*) malloc(MAX_DIGITS_IN_LONG + 1);

  sprintf(rep, "%lf", value); // convert to printable form.
  return rep;
}

/** Demonstrates a non-virtual function.
* @return Freshly-allocated C-stype string
*/

char* GeneralDouble::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralDouble!");
  return rep;
}

/** Generates an equivalent GeneralLong
* @return Pointer to a freshly-allocated GeneralLong object
*/

GeneralLong* GeneralDouble::toGeneralLong() const {
  GeneralLong* g = new GeneralLong(value); // Very simple!
  return g;
}

/** Generates an equivalent GeneralRational
* @return Pointer to a freshly-allocated GeneralRational object
*/

GeneralRational* GeneralDouble::toGeneralRational() const {
  GeneralRational* g = new GeneralRational(value, 1L);
  // Slightly more complicated!
  return g;
}

/** Generates an equivalent GeneralDouble
* @return Pointer to a freshly-allocated GeneralDouble object
*/

GeneralDouble* GeneralDouble::toGeneralDouble() const {
  GeneralDouble* g = new GeneralDouble(value); // Very simple!
  return g;
}

/** Demonstrates adding values of objects for GeneralDouble
* @param number object value thats being added accept a parameter of type GeneralNumber
* @return new added object value that returns pointer to a GeneralDouble, no matter the type of the parameter.
*/

GeneralNumber* GeneralDouble::addition(GeneralNumber* number) { // Runs program
  GeneralDouble* result = number->toGeneralDouble(); // Convert the parameter to GeneralDouble
  this->value = value;  // Sets value to be added
  value += result->value; // Additon process occurs and produces new added value
  delete(result); // Deletes old result after using it since we don't need it anymore
  return this;
}

/** Demonstrates subtracting values of objects for GeneralDouble
* @param number object value thats being subtracted accept a parameter of type GeneralNumber
* @return new subtracted object value that returns pointer to a GeneralDouble, no matter the type of the parameter.
*/

GeneralNumber* GeneralDouble::subtraction(GeneralNumber* number) { // Runs program
  GeneralDouble* result = number->toGeneralDouble(); // Convert the parameter to GeneralDouble
  this->value = value;  // Sets value to be subtracted
  value -= result->value; // Subtraction process occurs and produces new value
  delete(result); // Deletes old result after using it since we don't need it anymore
  return this;
}

/** Demonstrates multiplying values of objects for GeneralDouble
* @param number object value thats being multiplied accept a parameter of type GeneralNumber
* @return new multiplied object value that returns pointer to a GeneralDouble, no matter the type of the parameter.
*/

GeneralNumber* GeneralDouble::multiply(GeneralNumber* number) { // Runs program
  GeneralDouble* result = number->toGeneralDouble(); // Convert the parameter to GeneralDouble
  this->value = value;  // Sets value
  value *= result->value; // Multiplying process occurs and produces new value
  delete(result); // Deletes old result after using it since we don't need it anymore
  return this;
}

/** Demonstrates dividing values of objects for GeneralDouble
* @param number object value thats being divided accept a parameter of type GeneralNumber
* @return new divided object value that returns pointer to a GeneralDouble, no matter the type of the parameter.
*/

GeneralNumber* GeneralDouble::division(GeneralNumber* number) { // Runs program
  GeneralDouble* result = number->toGeneralDouble(); // Convert the parameter to GeneralDouble
  this->value = value;  // Sets value to be divided
  value /= result->value; // Division process occurs and produces new value
  delete(result); // Deletes old result after using it since we don't need it anymore
  return this;
}
