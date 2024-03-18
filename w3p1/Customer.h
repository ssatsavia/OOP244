//
//  Customer.h
//  w3p1
//
//  Created by Sage Satsavia on 2024-01-30.
//

#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H
#include "Car.h"

namespace seneca {

class Customer {
private:
    int m_id;
    char* m_name;
    const Car* m_car;

public:
    Customer();
    ~Customer();

    bool isEmpty() const;
    void setEmpty();
    void deallocateMemory();
    void set(int customerId, const char* name, const Car* car);
    void display() const;
    const Car& car() const;
};

} // namespace seneca

#endif // SENECA_CUSTOMER_H
