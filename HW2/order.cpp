/**
 * @file order.cpp
 * @author Thomas Michael (tjm0027@uah.edu)
 * @date 2 Aug 2022
 * @brief Implementation for the customers order and the functions for printing receipts
 */
#include "order.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace Order;

void order::addItem(Product::product product, int qty, std::ofstream &outFile){
    product.quantity = qty;
    items.itemVect.push_back(product);
    order::printItem(outFile, product);
}
void order::printHeader(std::ofstream &outFile) const{
    outFile << "==============================" << std::endl;
    outFile << "Customer " << customerNumber << std::endl;
}
void order::printItem(std::ofstream &outFile, const Product::product& product){
    outFile << product.desc << " " << product.quantity << " @ " << product.price << " " << product.quantity * product.price << std::endl;
}
void order::printItemNotFound(std::ofstream &outFile, int enteredPN){
    outFile << "*** item " << enteredPN << " not found in inventory ***" << std::endl;
}
void order::printTotals(std::ofstream &outFile){
    double subtotal = 0.0;
    double tax = 0.0;
    for (const Product::product& product : items.itemVect){
        subtotal = subtotal + product.price * product.quantity;
        if (product.taxable){
            tax = tax + (product.price * .075);
        }
    }
    outFile << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    outFile << "Subtotal  " << subtotal << std::endl;
    outFile << "Tax       " << tax << std::endl;
    outFile << std::endl;
    outFile << "Total     " << subtotal + tax << std::endl;
}



