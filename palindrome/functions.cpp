//
//  functions.cpp
//  palindrome
//
//  Created by Cody Williams on 10/17/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <string>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>
#include "functions.h"
using namespace std;

// print usage info
void printUsageInfo(const string& program_name){
    cout << "Usage: " << program_name << " [-c] [-s] string ..." << endl;
    cout << "-c: case sensitivity turned on" << endl;
    cout << "-s: ignoring spaces turned off" << endl;
}


//changes all letters to lowercase
string toLowerCase(string &str){
    
    for(int i = 0; i < str.size(); ++i){
        str.at(i) = tolower(str.at(i));
    }
    
    return str;
}

//remove punctuation **Needs fixing...
string removePunctuation(string &str){
    
    string str1;
    
    for(int i = 0; i < str.size(); ++i){
        if(str.at(i) != ' '){
            str1 += str.at(i);
        }
    }
    
    str = str1;
    return str;
}

//checks to see if string is a palindrome with case and spacce conditions
// FIX_ME include bool case_sensitive, bool dontignore_spaces in function arguements
bool isPalindrome(string str, bool isSensitive, bool dontIgnoreSpaces){
    bool palindrome;
    
    //test is not case sensitive
    if(isSensitive == false){
        toLowerCase(str);
    }
    
    //test ignores spaces
    if(dontIgnoreSpaces == false){
        removePunctuation(str);
    }
    
    
    
    //checking to see if the given string is a palindrome under given conditions.
    if(str.size() <= 1){
        palindrome = true;
    }
    else if((str.at(0)) != (str.at(str.size() - 1))){
        palindrome = false;
    }
    else{
        str.erase(0,1);
        str.erase(str.size() - 1, 1);
        palindrome = isPalindrome(str, isSensitive, dontIgnoreSpaces);
    }
    
    return palindrome;
}
