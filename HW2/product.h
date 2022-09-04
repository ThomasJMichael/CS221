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