//
//  SavingsAccount.cpp
//  OOPws7
//
//  Created by Sage Satsavia on 2024-03-12.
//

#include "SavingsAccount.h"
#include <iomanip>
#include <cstring>  
#include <limits>

namespace seneca {

void SavingsAccount::writeInterest(std::ostream& out) const {
    out << std::fixed << std::setprecision(3) << m_interest << "%";
    
}
   

SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate)
: BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}

void SavingsAccount::applyInterest(Date& dt) {
    double originalBalance = getBalance();
    double interestAmount = originalBalance * m_interest;
    double newBalance = originalBalance + interestAmount;
    setBalance(newBalance);
    Date originalDate = m_interestDate; // Store the original date
    m_interestDate = dt;
    std::cout << "   ";
    writeCurrency(std::cout, originalBalance);
    std::cout << " + ";
    writeCurrency(std::cout, interestAmount);
    std::cout << " (";
    writeInterest(std::cout);
    std::cout << ") = ";
    writeCurrency(std::cout, newBalance);
    std::cout << " | ";
    originalDate.write(std::cout); // Use the original date
    std::cout << " => ";
    m_interestDate.write(std::cout); // Use the new date
    std::cout << std::endl;
}







std::ostream& SavingsAccount::write(std::ostream& out) const {
    BankAccount::write(out);
    out << " | ";
    writeInterest(out);
    out << " | " << m_interestDate;
    return out;
}

std::istream& SavingsAccount::read(std::istream& in) {
    // Read the remaining details using the BankAccount's read function
    BankAccount::read(in);


    // Prompt the user to enter the interest date
    std::cout << "Interest Date ";
    in >> m_interestDate;
    
    // Prompt the user to enter the interest rate
    std::cout << "Interest Rate: ";
    in >> m_interest;

    return in;
}



std::istream& operator>>(std::istream& in, SavingsAccount& acct) {
    return acct.read(in);
}

std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
    return acct.write(out);
}
}
