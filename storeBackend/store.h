//
//  store.hpp
//  storeBackend
//
//  Created by Cody Williams on 10/27/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <string>
#include <vector>
#include "customer.h"
#include "product.h"
#ifndef store_hpp
#define store_hpp

#include <stdio.h>
class Store{
    
    std::string name;
    std::vector<Customer> customers;
    std::vector<Product> products;
    
public:
    
    Store(std::string name);
    std::string getName();
    void setName(std::string name);
    void addProduct(int productID, std::string productName);
    void addCustomer(int customerID ,std::string name);
    
    Product& getProduct(int productID);
    Customer& getCustomer(int customerID);
    void takeShipment(int productID1, int quantity1, double cost1);
    void makePurchase(int customerID1, int productID1, int quantity1);
    void takePayment(int customerID1, double amount1);
    void listProducts();
    void listCustomers();
    
};

#endif /* store_hpp */
