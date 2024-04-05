
#define _CRT_SECURE_NO_WARNINGS 
#include "Time.h"
#include "Utils.h"
namespace seneca {
	Time& Time::reset() {

		m_min = U.getTime();
		return *this;

	}

	Time::Time(unsigned int min) {
		m_min = min;

	}

	void Time::write(std::ostream& out) const {
		unsigned int hours = m_min / 60;
		unsigned int mins = m_min % 60;
		out.width(2);
		out.fill('0');

		out << hours << ":"; 
		out.width(2);
		out << mins;
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
			m_min = hours * 60 + mins;
		}


	}

	Time::operator unsigned int()const {
		return m_min;
	}

	Time& Time:: operator*= (int val) {
		m_min *= val;
		return *this;
	}

	Time& Time:: operator-= (const Time& D) {
		int difference = m_min - D.m_min;
		if (difference < 0) {
			m_min = (difference + 1440) % 1440;
		}
		else {
			m_min = difference;
		}
		return *this;
	}

	Time Time::operator-(const Time& T)const { 
		Time tmp = *this;
		tmp -= T;
		return tmp;
	}


	std::ostream& operator<<(std::ostream& out, const Time& tm) {
		tm.write(out);
		return out;

	}

	std::istream& operator>>(std::istream& in, Time& tm) {
		tm.read(in);
		return in;

	}


}
