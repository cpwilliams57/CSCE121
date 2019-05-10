//
//  main.cpp
//  storeBackend
//
//  Created by Cody Williams on 10/24/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "store.h"
using namespace std;

int main() {
    Customer me("name", 12345, true);
    Store mystore("My Store");
    
//    cout << me.getBalance() << endl;
//    me.processPayment(6354.86);
//    cout << me.getBalance() << endl;
    
    Product someProduct(12, "thisProduct");
    someProduct.addShipment(26, 20892.2);
    
    cout << someProduct.getPrice() << endl;
    
    //testing addproduct
    mystore.addProduct(5555, "some product");
    //cout << mystore.getProduct(5555) << endl;
    
    
    //testing addCustomer
    mystore.addCustomer(1234, "cody");
    //cout << mystore.getCustomer(1234) << endl;
    
    //testing listing functions
    //mystore.listProducts();
    //mystore.listCustomers();
    
    return 0;
    
}
