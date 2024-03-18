//
//  Time.cpp
//  MS1
//
//  Created by Sage Satsavia on 2024-03-11.
//

#include "Time.h"
#include <iomanip>
#include<limits>
#include <iostream>
#include "Utils.h"

namespace seneca{
using namespace std;


Time::Time(unsigned int min) : minutes(min) {}

Time& Time::reset() {
    if (debug)
        minutes = U.getTime();
    else
        minutes = 0;
    return *this;
}

void Time::write(ostream& os) const {
    unsigned int hours = minutes / 60;
    unsigned int mins = minutes % 60;
    os << setw(2) << setfill('0') << hours << ":"
    << setw(2) << setfill('0') << mins;
}


void Time::read(std::istream& in) {
    char colon;
    unsigned int hours, mins;

    in >> hours;
    colon = in.peek();


    if (colon != ':') {
        in.setstate(ios::failbit);
    }
    else {
        in.ignore();
        in >> mins;
        minutes = hours * 60 + mins;
    }


}






Time::operator unsigned int() const {
    return minutes;
}

Time& Time::operator*=(int val) {
    minutes *= val;
    return *this;
}

Time& Time::operator-=(const Time& D) {
    if (minutes < D.minutes) {
        minutes += 1440;
    }
    minutes -= D.minutes;
    return *this;
}

Time Time::operator-(const Time& T) const {
    Time result(*this);
    if (result.minutes < T.minutes) {
        result.minutes += 1440;
    }
    result.minutes -= T.minutes;
    return result;
}

ostream& operator<<(ostream& os, const Time& T) {
    T.write(os);
    return os;
}

istream& operator>>(istream& is, Time& T) {
    T.read(is);
    return is;
}
}
