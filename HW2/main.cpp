/**
 * @file main.cpp
 * @author Thomas Michael (tjm0027@uah.edu)
 * @date 2 Aug 2022
 * @brief Client code for a grocery store checkout system
 */
#include "invent.h"
#include "order.h"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

/*
 *The maximum allotted size for a product number.
 */
#define MAX_PN 5

using namespace std;

int main(){
    int customerNumber = 0;
    string line;
    Invent::inventory storeInventory;
    
    ifstream inFile;
    ofstream outFile;
    inFile.open("Invent.dat");
    if (!inFile){
        cerr << "Error opening input file." << endl;
        return 1;
    }
    outFile.open("Output.dat");
    if (!outFile){
        cerr << "Error opening output.dat" << endl;
        return 1;
    }
    while (getline(inFile, line)){
        int productNumber;
        try {
            productNumber = stoi(line.substr(0,MAX_PN));
        } catch (invalid_argument &e) {
            cerr << "Invalid input for product number." << endl;
            return 1;
        }
        size_t pos1 = line.find(' ',MAX_PN+1);
        string desc = line.substr(MAX_PN+1, pos1-MAX_PN);
        size_t pos2 = line.find(' ',pos1+1);
        double price;
        try {
            price = stod(line.substr(pos1 + 1, pos2 - pos1));
        } catch (invalid_argument &e){
            cerr << "Invalid input for price." << endl;
            return 1;
        }
        size_t pos3 = line.find(' ',pos2);
        string tax = line.substr(pos3+1);
        bool taxable;
        if (tax == "T")
            taxable = true;
        else taxable = false;
        Product::product newProduct(productNumber, desc, price, taxable);
        storeInventory.addProduct(newProduct);
    }
    
    while (true) {
        customerNumber++;
        string input;
        unsigned char continueInput, formatedInput;
        int productNumber;
        int quantity;
        Order::order customerOrder(customerNumber);
        customerOrder.printHeader(outFile);
        while (true){
            cout << "Enter product number and quantity." << endl;
            getline(cin, input);
            if (input.size() < MAX_PN){
                if (input[0] == '0'){
                    customerOrder.printTotals(outFile);
                    break;
                }else{
                    std::cerr << "Error: Invalid Input" << endl;
                    continue;
                }
            }
            productNumber = stoi(input.substr(0,MAX_PN));
            quantity = stoi(input.substr(MAX_PN));
            cout << productNumber << " | " << quantity << endl;
            if (quantity > 100){
                cerr << "Quantity cannot be greater than 100." << endl;
                continue;
            }
            for (int i = 0; i < storeInventory.getInventory().size(); i++){
                if (storeInventory.getInventory()[i].productNumber == productNumber) {
                    customerOrder.addItem(storeInventory.getInventory()[i], quantity, outFile);
                    break;
                }
                if (i == storeInventory.getInventory().size() - 1) {
                    Order::order::printItemNotFound(outFile, productNumber);
                }
            }
        }
        cout << "Is there another customer? 'Y' or 'N'" << endl;
        cin >> continueInput;
        cin.ignore();
        formatedInput = tolower(continueInput);
        if (formatedInput == 'y'){
            continue;
        }else {
            cout << "Have a nice day." << endl;
            break;
        };
    }
}