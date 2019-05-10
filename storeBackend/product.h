//
//  Product.hpp
//  storeBackend
//
//  Created by Cody Williams on 10/24/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#ifndef Product_hpp
#define Product_hpp
#include <string>

#include <stdio.h>
class Product{
    int productID;
    std::string name;
    std::string description; 
    int inventory = 0;
    int numsold = 0;
    double totalPaid = 0;
    double price = 0;
    
public:
    Product(int productID, std::string ProductName);
    std::string getDescription() const;
    void setDescription(std::string description);
    std::string getName() const;
    int getID() const;
    int getNumberSold()const;
    double getTotalPaid()const;
    int getInventoryCount()const;
    
    //Part 2
    void addShipment(int shipmentQuantity, double shipmentCost);
    void reduceInventory(int purchaseQuantity);
    double getPrice(); 
};

std::ostream& operator<<(std::ostream& ps, const Product& p);

#endif /* Product_hpp */
