//
//  Product.cpp
//  storeBackend
//
//  Created by Cody Williams on 10/24/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include "product.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;


Product::Product(int productID1, std::string ProductName1):productID(productID1), name(ProductName1)
{
    ;
}
//setters
void Product::setDescription(string description1){
    description = description1;
}

//getters 
string Product::getDescription() const{
    return description;
}

//**
string Product::getName()const{
    return name;
}

//**
int Product::getID()const{
    return productID;
}

//**
int Product::getNumberSold()const{
    return numsold;
}

//**
double Product::getTotalPaid()const{
    return totalPaid;
}

//**
int Product::getInventoryCount()const{
    return inventory;
}

//**
void Product::addShipment(int shipmentQuantity1, double shipmentCost1){
    if((shipmentQuantity1 < 0)||(shipmentCost1 < 0)){
        throw runtime_error("Shipmant quantity and cost must be greater than or equal to 0");
    }
    inventory = inventory + shipmentQuantity1;
    totalPaid = totalPaid + shipmentCost1;
}

//**
void Product::reduceInventory(int purchaseQuantity1){
    if(purchaseQuantity1 < 0){
        throw runtime_error("Purchase quantity must be grreater than 0");
    }
    else if((inventory - purchaseQuantity1) < 0){
        throw runtime_error("Not enough inventory");
    }
    else{
        inventory = inventory - purchaseQuantity1;
        numsold = numsold + purchaseQuantity1;
    }
}

//**
double Product::getPrice(){
    double price;
    double total = this->getTotalPaid();
    double inventoryCount = this->getInventoryCount();
    double numberSold = this->getNumberSold();

    if((inventoryCount + numberSold) == 0){
        return 0;
    }
    else{
        price = (total / (inventoryCount + numberSold)) * 1.25;
        return price;
    }
}

//**
//overloading the output operator
ostream& operator<<(ostream& ps, const Product& p){
    ps << p.getID() << " " << p.getName() << " " << p.getDescription() << " " << p.getNumberSold() << endl;
    ps << p.getInventoryCount() << " " << p.getTotalPaid() << endl;
    return ps;
}


