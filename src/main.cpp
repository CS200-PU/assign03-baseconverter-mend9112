//******************************************************************************
// File name:   main.cpp
// Author:      Marisa Mendosa
// Date:        09/13/2024
// Class:       CS200 (Replace xx with your section number)
// Assignment:  Base Converter
// Purpose:     Convert between hexadecimal, decimal, and binary
// Hours:       3
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

//***************************************************************************
// Function:    intToHexChar
//
// Description: Converts integer value to its hex character
//
// Parameters:  num - integer value to be converted
//
// Returned:    Equivalent hex character
//***************************************************************************
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
// Function:    getNumber
//
// Description: Isolates the number from the inputed value
//
// Parameters:  prompt - user inputed value to be converted
//
// Returned:    String representing a decimal, hexadecimal, or binary number
//***************************************************************************
string getNumber (const string &prompt)
{
  string num = prompt;

  if ('D' != getBase (prompt.c_str()))
  {
    num.erase(0, 2);
  }

  return num;
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
// Function:    hexToBinary
//
// Description: Converts a hex value to its equivalent binary value
//
// Parameters:  strNumber - hex number to convert to binary
//
// Returned:    String of binary value
//***************************************************************************
string hexToBinary (const string &strNumber)
{
  return decimalToBinary (hexToDecimal (strNumber));
}

//***************************************************************************
// Function:    binaryToHex
//
// Description: Converts a binary value to its equivalent hex value
//
// Parameters:  strNumber - binary number to convert to hex
//
// Returned:    String of hex value
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
  const string TITLE = "HEX-DECIMAL-BINARY CONVERTER",
               DEC_CONV = "The decimal conversion is: ",
               HEX_CONV = "The hexadecimal conversion is: ",
               BIN_CONV = "The binary conversion is: ";

  const char DEC = 'D', 
             HEX = 'H', 
             BIN = 'B';
  
  string userInput;
  string num;
  char base;

  printTitle(TITLE);

  cout << "Enter your string to convert (q to quit): ";
  cin >> userInput;

  while ("q" != userInput) 
  {
    num = getNumber (userInput);
    base = getBase (userInput.c_str());

    if (DEC == base)
    {
      cout << BIN_CONV << BIN_PREFIX + decimalToBinary (num) << endl;
      cout << HEX_CONV << HEX_PREFIX + decimalToHex (num) << endl;
    }
    else if (HEX == base)
    {
      cout << DEC_CONV << hexToDecimal (num) << endl;
      cout << BIN_CONV << BIN_PREFIX + hexToBinary (num) << endl;
    }
    else if (BIN == base)
    {
      cout << DEC_CONV << binaryToDecimal (num) << endl;
      cout << HEX_CONV << HEX_PREFIX + binaryToHex (num) << endl;
    }

    cout << endl;

    cout << "Enter your string to convert (q to quit): ";
    cin >> userInput;
  }
  

  return EXIT_SUCCESS;
}