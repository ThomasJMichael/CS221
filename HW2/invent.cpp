/**
 * @file invent.cpp
 * @author Thomas Michael (tjm0027@uah.edu)
 * @date 2 Aug 2022
 * @brief Class for the store inventory management system
 */
#include "invent.h"
#include <fstream>
#include <ostream>
#include <vector>

using namespace Invent;

void inventory::addProduct(const Product::product& product){
    productsInventory.inventVect.push_back(product);
}

std::vector<Product::product> inventory::getInventory() const{
    return productsInventory.inventVect;
}

void inventory::printInvent() {
    for (const Product::product& product : productsInventory.inventVect){
        std::cout << product.productNumber << " | "  << product.desc
        << " | " << product.price << " | " << product.taxable << std::endl;
    }
}

void inventory::printInvent(std::ofstream &outFile) {
    outFile << "==========[Inventory]==========" << std::endl;
    for (const Product::product& product : productsInventory.inventVect){
        outFile << product.productNumber << " | "  << product.desc
        << " | " << product.price << " | " << product.taxable << std::endl;
    }
    outFile << "===============================" << std::endl;
}

