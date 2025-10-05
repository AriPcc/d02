/******************************************************************************
# Author:         Ari P. and Johnson M.
# Lab:            Discussion 2
# Date:           September 5, 2025
# Description:    This program will create a memorable password given a word or
#                 phrase, 4-digit code, and special character.
# Input:          phrase (cstring), code (cstring), character (char)
# Output:         password (cstring)
# Sources:        Discussion 2 specifications, zyBooks reference
#*****************************************************************************/

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

// Declare and initialize global constant variables
const int MAX_CHAR = 21;

// Declare functions, all of which are defined after main()
void welcome();
void readPhrase(char* word);
void readCode(char* code);
void readChar(char& special);
void createPassword(char* password, char word[], char code[], char special);
void goodbye();

int main() {
   // Declare and initialize variables for input
   char word[MAX_CHAR] = "";
   char code[MAX_CHAR] = "";
   char special = ' ';
   char password[MAX_CHAR] = "";

   welcome();
   cout << endl;

   // Get input values
   readPhrase(word);
   readCode(code);
   readChar(special);
   cout << endl;

   // Combine input values and display result
   createPassword(password, word, code, special);
   cout << "Your new password is: " << password << endl;
   cout << endl;

   goodbye();
   return 0;
}

// Name:    welcome()
// Desc:    This function prints a welcome message
// input:   None
// output:  None
// return:  void
void welcome() {
   cout << "This program will create a strong password using your answers to \
the following prompts." << endl;
}

// Name:    readPhrase(char* word)
// Desc:    This function reads a phrase from the user and keeps only the first
//          word.
// input:   phrase (cstring)
// output:  None
// return:  void
void readPhrase(char* word) {
   char phrase[MAX_CHAR] = "";
   int wordLimit = 0;

   cout << "Enter a memorable word or phrase: ";
   cin.getline(phrase, MAX_CHAR);

   // Get length of phrase until first ' '
   wordLimit = strcspn(phrase, " ");
   // Get first word in phrase
   strncpy(word, phrase, wordLimit);
}

// Name:    readCode(char* code)
// Desc:    This function reads a 4-digit number from the user
// input:   code (cstring)
// output:  None
// return:  void
void readCode(char* code) {
   bool validCode = true;
   int codeLength = 0;
   
   do {
      cout << "Enter a 4-digit number: ";
      cin.getline(code, MAX_CHAR);
      codeLength = strlen(code);

      // Ensure code is exactly 4 characters and has only numbers
      if (codeLength != 4) {
         validCode = false;
      }
      else {
         for (int i = 0; i < codeLength; i++) {
            if ( !isdigit(code[i]) ) {
               validCode = false;
            }
            else if (i == codeLength - 1) {
               validCode = true;
            }
         }
      }

      if (validCode == false) {
         cout << "Invalid answer! Please try again." << endl;
      }
      if ( cin.fail() ) {
         cin.clear();
         cin.ignore(100, '\n');
      }
   } while ( ( cin.fail() ) || (validCode == false) );
}

// Name:    readChar(char& special)
// Desc:    This function reads a special character from the user
// input:   special (char)
// output:  None
// return:  void
void readChar(char& special) {
   cout << "Enter a special character: ";
   cin >> special;

   // Ensure special is a punctuation character
   while ( ( cin.fail() ) || !ispunct(special) ) {
      if ( cin.fail() ) {
         cin.ignore(100, '\n');
         cin.clear();
      }
      cout << "Invalid answer! Please try again." << endl;
      cout << "Enter a special character: ";
      cin >> special;
   }
}

// Name:    createPassword(char* password, char word[], char code[], char special)
// Desc:    This function combines word, code, and special to create a password
// input:   None
// output:  None
// return:  void
void createPassword(char* password, char word[], char code[], char special) {
   char endChar[2] = "";
   endChar[0] = special;
   endChar[1] = '\0';

   strcpy(password, word);
   strcat(password, code);
   strcat(password, endChar);
}

// Name:    goodbye()
// Desc:    This function prints a goodbye message
// input:   None
// output:  None
// return:  void
void goodbye() {
   cout << "Don't forget to write it down!" << endl;
}