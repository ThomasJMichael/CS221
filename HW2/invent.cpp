#include "invent.h"
#include <vector>

using namespace Invent;

void inventory::addProduct(Product::product product){
    productsInventory.inventVect.push_back(product);
}

std::vector<Product::product> inventory::getInventory(){
    return productsInventory.inventVect;
}

void inventory::printInvent() {
    for (Product::product product : productsInventory.inventVect){
        std::cout << product.productNumber << " | "  << product.desc
        << " | " << product.price << " | " << product.taxable << std::endl;
    }
}


