/**
 * @file InventDriver.cpp
 * @author Thomas Michael (tjm0027@uah.edu)
 * @brief Driver to test ADT inventory for grocery checkout system.
 * @date 2022-09-03
 * 
 */
#include "invent.h"
#include "product.h"
#include <fstream>
#include <stdexcept>
#include <string.>
#include <string>

int main(){
    using namespace std;
    //File stream objects
    ifstream inFile;
    ofstream outFile;

    //Names for file stream objects
    string inFileName;
    string outFileName;

    //Variables for cmd handling
    string cmd;
    int numCommands;

    //Needed values for testingn invent
    Invent::inventory testInventory;
    string product_number_input;
    string desc_input;
    string price_input;
    string taxable_input;

    //Opening input file and error handling
    inFile.open("C:/Users/Jacob/Documents/UAH/CS221/HW2/inventTestDriver.txt");
    if (!inFile) {
        cerr << "[Error] Input file failed to open." << endl;
        return 1;
    }
    //Opening output file and error handling
    outFile.open("testDriverOutput.txt");
    if (!outFile) {
        cerr << "[Error] Output file failed to open." << endl;
        return 1;
    }
    //Read in first cmd and init num commands to zero
    inFile >> cmd;
    numCommands = 0;
    /**
     * @brief Command control loop. Continues unit it reads 'Quit' Command
     *        Commands
     *              add: adds product to inventory ADT
     *              print: prints the values of the inventory ADT
     *              quit: ends the loop 
     */
    while (cmd != "Quit") {
        numCommands++;
        //Add command reads in the next 4 lines of input and converts the data
        //into a product objects and adds it to the inventory object
        if (cmd == "add"){
            cout << "Adding product." << endl;
            inFile >> product_number_input;
            inFile >> desc_input;
            inFile >> price_input;
            inFile >> taxable_input;
            int productNumber;
            //Converts string to int and handles exception for incorrect input
            //Continues program with next cmd
            try {
                productNumber = stoi(product_number_input);
            } catch (invalid_argument &e) {
                cerr << "[Error] Invalid argument for product number." << endl;
                outFile << "Invalid product for command: " << cmd 
                        << "on command number: "<< numCommands << endl;
                inFile >> cmd;
                continue;
            }
            string desc = desc_input;
            //Converts string to double and handles exception for incorrect input
            //Continues program with next command
            double price;
            try {
                price = stod(price_input);
            } catch (invalid_argument &e) {
                cerr << "[Error] invalid arguemnt for price." << endl;
                outFile << "Invalid product for command: " << cmd 
                        << " on command number: "<< numCommands << endl;
                inFile >> cmd;
                continue; 
            }
            bool taxable = false;
            if (taxable_input == "T"){
                taxable = true;
            }
            Product::product new_product(productNumber, desc, price, taxable);
            testInventory.addProduct(new_product);
        }
        //Prints full invent to output file
        if (cmd == "print"){
            cout << "Printing inventory." << endl;
            testInventory.printInvent(outFile);
        }
        // Else case handles invalid input
        else {
            cerr << "Invalid command entered. Command: " << cmd << endl;
            outFile << "Invalid command entered. Command: " << cmd << endl;
        }
        inFile >> cmd;
    }
    cout << "Testing Complete." << endl;
    cout << numCommands << " commands completed" << endl;
}