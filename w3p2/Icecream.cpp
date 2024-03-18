#include "Icecream.h"
#include <limits>

using namespace std;

namespace seneca {
    void Icecream::getOrder() {
        cout << "Select flavour:\n"
             << "----------------\n"
             << "1: Chocolate\n"
             << "2: Strawberry\n"
             << "3: Mango\n"
             << "4: Tutti fruit\n"
             << "5: Almond crunch\n"
             << "----------------\n> ";
        
        
        int choice;
        cin >> choice;
                while (cin.fail()||choice < 1 || choice > 5) {
                    if (cin.fail()) {
                        cout << "Invalid entry, retry\n> ";
                                   cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                               } else if (choice == 0) {
                                   cout << "Invlid value(1<=val<=5)\n> ";
                               } else {
                                   cout << "Invlid value(1<=val<=5)\n> ";
                               }
                               cin >> choice;
                           }
        
        switch (choice) {
            case 1:
                flavour = "Chocolate";
                price = 5.0;
                break;
            case 2:
                flavour = "Strawberry";
                price = 5.0;
                break;
            case 3:
                flavour = "Mango";
                price = 5.0;
                break;
            case 4:
                flavour = "Tutti fruit";
                price = 5.0;
                break;
            case 5:
                flavour = "Almond crunch";
                price = 5.0;
                break;
            default:
                break;
        }
        
        
   
        cout << "Number of Scoops (max 3)\n> ";
        cin >> numScoops;
        while (cin.fail() || numScoops < 1 || numScoops > 3) {
        if (cin.fail()) {
                       cout << "Invalid entry, retry\n> ";
                       cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   } else if (numScoops == 0) {
                       cout << "Invlid value(1<=val<=3)\n> ";
                   } else {
                       cout << "Invlid value(1<=val<=3)\n> ";
                   }
                   cin >> numScoops;
               }
        
        
        
        char choiceChar;
        cout << "Vanilla wafer cone?\n(Y)es/(N)o > ";
        cin >> choiceChar;
        while (choiceChar != 'Y' && choiceChar != 'y' && choiceChar != 'N' && choiceChar != 'n') {
            cout << "Only Y or N are acceptable:\n> ";
            cin.clear(); // Clear any error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input buffer
            cin >> choiceChar;
        }
        if (choiceChar == 'Y' || choiceChar == 'y') {
            hasVanillaWafer = true;
        } else {
            cout << "Only Y or N are acceptable:\n> ";
            cin.clear(); // Clear any error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input buffer
            cin >> choiceChar;
            // Handle the error condition
        }
    }

void Icecream::printOrder(int orderNo) const {
    double totalCost = numScoops * price;
    // Add extra cost for chocolate flavor
    if (flavour == "Chocolate") {
        totalCost += numScoops * 1.00;
    }
    // Output order details
    cout << "Order No: " << orderNo << ":\n"
         << "Order details:                Price\n"
         << "-----------------------------------\n"
         << "Number of scoops, " << numScoops << " total:    " << setw(5) << fixed << setprecision(2)
         << numScoops * price << "\n" << flavour << " flavour";

    // Output chocolate price if flavour is chocolate
    if (flavour == "Chocolate") {
        cout << ":             " << setw(4) << fixed << setprecision(2) << numScoops * 1.0 << endl;
    }

    // Output vanilla wafer if included in the first order
    if (hasVanillaWafer && orderNo == 1) {
        cout << "Vanilla Wafer:                 " << fixed << setprecision(2) << "5.00\n";
        totalCost+= 5.0;
    } else {
        cout << "\nVanilla Wafer:                 " << fixed << setprecision(2) << "0.00\n";
    }

    // Output total price for this order
    cout << "Price:                        " << setw(5) << fixed << setprecision(2) << totalCost << "\n";
    
    if (orderNo == 1){
        cout << endl ;
    }
}


double Icecream::getPrice() const {
    return numScoops * price + (flavour == "Chocolate" ? numScoops * 1.00 : 0.0) + (hasVanillaWafer ? 5.0 : 0.0);    
    
}
        
        
    }

