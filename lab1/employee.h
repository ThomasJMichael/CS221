/**
 * @file employee.h
 * @author Jacob Michael (tjm0027@uah.edu)
 * @brief Header file for employee class
 * @date 2022-09-09
 * 
 */
#pragma once

#include <string>

namespace Employee {
    class employee{
    private:
        int bankValue;
        std::string employeeName;
    public:
        employee(){
            bankValue = 0;
        }
        /**
         * @brief Constructor
         * @param name  Employee Name
         */
        employee(std::string name);
        /**
         * @brief Getter for employee bank value
         * @return bankValue
         */
        inline int getBanValue() const {return bankValue;}
        /**
         * @brief Getter for employee name
         * @return String for Employee name
         */
        inline std::string getName() const {return employeeName;}
        /**
         * Function to pay employee set amount
         * @param amount    int for amount to be paid
         */
        void payEmployee(int amount);
    };

}
