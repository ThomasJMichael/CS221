#include "invent.h"
#include "order.h"
#include "product.h"
#include <cctype>
#include <cstring>
#include <ctype.h>
#include <fstream>
#include <string.>
#include <iostream>
#include <string>

#define MAX_PN 5



using namespace std;
int main(){

    bool customer = true;
    bool customerOrder = true;
    int customerNumber = 0;
    string line;
    Invent::inventory storeInventory;
    
    ifstream inFile;
    ofstream *outFile;
    inFile.open("invent.dat");
    if (!inFile){
        cerr << "Error opening input file." << endl;
    }
    outFile->open("output.dat");
    if (!outFile){
        cerr << "Error opening output.dat" << endl;
    }

    getline(inFile, line);
    while (getline(inFile, line)){
        //getline(inFile, line);
        int productNumber = stoi(line.substr(0,MAX_PN));
        size_t pos1 = line.find(' ',MAX_PN+1);
        string desc = line.substr(MAX_PN+1, pos1-MAX_PN);
        size_t pos2 = line.find(' ',pos1+1);
        double price = stod(line.substr(pos1+1, pos2-pos1));
        size_t pos3 = line.find(' ',pos2);
        string tax = line.substr(pos3+1);
        bool taxable;
        if (tax == "T")
            taxable = true;
        else taxable = false;
        Product::product newProduct(productNumber, desc, price, taxable);
        storeInventory.addProduct(newProduct);
    }
    
    while (customer) {
        customerNumber++;
        string input;
        int productNumber;
        int quantity;

        while (customerOrder){
            Order::order customerOrder(customerNumber);
            cout << "Enter product number and quantity." << endl;
            getline(cin, input);
            productNumber = stoi(input.substr(0,MAX_PN));
            quantity = stoi(input.substr(MAX_PN));
            cout << productNumber << " | " << quantity << endl;
            if (quantity > 100){
                cerr << "Quantity cannot be greater than 100." << endl;
                continue;
            }
            if (productNumber == 0.0){
                customerOrder.printOrder(*outFile);
                char input, formatedInput;
                cout << "Is there another customer? 'Y' or 'N'" << endl;
                cin >> input;
                formatedInput = tolower(input);
                if (formatedInput == 'y'){
                    customerOrder = false;
                }
            }
        }
        break;
    }

    storeInventory.printInvent();
}