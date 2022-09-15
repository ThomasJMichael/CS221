/**
 * @file company.cpp
 * @author Jacob Michael (tjm0027@uah.edu)
 * @brief implementation for company list
 * @date 2022-09-09
 * 
 */
#include "company.h"
#include <atomic>
#include <iostream>
#include <new>
#include <string>
namespace company
{
    struct companyNode{
        Employee::employee employee;
        companyNode* next{};
    };
    company::company(std::string name)
    {
        length = 0;
        companyName = name;
        headNode = nullptr;
    }

    void company::MakeEmpty()
    {
        companyNode* tempPtr;
        while (headNode != nullptr) {
            tempPtr = headNode;
            headNode = headNode->next;
            delete tempPtr;
        }
        length = 0;
    }

    bool company::IsFull() const
    {
        companyNode* newNode;
        try{
            newNode = new companyNode;
        } catch (std::bad_alloc &e){
            return true;
        }
        return false;
    }

    int company::GetLength() const
    {
        return length;
    }


    void company::putEmployee(Employee::employee employee)
    {
        auto* newNode = new companyNode;
        newNode->employee = employee;
        newNode->next = headNode;
        headNode = newNode;
        length++;
    }

    void company::deleteEmployee(std::string employee)
    {
        companyNode* location = headNode;
        companyNode* tempNode;
        if (employee == headNode->employee.getName()){
            tempNode = headNode;
            headNode = headNode->next;
        }
        else {
            while (location->next->employee.getName() != employee) {
                location = location->next;
            }
            tempNode = location->next;
            location->next = location->next->next;
        }
        delete tempNode;
        length--;
    }

    companyNode* company::getPreviousEmployee(Employee::employee employee){
        companyNode* tempNode;
        currentPos = headNode;
        while (currentPos != nullptr) {
            if (currentPos->next->employee.getName() == employee.getName()){
                tempNode = currentPos->next;
                return tempNode;
            } else {
                currentPos = currentPos->next;
            }
        }
        return nullptr;
    }

    Employee::employee* company::GetNextEmployee()
    {
        Employee::employee *employee;
        if (currentPos == nullptr){
            currentPos = headNode;
        }else {
            if (currentPos->next == nullptr){
                currentPos = headNode;
                return &headNode->employee;
            }
            currentPos =  currentPos->next;
        }
        employee = &currentPos->employee;
        return employee;
    }

    void company::promoteEmployee(Employee::employee employee)
    {
        companyNode* employeePos = getEmployee(employee);
        if (employeePos->next == nullptr){
            return;
        }
        Employee::employee tempEmployee = employeePos->next->employee;
        employeePos->next->employee = employee;
        employeePos->employee = tempEmployee;
    }

    void company::demoteEmployee(Employee::employee employee)
    {
        companyNode* currNode = getEmployee(employee);
        if (currNode == headNode){
            return;
        }
        companyNode* previousNode = getPreviousEmployee(employee);
        Employee::employee tempEmployee = previousNode->employee;
        previousNode->employee = employee;
        currNode->employee = tempEmployee;
    }

    void company::payEmployees()
    {
        int employeePosition = 0;
        currentPos = headNode;
        while (currentPos != nullptr){
            employeePosition++;
            currentPos->employee.payEmployee(employeePosition*1000);
            currentPos = currentPos->next;
        }
    }

    void company::printEmployees()
    {
        int EmployeePosition = 0;
        currentPos = headNode;
        std::cout << "----------[" << companyName << "]----------" << std::endl;
        while (currentPos != nullptr) {
            std::cout << "[Position " << EmployeePosition << " ] " << currentPos->employee.getName() << std::endl;
            currentPos = currentPos->next;
            EmployeePosition++;
        }
        std::cout << "______________________________" << std::endl;
    }
    void company::printEmployees(std::ofstream &outFile)
    {
        int EmployeePosition = 0;
        currentPos = headNode;
        outFile << "----------[" << companyName << "]----------" << std::endl;
        while (currentPos != nullptr) {
            outFile << "[Position " << EmployeePosition << " ] " << currentPos->employee.getName() << std::endl;
            currentPos = currentPos->next;
            EmployeePosition++;
        }
        outFile << "______________________________" << std::endl;
    }
    bool company::containsEmployee(std::string employee)
    {
        currentPos = headNode;
        bool found = false;
        while (currentPos != nullptr) {
            if (currentPos->employee.getName() == employee){
                found = true;
                break;
            }
            else {
                currentPos = currentPos->next;
            }
        }
        return found;
    }
    companyNode* company::getEmployee(Employee::employee employee){
        currentPos = headNode;
        while (currentPos != nullptr){
            if (currentPos->employee.getName() == employee.getName()){
                return currentPos;
            } else {
                currentPos = currentPos->next;
            }
        }
        return nullptr;
    }

    company::~company(){
        companyNode* tempPtr;
        while (headNode != nullptr) {
            tempPtr = headNode;
            headNode = headNode->next;
            delete tempPtr;
        }
    }
}