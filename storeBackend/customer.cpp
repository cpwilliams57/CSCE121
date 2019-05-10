//
//  Customer.cpp
//  storeBackend
//
//  Created by Cody Williams on 10/24/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include "customer.h"
#include "product.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

Customer::Customer(string name1, int customerID1, bool credit1){
    name = name1;
    customerID = customerID1;
    credit = credit1;
}

//getters
string Customer::getName() const{
    return name;
}

//**
int Customer::getID() const{
    return customerID;
}

//**
bool Customer::getCredit()const{
    return credit;
}

//**
double Customer::getBalance()const{
    return balance;
}

//setters
void Customer::setName(string name1){
    name = name1;
}

//**
void Customer::setCredit(bool hasCredit){
    credit = hasCredit;
}

//**
void Customer::processPayment(double amount1){
    if(amount1 < 0){
        throw runtime_error("Amount must be positive");
    }
    balance = balance + amount1;
}

//**
void Customer::processPurchase(double amount, Product product){
    if(amount < 0){
        throw runtime_error("Invalid amount");
    }
    if(this->getCredit() == true){
        balance = balance - amount;
    }
    else{
        if(amount > balance){
            throw runtime_error("This exceeds the customers balance. This customer has no credit.");
        }
        balance = balance - amount;
    }
    productsPurchased.push_back(product);
}

//overloading output operator
ostream& operator<<(ostream& cs, const Customer& c){
    cs << c.getName() << " " << c.getID() << " " << c.getBalance()<< " " << c.getCredit() << endl;
    return cs;
}

void Customer::listProductsPurchased(ostream& cs){
    for(int i = 0; i < productsPurchased.size(); ++i){
        cs << productsPurchased.at(i) << endl;
    }
    
}


