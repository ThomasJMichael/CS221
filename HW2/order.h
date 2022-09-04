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
        inline explicit order(int customerNumber) { this->customerNumber = customerNumber; }
        static void printItem(std::ofstream &outFile, const Product::product& product);
        void printHeader(std::ofstream &outFile) const;
        void addItem(Product::product product, int qty, std::ofstream &outFile);
        static void printItemNotFound(std::ofstream &outFile, int enteredPN);

        void printTotals(std::ofstream &outFile);
    };
}