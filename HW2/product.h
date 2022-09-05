/**
 * @file product.h
 * @author Thomas Michael (tjm0027@uah.edu)
 * @date 2 Aug 2022
 * @brief Header file for the product class
 */
#pragma once
#include <string>

namespace Product
{
    class product{
    public:
        int productNumber;
        std::string desc;
        double price;
        bool taxable;
        int quantity = 0;

        product(int productNumber,std::string desc,double price, bool taxable);
    };
}