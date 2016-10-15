Name: Goutham Deva

Program Description: 

In the “assig5” folder, there are 16 files/directories. Note: Objects files will not be included in this guide as all the descriptions would be simply compiled code from the corresponding code files. Also note that html and latex directories are part of the doxygen file that help run and store "make docs". Therfore, we will not be going over those directories.  


NOTE: IF YOU WANT TO USE DOXYEGEN COMMAND "Make Docs", TAKE THE READ ME FILE OUT OF THE ZIP IN A SEPERATE DIRECTORY SO THAT DOXYGEN DOESN'T REGISTER readme.txt syntax as file members online. Thanks! 

calc: This file is an executable that runs a simple calculator which lets a user type in GeneralNumbers and commands for manipulating them. User can enter an int, long, rational, and double numbers in the proper format and add, subtract, multiply, and divide these numbers with the printed result and the caculation process.

calc.cpp: This is human readable code file for calc. All the code from this file was compiled to create the executable.

gnparse.cpp: This code stores multiple functions that help run the calc excutable. The file stores a function that handles the message prompts in calc and whether they are valid, the function that determines which operator is needed and applies them with the generalNumbers which is sent back to calc, and a function that checks the format of the string to convert it to the proper type of generalNumber.

gntest: This file is an executable that prints out different types of numbers. The program first prints out an output for each type of number first stating that you can never instantiate a plain GeneralNumber followed by printing a long type number, another long number, and then a rational. Both the last two numbers are instantiated as GeneralNumber* to help create consitancy and convert both data types which is why they are both printed as GeneralNumber instead of GeneralLong and GeneralRational. The next printed lines show the 2000 Long data type being converted to Rational with the datatype still retaining it's value but displayed as a fraction [2000/1]. Same goes from rational to long where rational number [4000/3000] is converted to 1 Long because Long doesn't taken fractions and simply divides the value while removing any remainders. The next two chunk of lines does the same thing where Long is being converted to Rational and vice versa [we had to do this for part 4]. For the next chunk of lines, we test a function stored in GeneralNumbers.cpp that simplifies the original rational function. Specifically, the denominator is always positive and if not make sure the polarity is changed to the numerator so the value remains the same and the numerator and denominator have magnitudes as small as possible. This chunk of lines demonstrate three examples showing that this function works properly. Finally, the last chunk of lines shows the addition methods made in all classes all stored in GeneralNumbers.cpp. It allows for different types of numbers to be added with the first number in the addition process being the resulting number type. The file demonstrates a rational plus a rational, long plus a rational, rational plus a long, and long plus long. Also added on to this file is the testing of function parse from the file gnparse.cpp which checks the string number format entered to return the number in the proper type entered. 

gntest.cpp: This is human readable code file for gntest. All the code from this file was compiled to create the executable.

GeneralNumbers.cpp: This files stores all the functions with each class/sub-class that we use in gntest. Most of the functions stored there convert and print out there data type number. The most important functions modified are the canonize function which simplifies original rational functions, the addition functions for both GeneralNumber, GeneralLong, and GeneralRational, and both helper functions Greatest Common Denominator which helps to canonize GeneralRational and Least Common multiple which helps to multiply two rationals (or a rational and long).

GeneralNumbers.h: This is the header file and contains both the function prototype, class of GeneralNumber, subclasses of GeneralLong & GeneralRational & GeneralDouble as well as there private stored values.

Makefile: Makefile takes all of the code files and compiles them so that they are ready to be used for the computer to read. In the contents of the file, makefile shows the files that that are told to be compiled and link together and cleaned. This include the files GeneralNumbers.cpp and gntest.ccp as well as there respective header files. To activate the contents of Makefile, type “make” on the command line which will allow the code files to be compiled to run the program. If you wish to uncompile the code files which removes the .o file, type “make clean” on the command prompt.

How to compile: 

Unzip the tar file and type "make" in the command prompt inside the "assig5" directory. This will compile all the files in the folder as well as link the header files with the same named code file. If you wish to uncompile, type "make clean" and it will delete all the object files and leave you with the code files, header files, Doxyfile, and makefile.

Test Data:

calc: 

//Check if the program runs

Input: ./calc
then enter 3, +, 5, in that order

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 3
Enter operator: +
Enter second argument (blank to exit): 5
3 + 5 = 8
Enter first argument (blank to exit): 
_________________________________________________________________

calc: 

//Check if exits when entering nothing for parameter one

Input: ./calc
then press enter

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 
Thank You for using my calculator, GoodBye!
_________________________________________________________________

calc: 

//Check if exits when entering nothing for parameter two

Input: ./calc
Then enter 3, +, and press enter

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 3
Enter operator: +
Enter second argument (blank to exit): 
Thank You for using my calculator, GoodBye
_________________________________________________________________

calc: 

// Asks user to try again if invalid parameter for parameter one

Input: ./calc
Then enter "duck" or anything but a number

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): duck
Try Again
Enter first argument (blank to exit):
_________________________________________________________________

calc: 

// Asks user to try again if invalid parameter for operator

Input: ./calc
Enter 3 and then enter "duck" or anything but an operator

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 3
Enter operator: duck
Try Again
Enter first argument (blank to exit): 
Thank You for using my calculator, GoodBye!

_________________________________________________________________

calc: 

// Asks user to try again if invalid parameter for parameter two

Input: ./calc
Enter 3, + and then enter "duck" or anything but a number

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 3
Enter operator: +
Enter second argument (blank to exit): duck
Try Again
Enter first argument (blank to exit): 

_________________________________________________________________

calc: 

// If long plus long can return long

Input: ./calc
Then enter 12345, +, 45321 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12345
Enter operator: +
Enter second argument (blank to exit): 45321
12345 + 45321 = 57666
Enter first argument (blank to exit): 

_________________________________________________________________

calc: 

// If long plus rational can return long

Input: ./calc
345, +, [34 / 54]

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 345
Enter operator: +
Enter second argument (blank to exit): [34 / 54]
345 + [34 / 54] = 345
Enter first argument (blank to exit): 
_________________________________________________________________

calc: 

// If rational plus long can return rational

Input: ./calc
[234 / 43], +, 345

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [234 / 43]
Enter operator: +
Enter second argument (blank to exit): 345
[234 / 43] + 345 = [15069 / 43]
Enter first argument (blank to exit):
_________________________________________________________________

calc: 

// If rational plus rational can return rational

Input: ./calc
[345/32], +, [456 /43] 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [345/32]
Enter operator: +
Enter second argument (blank to exit): [456 /43]
[345/32] + [456 /43] = [29427 / 1376]
Enter first argument (blank to exit): 

_________________________________________________________________

calc: 

// If double plus double can return double

Input: ./calc
12.25, +, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: +
Enter second argument (blank to exit): 12.25
12.25 + 12.25 = 24.500000
Enter first argument (blank to exit): 


_________________________________________________________________

calc: 

// If double plus long can return double

Input: ./calc
12.25, +, 20 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: +
Enter second argument (blank to exit): 20
12.25 + 20 = 32.250000
Enter first argument (blank to exit): 

_________________________________________________________________

calc: 

// If double plus rational can return double

Input: ./calc
12.25, +, [10 / 4]

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: +
Enter second argument (blank to exit): [10 / 4]
12.25 + [10 / 4] = 14.750000
Enter first argument (blank to exit): 

_________________________________________________________________

calc: 

// If long plus double can return double

Input: ./calc
20, +, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 20
Enter operator: +
Enter second argument (blank to exit): 12.25
20 + 12.25 = 32
_________________________________________________________________

calc: 

// If rational plus double can return double

Input: ./calc
[10 / 4], +, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [10 / 4]
Enter operator: +
Enter second argument (blank to exit): 12.25
[10 / 4] + 12.25 = [29 / 2]
Enter first argument (blank to exit): 

________________________________________________

calc: 

// If long minus long can return long

Input: ./calc
Then enter 12345, -, 45321 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12345
Enter operator: -
Enter second argument (blank to exit): 45321
12345 - 45321 = -32976
_________________________________________________________________

calc: 

// If long minus rational can return long

Input: ./calc
345, -, [34 / 54]

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 345
Enter operator: -
Enter second argument (blank to exit): [34 / 54]
345 - [34 / 54] = 345
_________________________________________________________________

calc: 

// If rational minus long can return rational

Input: ./calc
[234 / 43], -, 345

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [234 / 43]
Enter operator: -
Enter second argument (blank to exit): 345
[234 / 43] - 345 = [-14601 / 43]
_________________________________________________________________

calc: 

// If rational minus rational can return rational

Input: ./calc
[345/32], -, [456 /43] 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [345/32]
Enter operator: -
Enter second argument (blank to exit): [456/43]
[345/32] - [456/43] = [243 / 1376]
_________________________________________________________________

calc: 

// If double minus double can return double

Input: ./calc
12.25, -, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: -
Enter second argument (blank to exit): 12.25
12.25 - 12.25 = 0.000000
_________________________________________________________________

calc: 

// If double minus long can return double

Input: ./calc
12.25, -, 20 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: -
Enter second argument (blank to exit): 20
12.25 - 20 = -7.750000
_________________________________________________________________

calc: 

// If double minus rational can return double

Input: ./calc
12.25, -, [10 / 4]

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: -
Enter second argument (blank to exit): [10 / 4]
12.25 - [10 / 4] = 9.750000

_________________________________________________________________

calc: 

// If long minus double can return double

Input: ./calc
20, -, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 20
Enter operator: -
Enter second argument (blank to exit): 12.25
20 - 12.25 = 8
_________________________________________________________________

calc: 

// If rational minus double can return double

Input: ./calc
[10 / 4], -, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [10 / 4]
Enter operator: -
Enter second argument (blank to exit): 12.25
[10 / 4] - 12.25 = [-19 / 2]

_________________________________________________________________

calc: 

// If long times long can return long

Input: ./calc
Then enter 12345, *, 45321 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12345
Enter operator: *
Enter second argument (blank to exit): 45321
12345 * 45321 = 559487745
_________________________________________________________________

calc: 

// If long times rational can return long

Input: ./calc
345, *, [34 / 54]

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 345
Enter operator: *
Enter second argument (blank to exit): [34 / 54]
345 * [34 / 54] = 0
_________________________________________________________________

calc: 

// If rational times long can return rational

Input: ./calc
[234 / 43], *, 345

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [234 / 43]
Enter operator: *
Enter second argument (blank to exit): 345
[234 / 43] * 345 = [80730 / 43]
_________________________________________________________________

calc: 

// If rational times rational can return rational

Input: ./calc
[345/32], *, [456 /43] 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [345/32]
Enter operator: *
Enter second argument (blank to exit): [456/43]
[345/32] * [456/43] = [19665 / 172]
_________________________________________________________________

calc: 

// If double times double can return double

Input: ./calc
12.25, *, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: *
Enter second argument (blank to exit): 12.25
12.25 * 12.25 = 150.062500
_________________________________________________________________

calc: 

// If double times long can return double

Input: ./calc
12.25, *, 20 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: *
Enter second argument (blank to exit): 20
12.25 * 20 = 245.000000
________________________________________________________________

calc: 

// If double times rational can return double

Input: ./calc
12.25, *, [10 / 4]

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: *
Enter second argument (blank to exit): [10/4]
12.25 * [10/4] = 30.625000
_________________________________________________________________

calc: 

// If long times double can return double

Input: ./calc
20, *, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 20
Enter operator: *
Enter second argument (blank to exit): 12.25
20 * 12.25 = 240
_________________________________________________________________

calc: 

// If rational times double can return double

Input: ./calc
[10 / 4], *, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [10 / 4]
Enter operator: *
Enter second argument (blank to exit): 12.25
[10 / 4] * 12.25 = [30 / 1]

_________________________________________________________________

calc: 

// If long divided by long can return long

Input: ./calc
Then enter 12345, /, 45321 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12345
Enter operator: /
Enter second argument (blank to exit): 45321
12345 / 45321 = 0
_________________________________________________________________

calc: 

// If long divided by rational can return long

Input: ./calc
345, /, [2 / 1]

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 345
Enter operator: /
Enter second argument (blank to exit): [2 / 1]
345 / [2 / 1] = 172
_________________________________________________________________

calc: 

// If rational divided by long can return rational

Input: ./calc
[234 / 43], /, 345

What to Expect:

Simple GeneralNumber Calculator

Enter first argument (blank to exit): [234 / 43]
Enter operator: /
Enter second argument (blank to exit): 345
[234 / 43] / 345 = [78 / 4945]
_________________________________________________________________

calc: 

// If rational divided by rational can return rational

Input: ./calc
[345/32], /, [456 /43] 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [345/32]
Enter operator: /
Enter second argument (blank to exit): [456/43]
[345/32] / [456/43] = [4945 / 4864]
_________________________________________________________________

calc: 

// If double divided by double can return double

Input: ./calc
12.25, /, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: /
Enter second argument (blank to exit): 12.25
12.25 / 12.25 = 1.000000
_________________________________________________________________

calc: 

// If double divided by long can return double

Input: ./calc
12.25, /, 20 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: /
Enter second argument (blank to exit): 20
12.25 / 20 = 0.612500
________________________________________________________________

calc: 

// If double divided by rational can return double

Input: ./calc
12.25, /, [10 / 4]

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 12.25
Enter operator: /
Enter second argument (blank to exit): [10/4]
12.25 / [10/4] = 4.900000

_________________________________________________________________

calc: 

// If long divided by double can return double

Input: ./calc
20, /, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): 20
Enter operator: /
Enter second argument (blank to exit): 12.25
20 / 12.25 = 1
_________________________________________________________________

calc: 

// If rational divided by double can return double

Input: ./calc
[10 / 4], /, 12.25 

What to Expect:

Simple GeneralNumber Calculator
Enter first argument (blank to exit): [10 / 4]
Enter operator: /
Enter second argument (blank to exit): 12.25
[10 / 4] / 12.25 = [5 / 24]

_________________________________________________________________


gntest: 

//Check if the program runs

Input: ./gntest

What to Expect:
2000
This is the output of foo() for GeneralLong!
Long: 5000
This is the output of foo() for GeneralNumber!
Rational: [4000 / 3000]
This is the output of foo() for GeneralNumber!

Converting Long to Rational
[2000 / 1]
Converting Rational to Long
1

Testing values and instantiate objects!
Testing GeneralLong: 2500
This is the output of foo() for GeneralNumber!
Testing GeneralRational: [5000 / 2000]
This is the output of foo() for GeneralNumber!

Testing conversions!
Converting GeneralLong to GeneralRational: [2500 / 1]
Converting GeneralRational to GeneralLong: 2

Testing function that canonicalize a GeneralRational!
Original form:[500 / -300]
Canonical form:[-5 / 3]
Original form:[501 / -300]
Canonical form:[-167 / 100]
Original form:[503 / 300]
Canonical form:[503 / 300]

Testing adding values method!
Rational 500/700 plus Rational 500/800!
[75 / 56]
Long 500 plus Rational 1300/800!
501
Rational 1300/800 plus Long 500!
[4013 / 8]
Long 800 plus Long 500!
1300

Original form:1234567
Original form:[7 / 2]
It's NULL
_________________________________________________________
