

#ifndef PATIENT_H
#define PATIENT_H
#include "Ticket.h"
#include "IOAble.h"

#include <iostream>
namespace seneca {

	class Patient :public IOAble
	{
		char* m_name;
		int m_OhipNo;
		Ticket m_ticket;
	public:
		Patient(int ticketNo);
		Patient(const Patient& other);
		virtual ~Patient();

		virtual char type()const = 0;
		bool operator==(const char ch)const;
		bool operator==(const Patient& arg)const;


		Time time() const;
		const char* getName() const;
		void setName(const char* newName);
		bool setOHIP(int newOHIP);

		Patient& operator=(const Patient& other);
		operator const char* () const;
		operator bool() const;
		int number()const;
		void setArrivalTime();

		std::ostream& write(std::ostream& os) const override;
		std::istream& read(std::istream& is) override;
	};


}
#endif // !PATIENT_
