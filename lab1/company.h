#pragma once
#include "employee.h"
#include <fstream>
#include <string>

namespace company {
    struct companyNode;
    class company{
        public:
        company(std::string name);
        ~company();
        void MakeEmpty();
        // Function: Returns the list to the empty state.
        // Post:  List is empty.
        bool IsFull() const;
        // Function:  Determines whether list is full.
        // Pre:  List has been initialized.
        // Post: Function value = (list is full)

        int GetLength() const;
        // Function: Determines the number of elements in list.
        // Pre:  List has been initialized.
        // Post: Function value = number of elements in list


        void putEmployee(Employee::employee employee);
        // Function: Adds item to list.
        // Pre:  List has been initialized.
        //       List is not full.
        //       item is not in list.
        // Post: item is in list.

        void deleteEmployee(std::string employee);
        // Function: Deletes the element whose key matches item's key.
        // Pre:  List has been initialized.
        //       Key member of item is initialized.
        //       One and only one element in list has a key matching item's key.
        // Post: No element in list has a key matching item's key.

        void ResetList();
        // Function: Initializes current position for an iteration through the list.
        // Pre:  List has been initialized.
        // Post: Current position is prior to list.

        Employee::employee GetNextEmployee();
        // Function: Gets the next element in list.
        // Pre:  List has been initialized and has not been changed since last call.
        //       Current position is defined.
        //       Element at current position is not last in list.
        //	     
        // Post: Current position is updated to next position.
        //       item is a copy of element at current position.

        void promoteEmployee(Employee::employee employee);
        void demoteEmployee(Employee::employee employee);
        void payEmployees();
        void printEmployees();
        bool containsEmployee(std::string employee);
        companyNode* getEmployee(Employee::employee employee);
        companyNode* getPreviousEmployee(Employee::employee employee);

        inline std::string getName(){ return companyName;};

        private:
        std::string  companyName;
        companyNode* headNode;
        int length;
        companyNode* currentPos;
    };
};