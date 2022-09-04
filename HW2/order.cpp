#include "order.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace Order;

void order::addItem(Product::product product){
    items.itemVect.push_back(product);
}

void order::printOrder(std::ofstream &outFile){
    outFile << "------------------------------------------------------" << std::endl;
    outFile << "Customer " << customerNumber << std::endl;
    for (Product::product product : items.itemVect){

    }
}



