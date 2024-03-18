//
//  Time.h
//  MS1
//
//  Created by Sage Satsavia on 2024-03-11.
//

#ifndef SENECA_Time_H
#define SENECA_Time_H



#include <iostream>
using namespace std;
namespace seneca {

class Time {
private:
    unsigned int minutes;
    
public:
    Time(unsigned int min = 0u);
    
    Time& reset();
    
    void write(ostream& os) const;
    
    void read(istream& is);
    
    operator unsigned int() const;
    
    Time& operator*=(int val);
    
    Time& operator-=(const Time& D);
    
    Time operator-(const Time& T) const;
    
    friend ostream& operator<<(ostream& os, const Time& T);
    
    friend istream& operator>>(istream& is, Time& T);
};

}

#endif /* Time_h */
