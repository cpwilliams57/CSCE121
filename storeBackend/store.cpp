//
//  store.cpp
//  storeBackend
//
//  Created by Cody Williams on 10/27/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <string>
#include <stdexcept>
#include "store.h"
#include "product.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include "customer.h"
using namespace std;

Store::Store(string name1){
    name = name1;
}

//getters
string Store::getName(){
    return name;
}

//setters
void Store::setName(string name1){
    name = name1;
}

//**
void Store::addProduct(int productID1, string productName1){
    for(int i=0;i<products.size();++i)
    {
        if(products[i].getID() == productID1){
            throw runtime_error("Product already exists");
        }
    }
    Product newProduct(productID1, productName1);
    products.push_back(newProduct);
}

//**
void Store::addCustomer(int customerID1, std::string customerName1){
    for(int i = 0; i < customers.size(); ++i){
        if(customers[i].getID() == customerID1){
            throw runtime_error("Customer already exists");
        }
    }
    bool credit1;
    Customer newCustomer(customerName1,customerID1, credit1);
    customers.push_back(newCustomer);
}

//**
Product& Store::getProduct(int productID){
    bool foundProduct = false;
    int index = 0;
    for(int i = 0; i < products.size(); ++i){
        if(products.at(i).getID() == productID){
            foundProduct = true;
            index = i;
        }
    }
    if(foundProduct == false){throw runtime_error("Product not found");}
    return products.at(index);
}

//**
Customer& Store::getCustomer(int customerID){
    bool foundCustomer = false;
    int index = 0;
    for(int i = 0; i < customers.size(); ++i){
        if(customers.at(i).getID() == customerID){
            foundCustomer = true;
            index = i;
        }
    }
    if(foundCustomer == false){throw runtime_error("Customer not found");}
    return customers.at(index);
}

//**FIXME
void Store::takeShipment(int productID1, int quantity1, double cost1){
    Product &thisProduct = getProduct(productID1);
    thisProduct.addShipment(quantity1, cost1);
}

//**
void Store::makePurchase(int customerID1, int productID1, int quantity1){
    Customer &thisCustomer = getCustomer(customerID1);
    Product &thisProduct = getProduct(productID1);
    double totalPrice = thisProduct.getPrice() * quantity1;
    thisCustomer.processPurchase(totalPrice, thisProduct);
    thisProduct.reduceInventory(quantity1);
}

//**
void Store::takePayment(int customerID1, double amount1){
    Customer &thisCustomer = getCustomer(customerID1);
    thisCustomer.processPayment(amount1);
}

//**
void Store::listCustomers(){
    for(int i = 0; i < customers.size(); ++i){
        Customer thisCustomer = customers.at(i);
        cout<<thisCustomer<<endl;
    }
}

//**
void Store::listProducts(){
    for(int i = 0; i < products.size(); ++i){
        Product thisProduct = products.at(i);
        cout << thisProduct << endl;
    }
}

