//
//  main.cpp
//  palindrome
//
//  Created by Cody Williams on 10/17/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <iostream>
#include <string>
#include "functions.h"
using namespace std;


int main(int argc, const char * argv[]) {
    
    
    //handling flags
    bool isSensitive = false;
    bool dontIgnoreSpaces = false;
    int count = 0;
    string program_name = argv[0];
    
    for(int i = 0; i < argc; ++i){
        string temp = argv[i];
        
        //looking for different flags/flag types
        if((temp == "-c") || (temp == "-C")){
            isSensitive = true;
            count = count + 1;
        }
        
        if((temp == "-s") || (temp == "-S")){
            dontIgnoreSpaces = true;
            count = count + 1;
        }
        
        if((temp == "-cs") || (temp == "-Cs") || (temp == "-cS") || (temp == "-CS")){
            isSensitive = true;
            dontIgnoreSpaces = true;
            count = count + 1;
        }
        
        if((temp == "-sc") || (temp == "-sC") || (temp == "-Sc") || (temp == "-SC")){
            isSensitive = true;
            dontIgnoreSpaces = true;
            count = count + 1;
        }
        
    }
    
    
    
    //checking to see if substatial number of arguements
    if((argc - 1 - count) <= 0){
        printUsageInfo(program_name);
    }
    else {
        //testing each arguement entered at the command line
        for(int i = 1 + count; i < argc; ++i){
      
            if(isPalindrome(argv[i], isSensitive, dontIgnoreSpaces) == 1){
                cout << "\"" << argv[i] << "\"" << " is a palindrome." << endl;
            }
            else{
                cout << "\"" << argv[i] << "\"" << " is not a palindrome." << endl;
            }
        }
        
    }
    
}
