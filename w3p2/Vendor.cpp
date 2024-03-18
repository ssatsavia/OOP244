#include "Vendor.h"
#include <limits>

using namespace std;

namespace seneca {
    void Vendor::setEmpty() {
        orders.clear();
    }

    void Vendor::takeOrders() {
        int numOrders;
        cout << "Seneca Icecream shop\n ";
        cout << "         @" << endl;
        cout << "        (' .)" << endl;
        cout << "       (*.`. )" << endl;
        cout << "        \\###/" << endl;
        cout << "         \\#/" << endl;
        cout << "          V" << endl;
        cout << "How many Icecreams?\n> ";
        cin >> numOrders;
        while (cin.fail() || numOrders <= 0) {
            cout << "Invalid input, please enter a positive integer:\n> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> numOrders;
        }
        for (int i = 0; i < numOrders; ++i) {
            cout << "Order number " << i + 1 << ":\n";
            Icecream icecream;
            icecream.getOrder();
            orders.push_back(icecream);
        }
    }

void Vendor::displayOrders() const {
    double totalCost = 0.0;
    cout << "\n********** Order Summary **********\n";
    for (size_t i = 0; i < orders.size(); ++i) {
        orders[i].printOrder(static_cast<int>(i) + 1);
        totalCost += orders[i].getPrice();
    }
    totalCost -= 5.0;
    double tax = totalCost * 0.13;
    double totalPrice = totalCost + tax;
    cout <<"-----------------------------------\n"
         << "Price:                        " << setw(5) << fixed << setprecision(2) << totalCost << "\n"
         << "Tax:                          " << setw(5) << fixed << setprecision(2) << tax << "\n"
         << "Total Price ($):             " << setw(6) << fixed << setprecision(2) << totalPrice << endl;
}



    void Vendor::clearData() {
        orders.clear();
    }
}
