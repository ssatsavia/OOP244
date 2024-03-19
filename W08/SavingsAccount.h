
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"
namespace seneca {
	class SavingsAccount : public Account {
	private:
		double m_interestRate;
	public:
		SavingsAccount(double, double);
		void  monthEnd();
		void  display(std::ostream&) const;
	};
}

#endif
