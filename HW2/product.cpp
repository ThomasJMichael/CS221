/**
 * @file product.cpp
 * @author Thomas Michael (tjm0027@uah.edu)
 * @date 2 Aug 2022
 * @brief Implementation for the product class
 */
#include "product.h"

using namespace Product;

product::product(int productNumber,std::string desc,double price, bool taxable){
    this->productNumber = productNumber;
    this->desc = desc;
    this->price = price;
    this->taxable = taxable;
}