/**
 * @file invent.h
 * @author Thomas Michael (tjm0027@uah.edu)
 * @date 2 Aug 2022
 * @brief Header file for the store inventory.
 */
#pragma once
#include <vector>
#include "product.h"
#include <iostream>

namespace Invent {
    class inventory{
    private:
        struct productsInventory{
            std::vector<Product::product> inventVect;
        };
        productsInventory productsInventory;
    public:
        void addProduct(const Product::product& product);
        std::vector<Product::product> getInventory() const;
        void printInvent();
    };
}