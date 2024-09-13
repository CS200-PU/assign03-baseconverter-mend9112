//******************************************************************************
// File name:   main.cpp
// Author:      Marisa Mendosa
// Date:        09/13/2024 (Replace xx/xx/xxxx with month/day/year)
// Class:       CS150-xx (Replace xx with your section number)
// Assignment:  Hello World
// Purpose:     Display the message Hello World to the screen
// Hours:       0.25
//******************************************************************************

#include <iostream>

using namespace std;

//***************************************************************************
// Function:    hexCharToInt
//
// Description: Converts hexadecimal value to decimal
//
// Parameters:  hexDigit - digit to be converted
//
// Returned:    Equivalent decimal number
//***************************************************************************
int hexCharToInt (char hexDigit)
{
  int decVal = 0;

  switch (hexDigit) {
    case 'A':
      decVal = 10;
      break;
    case 'B':
      decVal = 11;
      break;
     case 'C':
      decVal = 12;
      break;
     case 'D':
      decVal = 13;
      break;
     case 'E':
      decVal = 14;
      break;
     case 'F':
      decVal = 15;
      break;
    default:
      decVal = hexDigit - '0';
  }

  return decVal;
}

//***************************************************************************
// #2
// Function:    getBase
//
// Description: Returns the base value of the value
//
// Parameters:  strNumber - value as string the base is to be determined for
//
// Returned:    Base value (D, H, B)
//***************************************************************************
char getBase (const string &strNumber)
{
  /*Input: string representing a decimal, hexadecimal, or binary number
Returns: one of three characters:
• D if the number is a decimal
• H if the user number is a hexadecimal
• B if the number is binary.*/
  char baseVal;
  if 
  return 0;
}

//***************************************************************************
// #3
// Function:    getNumber
//
// Description: 
//
// Parameters:  prompt - user inputed value to be converted
//
// Returned:    String representing a decimal, hexadecimal, or binary number
//***************************************************************************
string getNumber (const string &prompt)
{
  return 0;
}

//***************************************************************************
// #4
// Function:    printTitle
//
// Description: Prints the title
//
// Parameters:  myTitle - title to print
//
// Returned:    None
//***************************************************************************
void printTitle (const string &myTitle)
{
  cout << myTitle << endl;
}

//***************************************************************************
// #5
// Function:    binaryToDecimal
//
// Description: 
//
// Parameters:  strNumber - 
//
// Returned:    String
//***************************************************************************
string binaryToDecimal (const string &strNumber)
{
  return 0;
}

//***************************************************************************
// #6
// Function:    decimalToBinary
//
// Description: 
//
// Parameters:  strNumber - 
//
// Returned:    String
//***************************************************************************
string decimalToBinary (const string &strNumber)
{
  return 0;
}

//***************************************************************************
// #7
// Function:    decimalToHex
//
// Description: 
//
// Parameters:  strNumber - 
//
// Returned:    String
//***************************************************************************
string decimalToHex (const string &strNumber)
{
  return 0;
}

//***************************************************************************
// #8
// Function:    hexToDecimal
//
// Description: 
//
// Parameters:  strNumber - 
//
// Returned:    String
//***************************************************************************
string hexToDecimal (const string &strNumber)
{
  return 0;
}

//***************************************************************************
// #9
// Function:    hexToBinary
//
// Description: 
//
// Parameters:  strNumber - 
//
// Returned:    String
//***************************************************************************
string hexToBinary (const string &strNumber)
{
  return 0;
}

//***************************************************************************
// #10
// Function:    binaryToHex
//
// Description: 
//
// Parameters:  strNumber - 
//
// Returned:    String
//***************************************************************************
string binaryToHex (const string &strNumber)
{
  return 0;
}

//***************************************************************************
// Function:    main
//
// Description: Driver for converting base
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
int main () {

  // printTitle("Hi");
  cout << hexCharToInt ('F') << endl;

  
  return EXIT_SUCCESS;
}