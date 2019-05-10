//
//  main.cpp
//  Homework_2
//
//  Created by Cody Williams on 9/11/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;


int main(int argc, const char * argv[]) {
    double a = 0;
    double b = 0;
    double c = 0;
    double linearRoot = 0;
    
    cout << "enter coefficients a, b, and c ";
    cout << "Seperated by spaces: "<< endl;
    cin >> a >> b >> c;
    
    // testing for linear equation
    if (a == 0){
        cout << "This is a linear Equation: ";
        cout << b << "x + " << c << endl;
        
        linearRoot = -c / b;
        cout << "x = " << linearRoot << endl;
    }
    
    // inputs constitute a quadratic equation
    else{
        cout << a << "x^2 + " << b << "x + " << c << endl;
        //calculate discriminant
        double disc = b*b - 4 * a*c;
       
        //inputs constitute imaginary solutions
        if(disc < 0){
            double posdisc = -disc;
            double imgNum = 0;
            double bval = 0;
            
            bval = -b / (2 * a);
            imgNum = (sqrt(posdisc)) / (2 * a);
           
            
            cout << bval << " - " << imgNum << "i" << endl;
            cout << bval << " + " << imgNum << "i" << endl;
        }
        else{
            //inputs constitute  real roots
            double root1 = 0;
            double root2 = 0;
            
            root1 = (-b - sqrt(disc)) / (2 * a);
            root2 = (-b + sqrt(disc)) / (2 * a);
            cout << "x = " << root1 << endl;
            if(root1 != root2){
                cout << "x = " << root2 << endl;
            }
        }
        
    }


    return 0;

}
