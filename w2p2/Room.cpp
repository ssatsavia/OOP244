//
//  Room.cpp
//  w2p2
//
//  Created by Sage Satsavia on 2024-01-30.
//
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1 (P1)
Full Name  : Mussie Mulugheta
Student ID#: 151910171
Email      : mmulugheta@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// Include the header files needed for the program
#include "Room.h"
#include "Guest.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace seneca {

    void set(Room& room, int numberOfGuests, const char* roomNumber) {
        strcpy(room.m_roomNumber, roomNumber);
        room.m_noOfGuests = numberOfGuests;
        room.m_guests = new Guest[numberOfGuests];
        for (int i = 0; i < numberOfGuests; ++i) {
            room.m_guests[i].m_firstName = nullptr;
            room.m_guests[i].m_lastName = nullptr;
        }
    }

    void print(const Room& room) {
        if (room.m_guests == nullptr || room.m_noOfGuests == 0) {
            cout << "Empty Room!" << endl;
        }
        else {
            cout << "Room Number: " << room.m_roomNumber << endl;
            for (int i = 0; i < room.m_noOfGuests; ++i) {
                cout << "    ";
                print(room.m_guests[i]);
            }
        }
    }

    void book(Room& room) {
        cout << "Room number: ";
        cin >> room.m_roomNumber;
        
        cout << "Number of guests: ";
        cin >> room.m_noOfGuests;
        
        room.m_guests = new Guest[room.m_noOfGuests];
        for (int i = 0; i < room.m_noOfGuests; ++i) {
            cout << i + 1 << ":" << endl;
            book(room.m_guests[i]);
        }
    }

    
    void vacate(Room& room) {
        for (int i = 0; i < room.m_noOfGuests; ++i) {
            vacate(room.m_guests[i]);
        }
        delete[] room.m_guests;
        room.m_guests = nullptr;
    }
} // End of the "seneca" namespace
