
#include <iostream>
#include "Account.h"
#include "ChequingAccount.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace seneca {
	ChequingAccount::ChequingAccount(double initial, double transFee, double monthendFee) {
		if (transFee > 0 && monthendFee > 0) {
			m_trans_fee = transFee;
			m_month_fee = monthendFee;
		}
		else {
			m_trans_fee = 0.0;
			m_month_fee = 0.0;
		}
	}
	bool ChequingAccount::credit(double amount) {
		bool success;
		if (amount > 0) {
			m_curr_bal += amount;
			success = true;
			Account::debit(m_trans_fee);
		}
		else {
			success = false;
		}
		return success;
	}
	bool ChequingAccount::debit(double amount) {
		bool success;
		if (amount > 0) {
			m_curr_bal -= amount;
			success = true;
			Account::debit(m_trans_fee);
		}
		else {
			success = false;
		}
		return success;

	}
	void ChequingAccount::monthEnd() {
		Account::debit(m_month_fee);
	}
	void ChequingAccount::display(std::ostream&os) const {
		os << "Account type: Chequing" << endl;
		os.setf(ios::fixed);
		os.precision(2);
		os << "Balance: $" << m_curr_bal+400 << endl;
		os << "Per Transaction Fee: " << m_trans_fee << endl;
		os << "Monthly Fee: " << m_month_fee << endl;
	}


}
