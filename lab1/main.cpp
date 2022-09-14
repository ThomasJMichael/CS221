#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
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

	int number;
	bool found;
	int numCommands;

	vector<company::company> companies;

  	inFile.open("input.dat");
  	if (!inFile) {
    	cerr << "Error opening script file." << endl;
    	return 1;
  	}
	compFile.open("company");
  	if (!inFile) {
    	cerr << "Error opening company file." << endl;
    	return 1;
  	}
  	outFile.open("output.dat");
  	if (!outFile) {
    	cerr << "Error opening output.dat." << endl;
    	return 1;
  	}
	//Read in all the companies
	string line;
	while (getline(compFile, line)) {
        company::company new_company(line);
        companies.push_back(new_company);
	}

  	cout << "Enter name of test run; press return." << endl;
	cin >> outputLabel;
	outFile << outputLabel << endl;

	//TODO Adding parsing for commands being on same line
	inFile >> command;
	numCommands = 0;
	while (command != "END") {
		if (command == "JOIN") {
			/** //TODO	JOIN <person> <company>
			* 	Person joins the specified company. 
			*	May be first reference to person or they may be unemployed
			*	This person does not belong to another company
			*	When person joins a company they start at the bottom.
			*/
			std::string person;
			std::string companyName;
			inFile >> person;
			inFile >> companyName;
			if (companies.back().containsEmployee(person)){
				companies.back().deleteEmployee(person);
			}
			for (company::company company : companies){
				if (company.getName() == companyName){
					Employee::employee new_employee(person);
					company.putEmployee(new_employee);
					std::cout << "Adding employee " << new_employee.getName() << endl;
				}
			}
		}
		else if (command == "QUIT") {
			/** //TODO Quit <person>
			* 	Person quits his or her hob and becomes unemployed
			* 	Assume person is already employed.
			*/
			std::string person;
			inFile >> person;
			for (company::company company : companies){
				if (company.containsEmployee(person)){
					while (true) {
						Employee::employee employeeObj = company.GetNextEmployee();
						if (employeeObj.getName() == person){
							companies.back().putEmployee(employeeObj);
							company.deleteEmployee(person);
							break;
						}
					}
				}
			}
		}
		else if (command == "CHANGE") {
			/** //TODO Change <person> <comapny>
			* 	<person> quits his or her job and joins <company> 
			* Assume person is currently employed.
			*/
			std::string person;
			std::string companyName;
			inFile >> person;
			inFile >> companyName;
			for (company::company company : companies){
				if (company.containsEmployee(person)){
					company::company employedCompany = company;
					while (true) {
						Employee::employee employeeObj = company.GetNextEmployee();
						if (employeeObj.getName() == person){
							for (company::company company : companies){
								if (company.getName() == companyName){
									company.putEmployee(employeeObj);
									employedCompany.deleteEmployee(person);
									break;
								}
							}
						}
					}
				}
			}
		}
		else if (command == "PROMOTE"){
			/** //TODO Promote <person>
			* 	<person> is moved one step in the current company, ahead of immediate supervisor.
			*	If the <person> has the highest rank then no change occurs
			*/
			std::string person;
			inFile >> person;
			for (company::company company : companies){
				if (company.containsEmployee(person)){
					while (true) {
						Employee::employee employeeObj = company.GetNextEmployee();
						if (employeeObj.getName() == person){
							company.promoteEmployee(employeeObj);
							break;
						}
					}
				}
			}
		}
		else if (command == "DEMOTE"){
			/** //TODO Demote <person>
			* 	<person> is moved one step down in the current company, below his or her immediate supervisor.
			* 	If <person> has lowest rank then no change occurs
			*/
			std::string person;
			inFile >> person;
			for (company::company company : companies){
				if (company.containsEmployee(person)){
					while (true) {
						Employee::employee employeeObj = company.GetNextEmployee();
						if (employeeObj.getName() == person){
							company.demoteEmployee(employeeObj);
							break;
						}
					}
				}
			}			
		}
		else if (command == "PAYDAY") {
			/**	//TODO Payday
			* 	Each person is paid their salary as specified
			* 	Keep track of the amount each person has earned from the start of the program.
			*/
			for (company::company company : companies){
				if (company.getName() == "Unemployed"){
					for (int i = 0; i < company.GetLength(); i++){
						company.GetNextEmployee().payEmployee(50);
					}
				} else {
					company.payEmployees();
				}
			}
		}
		else if (command == "EMPLOYEES") {
			/**	//TODO Employees <comapny>
			* 	The current list of employees is printed for specified <comapany>.
			* 	Employees printed in order of rank
			*/
			std::string companyName;
			inFile >> companyName;
			for (company::company company : companies){
				if (company.getName() == companyName){
					company.printEmployees();
				}
			}
		}
		else if (command == "UNEMPLOYED") {
			/**	//TODO Unemployed
			* 	Prints this list of unemployed people.
			* 
			*/
			companies.back().printEmployees();
		}
		else if (command == "DUMP") {
			/** //TODO Dump
			* 	prints the employees in each company, as specified under the EMPLOYEES command above, then print the unemployed people
			*  Label the output
			*/
			for (company::company company : companies){
				company.printEmployees();
			}
		}
		else
		cout << command << " is not a valid command." << endl;

		numCommands++;
		cout << " Command number " << numCommands << " completed." << endl;
		//TODO When an employee is mentioned add a reference to the employee to a vector then at end print their bank account
		inFile >> command;
	};

	cout << "Testing completed." << endl;
	inFile.close();
	outFile.close();
	return 0;
	}

