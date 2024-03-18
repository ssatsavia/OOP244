#include "Hero.h"

using namespace std;

namespace seneca
{
    void Hero::calPowerlevel() 
    {
        powersLevel = 0;
        for(int i = 0; i < numOfPowers; i++)
        {
            powersLevel += powers[i].checkRarity();
        }
        powersLevel *= numOfPowers;
    }    
    
    Hero::Hero() : powers(nullptr), numOfPowers(0), powersLevel(0) 
    {
        m_name[0] = '\0';
    }

    Hero::Hero(const char* name, Power* power, int numPowers) 
    : numOfPowers(numPowers), powersLevel(0)
    {
        strncpy(m_name, name, MAX_NAME_LENGTH);
        m_name[MAX_NAME_LENGTH] = '\0';
        powers = new Power[numPowers];
        
        for (int i = 0; i < numPowers; ++i) 
        {
            powers[i] = power[i];
        }
        calPowerlevel();
    }

    Hero::~Hero() 
    {
        delete[] powers;
    }

    std::ostream& Hero::display() const
    {
        std:: ostream& os = std::cout;
        os << "Name: " << m_name << std::endl;
        os << "List of available powers: " << std::endl;
        for (int i = 0; i < numOfPowers; ++i) 
        {
            os <<"  Name: " << powers[i].checkName() << ", Rarity: " << powers[i].checkRarity() << endl;
        }
        os << "Power Level: " << powersLevel; 
        return os;
    }

    Hero& Hero::operator+=(const Power& power) 
    {
        Power* tempPowers = new Power[numOfPowers + 1];
        for (int i = 0; i < numOfPowers; ++i) 
        {
            tempPowers[i] = powers[i];
        }
        tempPowers[numOfPowers] = power;
        ++numOfPowers;
        delete[] powers;
        powers = tempPowers;
        calPowerlevel();
        return *this;
    }

    Hero& Hero::operator-=(int decrease) 
    {
        powersLevel -= decrease;
        return *this;
    }

    bool operator<(const Hero& hero1, const Hero& hero2) 
    {
        return hero1.powersLevel < hero2.powersLevel;
    }

    bool operator>(const Hero& hero1, const Hero& hero2) 
    {
        return hero1.powersLevel > hero2.powersLevel;
    }

    void operator>>(const Power& power, Hero& hero) 
    {
        hero += power;
    } 

   void operator<<(Hero& hero , const Power& power) 
    {
        hero += power;
    } 

}