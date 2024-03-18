//
//  BankAccount.hpp
//  OOPws7
//
//  Created by Sage Satsavia on 2024-03-12.
//

#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

#include <iostream>
#include "DepositUtility.h"

namespace seneca {

class BankAccount {
    private:
        char m_name[51];
        Date m_openDate;
        DepositInfo m_depInfo;
        double m_balance;

    protected:
        double getBalance() const;
        void setBalance(double balance);
        void writeCurrency(std::ostream& out, double amount) const;

    public:
        BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
        std::ostream& write(std::ostream& out) const;
        std::istream& read(std::istream& in);
        friend std::istream& operator>>(std::istream& in, BankAccount& acct);
        friend std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
    
    };


} // namespace seneca

#endif // BANKACCOUNT_H
