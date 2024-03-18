//
//  Customer.cpp
//  w3p1
//
//  Created by Sage Satsavia on 2024-01-30.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

namespace seneca {

    Customer::Customer() {
        setEmpty();
    }

    Customer::~Customer() {
        deallocateMemory();
    }

    bool Customer::isEmpty() const
    {
        bool result = false;
        if (m_car == nullptr)
        {
            if (m_name == nullptr || strlen(m_name) == 0 || m_car == nullptr)
            {
                result = true;
            }
            else
            {
                result = false;
            }

        }
        else
        {
            result = false;
        }
        if (m_name == nullptr ||m_name[0]=='\0')
        {
            result = true;
        }
        return result;
    }

    void Customer::setEmpty() {
        m_id = 0;
        m_name = nullptr;
        m_car = nullptr;
    }

    void Customer::deallocateMemory() {
        delete[] m_name;
        setEmpty();
    }

    void Customer::set(int customerId, const char* name, const Car* car) {
        deallocateMemory();
        setEmpty();
        if (name && car) {
            m_id = customerId;

            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);

            m_car = car;
        }
       
    }

    void Customer::display() const
    {
        cout << left << setw(15) << "Customer ID:"
            << right << setw(20) << m_id << endl;
        cout << left << setw(15) << "First Name:"
            << right << setw(20) << (m_name ? m_name : "") << endl;
        
        if (m_car != nullptr)
        {

            m_car->display();
        }
    }

    const Car& Customer::car() const {

        return *m_car;
    }

} // namespace seneca
