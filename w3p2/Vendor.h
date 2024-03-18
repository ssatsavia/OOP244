//
//  Vendor.hpp
//  w3p2
//
//  Created by Sage Satsavia on 2024-01-30.
//
//
//  Vendor.hpp
//  w3p2
//
//  Created by Sage Satsavia on 2024-01-30.
//
#ifndef VENDOR_H
#define VENDOR_H

#include "Icecream.h"
#include <vector>

namespace seneca {
    class Vendor {
    private:
        std::vector<Icecream> orders;

    public:
        void setEmpty();
        void takeOrders();
        void displayOrders() const;
        void clearData();
    };
}

#endif // VENDOR_H

