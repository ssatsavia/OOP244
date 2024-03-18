//
//  bankaccount.h
//  w5p1
//
//  Created by Sage Satsavia on 2024-02-17.
//

/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_



namespace seneca
{
    const int     ACCT_MAXLEN_USER = 16;
    class bankAccount
    {

    private:
        char    m_userName[ACCT_MAXLEN_USER];
        double    m_funds;
        bool    m_checking;
        int        m_monthlyTransactions;


    public:
        bankAccount(const char* name = nullptr, bool checking = false);
        bool isOpen() const;
        bool setup(const char* name, bool checking);
        operator bool() const;
        operator double() const;
        bankAccount& operator++();
        bankAccount& operator--();

        bool operator+= (double value);
        bool operator-= (double value);
        bool operator== (const bankAccount& other) const;
        bool operator> (double value) const;
        bool operator<= (double value) const;

        bool operator<<(bankAccount& other);
        void display() const;
    };
    bool operator> (double lhs, const bankAccount& rhs);
    bool operator<= (double lhs, const bankAccount& rhs);
}
#endif

