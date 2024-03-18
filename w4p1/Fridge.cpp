//
//  w4p1
//
//  Created by Sage Satsavia on 2024-02-09.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Fridge.h"
using namespace std;

namespace seneca{

const char* Food::name() const {
   return m_name;
}
int Food::weight() const {
   return m_weight;
}
Food::Food() {}

Food::Food(const char* nm, int wei) {
   strncpy(m_name, nm, NAME_LEN);
   m_weight = wei;
}

Fridge::Fridge() : m_numFoods(0), m_model(nullptr) {}
Fridge::Fridge(Food farr[], int nf, const char* mod) {
    int i;
    if (nf > 0)
    {
        m_numFoods = (nf < FRIDGE_CAP) ? nf : FRIDGE_CAP;
    }
    if (mod!=nullptr && mod[0] != '\0')
    {
        m_model = new char[NAME_LEN];
        strcpy(m_model, mod);
    }
    for (i = 0; i < m_numFoods; i++)
    {
        m_foods[i] = farr[i];
    }

}
Fridge::~Fridge() {
    delete[] m_model;
}

bool Fridge::addFood(const Food& f) {
    if (m_numFoods < FRIDGE_CAP) {
        m_foods[m_numFoods++] = f;
        return true;
    }
    return false;
}

void Fridge::changeModel(const char* m) {
    if (m != nullptr && m[0] != '\0') {
        delete[] m_model;
        m_model = new char[strlen(m) + 1];
        strcpy(m_model, m);
    }
}
bool Fridge::fullFridge() const {
    return m_numFoods == FRIDGE_CAP;
}
bool Fridge::findFood(const char* f) const {
    for (int i = 0; i < m_numFoods; ++i) {
        if (strcmp(m_foods[i].name(), f) == 0) {
            return true;
        }
    }
    return false;
}
ostream& Fridge::display(ostream& os) const {

    int i = 0;
    if (m_model != nullptr && m_model[0] != '\0') {
        os << "Fridge Model: " << m_model << endl
            << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << endl
            << "List of Foods" << std::endl;
        for (i = 0; i < m_numFoods; ++i) {
            os << right << setw(20) << m_foods[i].name() << " | " << m_foods[i].weight() << endl;
        }
    }
    return os;
}


}


