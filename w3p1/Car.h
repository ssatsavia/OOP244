//
//  Car.h
//  w3p1
//
//  Created by Sage Satsavia on 2024-01-30.
//

#ifndef SENECA_CAR_H
#define SENECA_CAR_H

namespace seneca {

class Car {
private:
    char m_licencePlate[9];
    char* m_makeModel;
    char* m_serviceDesc;
    double m_cost;

public:
    Car();
    ~Car();
    
    bool isEmpty() const;
    void setEmpty();
    void deallocateMemory();
    void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
    void display() const;
};

} // namespace seneca

#endif // SENECA_CAR_H

