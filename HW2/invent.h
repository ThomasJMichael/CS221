#pragma once
#include <vector>
#include "product.h"
#include <iostream>

namespace Invent {
    class inventory{
    private:
        struct productsInventory{
            std::vector<Product::product> inventVect;
            //productsInventory();
        };
        productsInventory productsInventory;
    public:
        //inventory();
        void addProduct(Product::product product);
        std::vector<Product::product> getInventory();
        void printInvent();
    };
}