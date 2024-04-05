

#define _CRT_SECURE_NO_WARNINGS
#include <cstring> 
#include <iomanip>
#include "Patient.h"
#include "Ticket.h"
#include "Time.h"
#include "IOAble.h"
using namespace std;
namespace seneca {
	Patient::Patient(int ticketNo) :m_ticket(ticketNo) {
		m_name = nullptr;
		m_OhipNo = 0;


	}

	Patient:: ~Patient() {
		delete[] m_name;
	}

	Patient::Patient(const Patient& other) :m_ticket(other.m_ticket) {
		m_name = nullptr;
		*this = other;

	}

	Patient& Patient:: operator=(const Patient& other) {
		if (this != &other) {
			delete[] m_name;
			if (other.m_name) {
				m_name = new char[strlen(other.m_name) + 1];
				strcpy(m_name, other.m_name);

			}
			else {
				m_name = nullptr;
			}

			m_OhipNo = other.m_OhipNo;
			m_ticket = other.m_ticket;
		}
		return *this;
	}

	bool Patient:: operator==(char type) const {
		if (this->type() == type) {
			return true;

		}
		else {
			return false;
		}
	}

	bool Patient:: operator==(const Patient& other) const {
		if (type() == other.type()) {
			return true;
		}
		else {
			return false;
		}
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Time Patient::time() const {
		return m_ticket.time();
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	Patient::operator bool() const {
		if (m_name == nullptr) {
			return false;
		}
		else {
			return true;
		}
	}

	Patient::operator const char* () const {
		return getName();
	}

	std::ostream& Patient::write(std::ostream& os) const {


		if (&os == &std::clog) {
			if (!*this) {
				os << "Invalid Patient Record";
			}
			else {
				os << std::left << std::setw(53) << std::setfill('.') << m_name
					<< std::setw(0) << m_OhipNo << " ";
				os << std::right << std::setw(4) << std::setfill(' ') << m_ticket.number()
					<< " " << m_ticket.time();
			}
		}
		else if (&os == &cout) {
			if (!*this) {
				os << "Invalid Patient Record\n";

			}
			else {
				os << m_ticket << "\n";
				os << m_name << ", OHIP: " << m_OhipNo << "\n";
			}

		}
		else {
			if (!*this) {
				os << "Invalid Patient Record";
			}
			else {
				os << type() << "," << m_name << "," << m_OhipNo << ",";
				m_ticket.write(os);
			}


		}
		return os;
	}

	std::istream& Patient::read(std::istream& is) {
		if (&is == &std::cin) {
			char buffer[51];
			cout << "Name: ";
			is.get(buffer, 51, '\n');
			is.ignore(1000, '\n');

			delete[] m_name;
			m_name = new char[strlen(buffer) + 1];
			strcpy(m_name, buffer);

			cout << "OHIP: ";
			is >> m_OhipNo;
			while (is.fail() || !setOHIP(m_OhipNo))
			{
				if (is.fail())
				{

					cout << "Bad integer value, try again: ";
					is.clear();
					is.ignore(1000, '\n');

				}
				is.clear();
				is.ignore(1000, '\n');
				cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
				is >> m_OhipNo;
			}
			is.ignore(1000, '\n');

		}
		else {
			char buffer[51];
			is.get(buffer, 51, ',');
			is.ignore(1000, ',');
			delete[] m_name;

			m_name = new char[strlen(buffer) + 1];
			strcpy(m_name, buffer);


			is >> m_OhipNo;
			is.ignore(1000, ',');
			m_ticket.read(is);
		}
		return is;

	}

	const char* Patient::getName() const {
		return m_name;
	}

	void Patient::setName(const char* newName) {

		strcpy(m_name, newName);
	}

	bool Patient::setOHIP(int newOHIP) {
		return(newOHIP >= 100000000 && newOHIP <= 999999999);
	}

}
