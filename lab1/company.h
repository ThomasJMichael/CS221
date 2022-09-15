/**
 * @file company.h
 * @author Jacob Michael (tjm0027@uah.edu)
 * @brief Header file for company class
 * @date 2022-09-09
 * 
 */
#pragma once
#include "employee.h"
#include <fstream>
#include <string>

namespace company {
    struct companyNode;
    class company{
    public:
        /**
         * @breif Constructor for company list of employees
         * @param name String for company name;
         */
        explicit company(std::string name);
        /**
         * @brief Destructor. Frees memory allocated on heap.
         */
        ~company();
        /**
         * @brief empty's the list
         */
        void MakeEmpty();
        /**
         * @brief Checks if the heap has enough memory to allocate another node
         * @return bool for if the heap has enough space to allocate another node
         */
        bool IsFull() const;
        /**
         * @breif Getter for length of list
         * @return int length of list
         */
        int GetLength() const;
        /**
         * @brief Adds an employee object to list
         * @param employee Employee object
         */
        void putEmployee(Employee::employee employee);
        /**
         * @brief Removes given employee from list
         * @param employee Employee object
         */
        void deleteEmployee(std::string employee);
        /**
         * @brief returns pointer to next employee node
         * @return Pointer to next employee node
         */
        Employee::employee* GetNextEmployee();
        /**
         * @brief Promotes employee to position + 1
         * @param employee Employee to be promoted
         */
        void promoteEmployee(Employee::employee employee);
        /**
         * @brief demotes employee to position - 1
         * @param employee Employee to be demoted
         */
        void demoteEmployee(Employee::employee employee);
        /**
         * @brief Pays all employees in the list
         */
        void payEmployees();
        /**
         * @brief prints all employee names from the list
         */
        void printEmployees();
        /**
         * @brief Overloaded function to print all employee names from list to file
         * @param outFile  output file
         */
        void printEmployees(std::ofstream &outFile);
        /**
         * @brief Checks if an employee of the given name is in the list
         * @param employee string for employee in list
         * @return bool for if the employee name is found
         */
        bool containsEmployee(std::string employee);
        /**
         * @brief gets node of specific employee object
         * @param employee Employee to find
         * @return Pointer to given employees node
         */
        companyNode* getEmployee(Employee::employee employee);
        /**
         * @brief Gets a pointer to the previous node of the given employee.
         * @param employee Given employee object
         * @return Pointer to node before the given employees node
         */
        companyNode* getPreviousEmployee(Employee::employee employee);
        /**
         * @brief Returns the name of the company
         * @return string for company name
         */
        inline std::string getName(){ return companyName;};
    private:
        std::string  companyName;
        companyNode* headNode;
        int length;
        companyNode* currentPos;
    };
};