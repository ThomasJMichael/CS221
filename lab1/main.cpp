/**
 * @file main.cpp
 * @author Jacob Michael (tjm0027@uah.edu)
 * @brief  [Lab 1] Driver for company lists
 * @date 2022-09-09
 * 
 *	The only notable change I did was modify the company file to include an unemployed company.
 *	I could have not done this and created one and added it after creating all of the companies from the file
 *	but I chose not to because it seemed like a more elegant solution to just add it to the file.
 *
 */
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "company.h"

using namespace std;

int main() {

    ifstream inFile;
    ofstream outFile;
    ifstream compFile;
    string inFileName;
    string outFileName;
    string outputLabel;
    string command;

    int numCommands;

    vector<company::company*> companies;

    inFile.open("C:/Dev/CppSeries/untitled1/script");
    if (!inFile) {
        cerr << "Error opening script file." << endl;
        return 1;
    }
    compFile.open("C:/Dev/CppSeries/untitled1/company");
    if (!compFile) {
        cerr << "Error opening company file." << endl;
        return 1;
    }
    outFile.open("C:/Dev/CppSeries/untitled1/employ.out");
    if (!outFile) {
        cerr << "Error opening output.dat." << endl;
        return 1;
    }
    //Read in all the companies
    //Unemployed is the final company so all uses of vector.back will point to Unemployed list
    string line;
    while (getline(compFile, line)) {
        auto *new_company = new company::company(line);
        companies.push_back(new_company);
    }

    cout << "Enter name of test run; press return." << endl;
    cin >> outputLabel;
    outFile << "_________" << endl;
    outFile << "| " <<outputLabel << " |" << endl;
    outFile << "---------" << endl;

    inFile >> command;
    numCommands = 0;
    while (command != "END") {
        if (command == "JOIN") {
            /**
            * 	Person joins the specified company.
            *	May be first reference to person or they may be unemployed
            *	This person does not belong to another company
            *	When person joins a company they start at the bottom.
            */
            string person;
            string companyName;
            inFile >> person;
            inFile >> companyName;
            cout << "Running command " << command << " " << person << " " << companyName << endl;
            outFile << command << " " << person << " " << companyName << endl;
            outFile << "Running command " << command << " " << person << " " << companyName << endl;
            if (companies.back()->containsEmployee(person)){
                for (int i = 0; i < companies.back()->GetLength(); i++) {
                    Employee::employee currentEmployee = *companies.back()->GetNextEmployee();
                    if (currentEmployee.getName() == person) {
                        for (company::company *company: companies) {
                            if (company->getName() == companyName) {
                                company->putEmployee(currentEmployee);
                                cout << currentEmployee.getBanValue() << endl;
                                cout << "Adding employee from unemployed " << currentEmployee.getName() << endl;
                            }
                        }
                    }
                }
                companies.back()->deleteEmployee(person);
            } else {
                for (company::company *company : companies) {
                    if (company->getName() == companyName) {
                        Employee::employee new_employee(person);
                        company->putEmployee(new_employee);
                        cout << "Adding employee " << new_employee.getName() << endl;
                    }
                }
            }
        }
        else if (command == "QUIT") {
            /**
            * 	Person quits his or her hob and becomes unemployed
            * 	Assume person is already employed.
            */
            std::string person;
            inFile >> person;
            cout << "Running command " << command << " " << person << endl;
            outFile << command << " " << person << " " << endl;
            outFile << "Running command " << command << " " << person << endl;
            for (company::company *company : companies){
                if (company->containsEmployee(person)){
                    while (true) {
                        Employee::employee employeeObj = *company->GetNextEmployee();
                        if (employeeObj.getName() == person){
                            companies.back()->putEmployee(employeeObj);
                            company->deleteEmployee(person);
                            break;
                        }
                    }
                }
            }
        }
        else if (command == "CHANGE") {
            /**
            * 	<person> quits his or her job and joins <company>
            * Assume person is currently employed.
            */
            std::string person;
            std::string companyName;
            inFile >> person;
            inFile >> companyName;
            cout << "Running command " << command << " " << person << " " << companyName << endl;
            outFile << command << " " << person << " " << companyName << endl;
            outFile << "Running command " << command << " " << person << " " << companyName << endl;
            for (company::company *company : companies){
                if (company->containsEmployee(person)){
                    company::company *employedCompany = company;
                    bool notChanged = true;
                    while (notChanged) {
                        Employee::employee employeeObj = *employedCompany->GetNextEmployee();
                        if (employeeObj.getName() == person){
                            for (company::company *newCompany : companies){
                                if (newCompany->getName() == companyName){
                                    newCompany->putEmployee(employeeObj);
                                    employedCompany->deleteEmployee(person);
                                    notChanged = false;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (command == "PROMOTE"){
            /**
            * 	<person> is moved one step in the current company, ahead of immediate supervisor.
            *	If the <person> has the highest rank then no change occurs
            */
            std::string person;
            inFile >> person;
            cout << "Running command " << command << " " << person << endl;
            outFile << command << " " << person << endl;
            outFile << "Running command " << command << endl;
            for (company::company *company : companies){
                if (company->containsEmployee(person)){
                    while (true) {
                        Employee::employee employeeObj = *company->GetNextEmployee();
                        if (employeeObj.getName() == person){
                            company->promoteEmployee(employeeObj);
                            break;
                        }
                    }
                }
            }
        }
        else if (command == "DEMOTE"){
            /**
            * 	<person> is moved one step down in the current company, below his or her immediate supervisor.
            * 	If <person> has lowest rank then no change occurs
            */
            std::string person;
            inFile >> person;
            cout << "Running command " << command << " " << person << endl;
            outFile << command << " " << person << endl;
            outFile << "Running command " << command << endl;
            for (company::company *company : companies){
                if (company->containsEmployee(person)){
                    while (true) {
                        Employee::employee employeeObj = *company->GetNextEmployee();
                        if (employeeObj.getName() == person){
                            company->demoteEmployee(employeeObj);
                            break;
                        }
                    }
                }
            }
        }
        else if (command == "PAYDAY") {
            /**
            * 	Each person is paid their salary as specified
            * 	Keep track of the amount each person has earned from the start of the program.
            */
            cout << "Running command " << command << endl;
            outFile << command << endl;
            outFile << "Running command " << command << endl;
            for (company::company *company : companies){
                if (company->getName() == "Unemployed"){
                    for (int i = 0; i < company->GetLength(); i++){
                        Employee::employee* currentEmployee = company->GetNextEmployee();
                        currentEmployee->payEmployee(50);
                    }
                } else {
                    company->payEmployees();
                }
            }
        }
        else if (command == "EMPLOYEES") {
            /**
            * 	The current list of employees is printed for specified <comapany>.
            * 	Employees printed in order of rank
            */
            std::string companyName;
            inFile >> companyName;
            cout << "Running command " << command << " " << companyName << endl;
            outFile << command << " " << companyName << endl;
            outFile << "Running command " << command << " " << companyName << endl;
            for (company::company *company : companies){
                if (company->getName() == companyName){
                    company->printEmployees();
                    company->printEmployees(outFile);
                }
            }
        }
        else if (command == "UNEMPLOYED") {
            /**
            * 	Prints this list of unemployed people.
            *
            */
            cout << "Running command " << command << endl;
            outFile << command << endl;
            outFile << "Running command " << command << endl;
            companies.back()->printEmployees();
            companies.back()->printEmployees(outFile);
        }
        else if (command == "DUMP") {
            /**
            * 	prints the employees in each company, as specified under the EMPLOYEES command above, then print the unemployed people
            *  Output is labeled
            */
            cout << "Running command " << command << endl;
            outFile << command << endl;
            outFile << "Running command " << command << endl;
            cout << "Running command " << command << endl;
            for (company::company *company : companies){
                company->printEmployees();
                company->printEmployees(outFile);
            }
        }
        else {
            cout << command << " is not a valid command." << endl;
            outFile << command << " is not a valid command." << endl;
        }
        numCommands++;
        cout << " Command number " << numCommands << " completed." << endl;
        inFile >> command;
    };

    for (auto company : companies){
        cout << "----------[" <<company->getName() << "]----------" << endl;
        for (int i = 0; i < company->GetLength(); i++){
            Employee::employee currentEmployee;
            currentEmployee = *company->GetNextEmployee();
            cout << currentEmployee.getName() << " $" << currentEmployee.getBanValue() << endl;
        }
        cout << "------------------------------" << endl;
    }
    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}

