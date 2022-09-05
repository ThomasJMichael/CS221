/**
 * @file order.h
 * @author Thomas Michael (tjm0027@uah.edu)
 * @date 2 Aug 2022
 * @brief  Header for a grocery store checkout system
 */
#pragma once
#include "product.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <iostream>

namespace Order{
    class order{
    private:
        struct items{
            std::vector<Product::product> itemVect;
        };
        items items;
    public:
        int customerNumber;
        /**
         * @brief Construct a new order object
         * 
         * @param customerNumber int for the customers number.
         */
        inline explicit order(int customerNumber) { this->customerNumber = customerNumber; }
        /**
         * @brief   prints an individual items to output file in formated form.
         * 
         * @param outFile   File to output to.
         * @param product   Product to print to output.
         */
        static void printItem(std::ofstream &outFile, const Product::product& product);
        /**
         * @brief Prints a formated header to output file.
         * 
         * @param outFile   File to print to.
         */
        void printHeader(std::ofstream &outFile) const;
        /**
         * @brief Adds an item to the order vector and prints output to file
         * 
         * @param product   Product to add.
         * @param qty       Number of products purchased.
         * @param outFile   File to print to.
         */
        void addItem(Product::product product, int qty, std::ofstream &outFile);
        /**
         * @brief Prints error message for item not found to output file
         * 
         * @param outFile    Output file.   
         * @param enteredPN  The entered product number
         */
        static void printItemNotFound(std::ofstream &outFile, int enteredPN);
        /**
         * @brief Calculates and prints the final totals at the bottom of the input file.
         * 
         * @param outFile The output file
         */
        void printTotals(std::ofstream &outFile);
    };
}