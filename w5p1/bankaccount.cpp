//
//  bankaccount.cpp
//  w5p1
//
//  Created by Sage Satsavia on 2024-02-17.
//

/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
// In bankaccount.cpp
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

namespace seneca
{
    bankAccount::bankAccount(const char* name, bool checking)
    {
        m_userName[0] = '\0';
        setup(name, checking);
    }
    bool bankAccount::setup(const char* name, bool checking)
    {
        if (isOpen())
            return false;
        if (name == nullptr)
            return false;

        strcpy(m_userName, name);
        m_monthlyTransactions = 0;
        m_checking = checking;
        m_funds = 0;
        return true;
    }

    bool bankAccount::isOpen() const
    {
        return (m_userName[0] != '\0');
    }

    const double TRANSACTION_CHECKING_FEE = 1.25;
    const double TRANSACTION_SAVINGS_FEE = 3.50;
    const double CHECKING_INTEREST_RATE = 0.005;
    const double SAVINGS_INTEREST_RATE = 0.025;

    bankAccount::operator bool() const
    {
        return isOpen();
    }

    bankAccount::operator double() const
    {
        return m_funds;
    }

    bankAccount& bankAccount::operator++()
    {
        if (isOpen() && m_funds > 0)
        {
            double total_Interest = m_checking ? m_funds * CHECKING_INTEREST_RATE : m_funds * SAVINGS_INTEREST_RATE;
            m_funds += total_Interest;
        }
        return *this;
    }

    bankAccount& bankAccount::operator--()
    {
        if (isOpen())
        {
            double traFee = m_checking ? m_monthlyTransactions * TRANSACTION_CHECKING_FEE : m_monthlyTransactions * TRANSACTION_SAVINGS_FEE;
            m_funds -= traFee;
        }
        return *this;
    }

    bool bankAccount::operator+=(double value)
    {
        if (isOpen())
        {
            m_funds += value;
            m_monthlyTransactions++;
            char valueStr[20];
            sprintf(valueStr, "%.2f", value);

            string output = "Deposit $" + std::string(valueStr) + " for " + m_userName;

            cout << output << std::endl;
            return true;
        }
        return false;
    }

    bool bankAccount::operator-=(double value)
    {
        m_funds -= value;
        m_monthlyTransactions++;
        char valueStr[20];
        sprintf(valueStr, "%.2f", value);

        string output = "Withdraw $" + std::string(valueStr) + " for " + m_userName;

        cout << output << std::endl;
        return true;
    }


    bool bankAccount::operator==(const bankAccount& Other) const
    {
        if (isOpen() && Other.isOpen())
        {
            return strcmp(m_userName, Other.m_userName) == 0 && m_checking == Other.m_checking && fabs(m_funds - Other.m_funds) < 0.001;
        }
        else
        {
            return false;
        }
    }
    bool bankAccount::operator>(double value) const
    {
        return isOpen() && m_funds > value;
    }

    bool bankAccount::operator<=(double Values) const
    {
        return !operator>(Values);
    }

    bool bankAccount::operator<<(bankAccount& other)
    {
        if (isOpen() && other.isOpen() && other.m_funds > 0)
        {
            double totTransferAmt = other.m_funds;
            char transferAmtStr[20];
            sprintf(transferAmtStr, "%.2f", totTransferAmt);

            string output = "Transfer $" + std::string(transferAmtStr) + " from " + other.m_userName + " to " + m_userName;

            cout << output << std::endl;

            *this += other.m_funds;
            other -= other.m_funds;
            return true;
        }
        return false;
    }

    void bankAccount::display() const
    {
        if (isOpen())
        {
            int lengthName = 15;
            int totalHyphens = lengthName - std::strlen(m_userName) + 1;
            std::string hyphens(totalHyphens, '-');

            char savingBalance[20];
            std::sprintf(savingBalance, "%8.2f", m_funds);

            char transactions[4];
            std::sprintf(transactions, "%03d", m_monthlyTransactions);

            std::string output = "Display Account -> User:" + hyphens + m_userName + " | " + (m_checking ? "Checking" : " Savings") + " | Balance: $" + std::string(savingBalance) + " | Transactions:" + std::string(transactions);

            std::cout << output << std::endl;
        }
        else
        {
            cout << "Display Account -> User:------- NOT OPEN" << endl;
        }
    }
    bool operator>(double lhs, const bankAccount& rhs)
    {
        return rhs.isOpen() && lhs > (double)rhs;
    }

    bool operator<=(double lhs, const bankAccount& rhs)
    {
        if (lhs > rhs) {
            return false;
        }
        else
        {
            return true;
        }

    }

}
