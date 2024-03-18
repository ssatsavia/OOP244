#define _CRT_SECURE_NO_WARNINGS
#include "Guest.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace seneca {

    void set(Guest& guest, const char* first, const char* last, int age) {
        if (first && last && *first && *last) {
            guest.m_firstName = new char[strlen(first) + 1];
            strcpy(guest.m_firstName, first);

            guest.m_lastName = new char[strlen(last) + 1];
            strcpy(guest.m_lastName, last);

            guest.m_adult = age >= 18;
        }
        else {
            guest.m_firstName = nullptr;
            guest.m_lastName = nullptr;
        }
    }

    void print(const Guest& guest) {
        if (guest.m_firstName && guest.m_lastName) {
            cout << guest.m_firstName << " " << guest.m_lastName;
            if (!guest.m_adult) {
                cout << "(Child)";
            }
            cout << endl;
        }
        else {
            cout << "Vacated!" << endl;
        }
    }

    void book(Guest& guest) {
        char first[100], last[100];
        int age;
        cout << "Name: ";
        cin >> first;
        cout << "Lastname: ";
        cin >> last;
        cout << "Age: ";
        cin >> age;
        set(guest, first, last, age);
    }

    void vacate(Guest& guest) {
        delete[] guest.m_firstName;
        delete[] guest.m_lastName;
        guest.m_firstName = nullptr;
        guest.m_lastName = nullptr;
    }
}
