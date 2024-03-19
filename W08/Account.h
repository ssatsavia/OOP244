
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include <iostream>
#include "iAccount.h"
namespace seneca {
	class Account :public iAccount {
	public:
		Account();
		Account(double);
		bool credit(double);
		bool debit(double);
		
	protected:
		double balance() const;
		double m_curr_bal;
	};
}

#endif
