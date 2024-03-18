//
//  BankAccount.cpp
//  OOPws7
//
//  Created by Sage Satsavia on 2024-03-12.
//

#include "BankAccount.h"
#include <iomanip>
#include <cstring>  
#include <limits>

namespace seneca {

    double BankAccount::getBalance() const {
        return m_balance;
    }

    void BankAccount::setBalance(double balance) {
        m_balance = balance;
    }

    void BankAccount::writeCurrency(std::ostream& out, double amount) const {
        out << "$" << std::fixed << std::setprecision(2) << amount;
    }

    BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
        : m_openDate(openDate), m_depInfo(depInfo), m_balance(balance) {
        strncpy(m_name, name, sizeof(m_name));
        m_name[sizeof(m_name) - 1] = '\0';
    }

std::ostream& BankAccount::write(std::ostream& out) const {
    out << ">> " << m_name << " | ";
    writeCurrency(out, m_balance);
    out << " | " << m_openDate << " | " << m_depInfo.m_transit << ","
    << std::setw(3) << std::setfill('0') << m_depInfo.m_institution << ","
    << std::setw(7) << std::setfill('0') << m_depInfo.m_account;
    return out;
}


std::istream& BankAccount::read(std::istream& in) {
    
    std::cout << "Name: ";
    in.getline(m_name, sizeof(m_name));
    
    static int count = 0; 
        count++;

        // Check if it's the fourth bank account
    if (count != 1 && count == 2) {
            // Prompt the user to enter the name
            //std::cout << "Name: ";
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //in.getline(m_name, sizeof(m_name));
        }
   
        // Read the opening balance
        std::cout << "Opening Balance: ";
        in >> m_balance;

    // Read the date
    std::cout << "Date Opened ";
    in >> m_openDate;

    // Read the deposit info
    std::cout << "Transit #: ";
    in >> m_depInfo.m_transit;
    std::cout << "Institution #: ";
    in >> m_depInfo.m_institution;
    std::cout << "Account #: ";
    in >> m_depInfo.m_account;

    return in;
}


    std::istream& operator>>(std::istream& in, BankAccount& acct) {
        return acct.read(in);
    }

    std::ostream& operator<<(std::ostream& out, const BankAccount& acct) {
        return acct.write(out);
    }

}// namespace seneca
