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
        inline order(int customerNumber) { this->customerNumber = customerNumber; }
        void printOrder(std::ofstream &outFile);
        void addItem(Product::product product);
    };
}