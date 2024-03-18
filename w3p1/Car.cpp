#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
namespace seneca {

    Car::Car() {
        setEmpty();
    }

    Car::~Car() {
        deallocateMemory();
    }

    bool Car::isEmpty() const
    {
        bool empty;
        if (m_makeModel == nullptr || m_serviceDesc == nullptr)
        {
            empty = true;
        }
        else if (strlen(m_makeModel) == 0 || strlen(m_serviceDesc) == 0)
        {
            empty = true;
        }
        else
        {
            empty = false;
        }
        return empty;
    }

    void Car::setEmpty() {
        m_licencePlate[0] = '\0';
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
        m_cost = 0.0;
    }

    void Car::deallocateMemory() {
        delete[] m_makeModel;
        delete[] m_serviceDesc;
        setEmpty();
    }

    void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost) {
        deallocateMemory();

        if (plateNo && carMakeModel && serviceDesc) {
            strncpy(m_licencePlate, plateNo, 8);
            m_licencePlate[8] = '\0';

            m_makeModel = new char[strlen(carMakeModel) + 1];
            strcpy(m_makeModel, carMakeModel);

            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_serviceDesc, serviceDesc);

            m_cost = serviceCost;
        }
        
    }

    void Car::display() const
    {
        if (m_licencePlate == nullptr || m_licencePlate[0] == '\0' || m_makeModel == nullptr ||
            m_makeModel[0] == '\0' || m_serviceDesc == nullptr || m_serviceDesc[0] == '\0')
        {
           
        }
        else
        {
            cout << left << setw(15) << "License Plate: " << right << setw(20) << (m_licencePlate ? m_licencePlate : "") << endl;
            cout << left << setw(15) << "Model: " << right << setw(20) << (m_makeModel ? m_makeModel : "") << endl;
            cout << left << setw(15) << "Service Name: " << right << setw(20) << (m_serviceDesc ? m_serviceDesc : "") << endl;
            cout << fixed << setprecision(2);
            cout << left << setw(15) << "Service Cost: " << right << setw(20) << m_cost << endl;
        }
    }


}
