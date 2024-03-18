//  Created by Sage Satsavia on 2024-01-30.


#ifndef ICECREAM_H
#define ICECREAM_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
namespace seneca {
    class Icecream {
    private:
        string flavour;
        int numScoops;
        bool hasVanillaWafer;
        double price;

    public:
        void getOrder();
        void printOrder(int orderNo) const;
        double getPrice() const;
    };
}

#endif // ICECREAM_H
