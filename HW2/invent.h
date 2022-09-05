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
        /**
        * @brief Adds product to a vector for inventory.
        * 
        * @param product    Product object
        */
        void addProduct(const Product::product& product);
        /**
         * @brief Get the Inventory object
         * 
         * @return std::vector<Product::product> 
         */
        std::vector<Product::product> getInventory() const;
        /**
         * @brief Prints the contents of the inventory vector to terminal.
         * 
         */
        void printInvent();
        /**
         * @brief Overloaded function to print inventory vector to file
         * 
         * @param outFile The file to write the contents of the inventory too.
         */
        void printInvent(std::ofstream &outFile);
    };
}