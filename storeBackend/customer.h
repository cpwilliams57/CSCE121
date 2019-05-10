//
//  Customer.hpp
//  storeBackend
//
//  Created by Cody Williams on 10/24/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#ifndef Customer_hpp
#define Customer_hpp
#include "product.h"
#include <vector>
#include <string>
#include <stdio.h>

class Customer{
    int customerID;
    std::string name;
    bool credit;
    double balance = 0;
    
    //list of products 
    std::vector<Product> productsPurchased;
    
public:
    Customer(std::string name, int customerID, bool credit);
    std::string getName()const;
    void setName(std::string name);
    int getID() const;
    bool getCredit()const;
    void setCredit(bool hasCredit);
    double getBalance()const;
    
    //part 2 
    void processPayment(double amount);
    void processPurchase(double amount, Product product);
    void listProductsPurchased(std::ostream& os);
};

std::ostream& operator<<(std::ostream& cs, const Customer& c);

#endif /* Customer_hpp */

