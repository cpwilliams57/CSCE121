//
//  functions.hpp
//  palindrome
//
//  Created by Cody Williams on 10/17/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <string>

using namespace std;

// print usage info
void printUsageInfo(const string& program_name);

//checks to see if string is a palindrome with case and spacce conditions
// FIX_ME include bool case_sensitive, bool ignore_spaces in function arguements
bool isPalindrome(string str, bool isSensitive, bool dontIgnoreSpaces);

//changes all letters to lowercase
string toLowerCase(string &str);

//remove punctuation
string removePunctuation(string &str);

#endif /* functions_hpp */
