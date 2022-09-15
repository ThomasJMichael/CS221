/**
 * @file employee.cpp
 * @author Jacob Michael (tjm0027@uah.edu)
 * @brief Employee implementation
 * @version 0.1
 * @date 2022-09-09
 * 
 */
#include "employee.h"
namespace Employee {

    employee::employee(std::string name) {
        bankValue = 0;
        employeeName = name;
    }
    void employee::payEmployee(int amount) {
        bankValue = bankValue + amount;
    }
}

