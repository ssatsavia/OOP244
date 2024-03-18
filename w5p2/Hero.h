#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "Power.h"
#include <iostream>
#include <cstring>


namespace seneca 
{
	const int MAX_POWERS = 10;

	class Hero
    {
		char m_name[MAX_NAME_LENGTH + 1];
        Power* powers;
		int numOfPowers;
        int powersLevel;
       

	public:
		Hero();
		Hero(const char* name, Power* power, int numPowers);
        ~Hero();
        
        void calPowerlevel();

        std::ostream& display() const;
       
        Hero& operator+=(const Power& power);
        Hero& operator-=(int decrease);

        friend bool operator<(const Hero& hero1, const Hero& hero2);
        friend bool operator>(const Hero& hero1, const Hero& hero2);

        friend void operator>>(const Power& power, Hero& hero);
        friend void operator<<(Hero& hero, const Power& power);
	};
}

#endif
