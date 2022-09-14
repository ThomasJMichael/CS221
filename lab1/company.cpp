#include "company.h"
#include <atomic>
#include <iostream>
#include <new>
#include <string>
namespace company
{
    struct companyNode{
        Employee::employee employee;
        companyNode* next;
    };
    company::company(std::string name)
    {
        length = 0;
        companyName = name;
        headNode = NULL;
    }

    void company::MakeEmpty()
    {
        companyNode* tempPtr;
        while (headNode != NULL) {
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
        companyNode* newNode = new companyNode;
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
        while (currentPos != NULL) {
            if (currentPos->next->employee.getName() == employee.getName()){
                tempNode = currentPos->next;
                return tempNode;
            } else {
                currentPos = currentPos->next;
            }
        }
        return NULL;
    }

    Employee::employee company::GetNextEmployee()
    {
        Employee::employee employee;
        if (currentPos == NULL){
            currentPos = headNode;
        }else {
            currentPos =  currentPos->next;
        }
        return currentPos->employee;
    }
    
    void company::promoteEmployee(Employee::employee employee)
    {
        companyNode* employeePos = getEmployee(employee);
        if (employeePos->next == NULL){
            return;
        }
        Employee::employee tempEmployee = employeePos->employee;
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
        previousNode->next->employee = tempEmployee;
    }
    
    void company::payEmployees()
    {
        int employeePosition = 0;
        currentPos = headNode;
        while (currentPos != NULL){
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
        std::cout << currentPos << " head node " << headNode << std::endl;
        if (currentPos == NULL){
            std::cout << "null here" << std::endl;
        }
        while (currentPos != NULL) {
            std::cout << "here" << std::endl;
            std::cout << "[Position " << EmployeePosition << " ] " << currentPos->employee.getName() << std::endl;
            currentPos = currentPos->next;
        }
        std::cout << "______________________________" << std::endl;
    }
    
    bool company::containsEmployee(std::string employee)
    {
        currentPos = headNode;
        bool found = false;
        while (currentPos != NULL) {
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
        while (currentPos != NULL){
            if (currentPos->employee.getName() == employee.getName()){
                return currentPos;
            } else {
                currentPos = currentPos->next;
            }
        }
        return NULL;
    }

    company::~company(){
        companyNode* tempPtr;
        while (headNode != NULL) {
            tempPtr = headNode;
            headNode = headNode->next;
            delete tempPtr;
        }
    }
}