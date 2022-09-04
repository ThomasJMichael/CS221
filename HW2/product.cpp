#include "product.h"

using namespace Product;

product::product(int productNumber,std::string desc,double price, bool taxable){
    this->productNumber = productNumber;
    this->desc = desc;
    this->price = price;
    this->taxable = taxable;
}