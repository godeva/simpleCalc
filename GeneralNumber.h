
// Maximum number of digits in a long integer, including possible sign
// Not necessarily portable -- this works for 64-bit longs.
#define MAX_DIGITS_IN_LONG (20)

// Class "prototypes" to solve the forward reference problem:
class GeneralNumber;
class GeneralLong;
class GeneralRational;
class GeneralDouble;
/***************************************/

// The parent class:

class GeneralNumber {
public:
  GeneralNumber();
  virtual char* toString() const = 0; // Setting as a pure virtual function
  char* foo() const; // Not a virtual function!
  virtual GeneralLong* toGeneralLong() const = 0; // Setting as a pure virtual function
  virtual GeneralRational* toGeneralRational() const = 0; // Setting as a pure virtual function
  virtual GeneralDouble* toGeneralDouble() const = 0; // Setting as a pure virtual function
  virtual GeneralNumber* addition(GeneralNumber* number) = 0;  // Allows the adding of different type numbers in sub classes
  virtual GeneralNumber* subtraction(GeneralNumber* number) = 0;  // Allows the adding of different type numbers in sub classes
  virtual GeneralNumber* multiply(GeneralNumber* number) = 0;  // Allows the adding of different type numbers in sub classes
  virtual GeneralNumber* division(GeneralNumber* number) = 0;  // Allows the adding of different type numbers in sub classes
  static GeneralNumber* parse(const char* s); // Parses a string representing a GeneralNumber
  static int Prompt(); // Handles all the I/O for calc
  static char* Calculate(GeneralNumber* numberOne, GeneralNumber* numberTwo, char opperator); // Handles the calculations for calc
};
/***************************************/

// Define the various subclasses:

class GeneralLong: public GeneralNumber {
public:
  GeneralLong();
  GeneralLong(long value);
  char* toString() const;
  char* foo() const; // Not a virtual function!
  GeneralLong* toGeneralLong() const;
  GeneralRational* toGeneralRational() const;
  GeneralDouble* toGeneralDouble() const;
  GeneralNumber* addition(GeneralNumber* number);  // Adds a long number with any number to return a new long number
  GeneralNumber* subtraction(GeneralNumber* number); // Subtracts a long number with any number to return a new long number
  GeneralNumber* multiply(GeneralNumber* number); // Multiplies a long number with any number to return a new long number
  GeneralNumber* division(GeneralNumber* number); // Divides a long number with any number to return a new long number

private:
  long value; // This holds the value of the number.
};

class GeneralRational: public GeneralNumber {
public:
  GeneralRational();
  GeneralRational(long top, long bottom);
  char* toString() const;
  char* foo() const; // Not a virtual function!
  GeneralLong* toGeneralLong() const;
  GeneralRational* toGeneralRational() const;
  GeneralDouble* toGeneralDouble() const;
  void cannonRational(); // Simplifies Rational number/fraction
  GeneralNumber* addition(GeneralNumber* number); // Adds a rational number with any number to return a new rational number
  GeneralNumber* subtraction(GeneralNumber* number); // Subtracts a rational number with any number to return a new rational number
  GeneralNumber* multiply(GeneralNumber* number); // Multiplies a rational number with any number to return a new rational number
  GeneralNumber* division(GeneralNumber* number); // Divides a rational number with any number to return a new rational number

private:
  long top; // This holds the top (numerator)
  long bottom; // This holds the bottom (denominator)

};

class GeneralDouble: public GeneralNumber {
public:
  GeneralDouble();
  GeneralDouble(double value);
  char* toString() const;
  char* foo() const; // Not a virtual function!
  GeneralDouble* toGeneralDouble() const;
  GeneralLong* toGeneralLong() const;
  GeneralRational* toGeneralRational() const;
  GeneralNumber* addition(GeneralNumber* number);  // Adds a Double number with any number to return a new Double number
  GeneralNumber* subtraction(GeneralNumber* number); // Subtracts a Double number with any number to return a new Double number
  GeneralNumber* multiply(GeneralNumber* number); // Multiplies a Double number with any number to return a new Double number
  GeneralNumber* division(GeneralNumber* number); // Divides a Double number with any number to return a new Double number

private:
  double value; // This holds the value of the number.
};

long helperGCD(long top, long bottom); // Calculates and returns greatest common denominator
long helperLCD(long bottom1, long bottom2); // Calculates and returns greatest lowest multiple/denominator
