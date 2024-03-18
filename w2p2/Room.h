//
//  Room.hpp
//  w2p2
//
//  Created by Sage Satsavia on 2024-01-30.
//

#ifndef SENECA_ROOM_H
#define SENECA_ROOM_H

#include "Guest.h"
#include <iostream>

namespace seneca{


struct Room {
    char m_roomNumber[6];
    int m_noOfGuests;
    Guest* m_guests;
};

void set(Room& room, int numberOfGuests, const char* roomNumber);


void print(const Room& room);


void book(Room& room);


void vacate(Room& room);
}
#endif /* Room_h */
