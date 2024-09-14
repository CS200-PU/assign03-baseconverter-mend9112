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
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const char* BIN_PREFIX = "0b";
const char* HEX_PREFIX = "0x";

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

string intToHexChar (int num)
{
  string hex;

  switch (num) {
    case 10:
      hex = "A";
      break;
    case 11:
      hex = "B";
      break;
     case 12:
      hex = "C";
      break;
     case 13:
      hex = "D";
      break;
     case 14:
      hex = "E";
      break;
     case 15:
      hex = "F";
      break;
    default:
      hex = to_string(num);
  }

  return hex;
}


//***************************************************************************
// Function:    getBase
//
// Description: Returns the base value of the value
//
// Parameters:  strNumber - value as string the base is to be determined for
//
// Returned:    Base value (D, H, B)
//***************************************************************************
char getBase (const char *strNumber)
{ 
  char baseVal;
  const int PREFIX_LEN = 2;

  int binary = strncmp (BIN_PREFIX, strNumber, PREFIX_LEN);
  int hex = strncmp (HEX_PREFIX, strNumber, PREFIX_LEN);

  if (0 == binary)
  {
    baseVal = 'B';
  }
  else if (0 == hex)
  {
    baseVal = 'H';
  }
  else
  {
    baseVal = 'D';
  }

  return baseVal;
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
  const int LEN = 38;
  const string STARS = "*****";

  for (int i = 0; i < LEN; i++)
  {
    cout << '*';
  }

  cout << endl << STARS << myTitle  << STARS << endl;

  for (int i = 0; i < LEN; i++)
  {
    cout << '*';
  }
  cout << endl;
}

//***************************************************************************
// Function:    binaryToDecimal
//
// Description: Converts a binary value to its equivalent decimal value
//
// Parameters:  strNumber - binary number to convert to decimal
//
// Returned:    String of decimal value
//***************************************************************************
string binaryToDecimal (const string &strNumber)
{
  int len = strNumber.length ();
  int decSum = 0;

  for (int i = 0; i < len; i++)
  {
    decSum += (pow (2, (len - 1) - i)) * (strNumber[i] - '0');
  }

  return to_string(decSum);
}

//***************************************************************************
// Function:    decimalToBinary
//
// Description: Converts a decimal value to its equivalent binary value
//
// Parameters:  strNumber - decimal number to convert to binary
//
// Returned:    String of binary value
//***************************************************************************
string decimalToBinary (const string &strNumber)
{
  string bin;
  int dec = stoi (strNumber);

  do
  {
    bin += to_string(dec % 2);
    dec /= 2;
  } while (dec > 0);
  
  reverse(bin.begin(), bin.end());

  return bin;
}

//***************************************************************************
// #7
// Function:    decimalToHex
//
// Description: Converts a decimal value to its equivalent hex value
//
// Parameters:  strNumber - decimal number to convert to hex
//
// Returned:    String of hex value
//***************************************************************************
string decimalToHex (const string &strNumber)
{
  string hex;
  int dec = stoi (strNumber);

  do
  {
    hex += intToHexChar (dec % 16);
    dec /= 16;
  } while (dec > 0);
  
  reverse(hex.begin(), hex.end());

  return hex;
}

//***************************************************************************
// Function:    hexToDecimal
//
// Description: Converts a hex value to its equivalent decimal value
//
// Parameters:  strNumber - binary number to convert to decimal
//
// Returned:    String of decimal value
//***************************************************************************
string hexToDecimal (const string &strNumber)
{
  int len = strNumber.length ();
  int decSum = 0;

  for (int i = 0; i < len; i++)
  {
    decSum += (pow (16, (len - 1) - i)) * hexCharToInt (strNumber[i]);
  }

  return to_string (decSum);
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
  return decimalToBinary (hexToDecimal (strNumber));
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
  return decimalToHex (binaryToDecimal (strNumber));
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
  const string TITLE = "HEX-DECIMAL-BINARY CONVERTER";
  
  string userInput;

  printTitle(TITLE);

  do {

  
    cout << "Enter your string to convert (q to quit): ";
    cin >> userInput;

    // getNumber (userInput)

    // decimalToBinary (userInput);
    // decimalToHex (userInput);
    // cout << hexToDecimal (userInput) << endl;
    // cout << binaryToDecimal (userInput) << endl;
    // cout << hexToBinary (userInput) << endl;
    cout << binaryToHex (userInput) << endl;

  } while ("q" != userInput);
  

  return EXIT_SUCCESS;
}