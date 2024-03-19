
#ifndef  SENECA_CHEQUINGACCOUNT_H
#define  SENECA_CHEQUINGACCOUNT_H
#include <iostream>
#include "iAccount.h"
#include "Account.h"
namespace seneca {
	class ChequingAccount :public Account {
		double m_trans_fee;
		double m_month_fee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};

	
}
#endif
