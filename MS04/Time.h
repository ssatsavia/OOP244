

#ifndef SENECA_TIME_H
#define  SENECA_TIME_H
#include <iostream>
#include <ostream>
using namespace std;
namespace seneca {
	class Time {
		unsigned int m_min;
	public:
		Time& reset();
		Time(unsigned int min = 0u);
		void write(std::ostream& out) const;
		void read(std::istream& in);
		operator unsigned int()const;

		Time& operator*= (int val);
		Time& operator-= (const Time& D);
		Time operator-(const Time& T)const;

		friend std::ostream& operator<<(std::ostream& out, const Time& tm);
		friend std::istream& operator>>(std::istream& in, Time& tm);
	};
}

#endif
