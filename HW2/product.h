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
        /**
         * @brief Construct a new product object
         * 
         * @param productNumber 5 digit int for product number
         * @param desc          string short description of product
         * @param price         double for price
         * @param taxable       boolean for if the item is taxable
         */
        product(int productNumber,std::string desc,double price, bool taxable);
    };
}