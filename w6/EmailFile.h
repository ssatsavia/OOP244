//
//  EmailFile.h
//  oopw6
//
//  Created by Sage Satsavia on 2024-03-04.
//
/***********************************************************************
// OOP244 Workshop # 6
//
// File:    EmailFile.h
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>
const int BUFFER_SIZE = 1024;

namespace seneca {

    class Email {
    private:
        char* m_email{ nullptr };
        char* m_name{ nullptr };
        char m_year[5]{ '\0' };

        void copyData(const Email& other);

    public:
        Email();
        Email(const Email& other);
        Email& operator=(const Email& other);
        bool load(std::ifstream& in);
        ~Email();

        friend class EmailFile;
    };

    class EmailFile {
    private:
        Email* m_emailLines{ nullptr };
        char* m_filename{ nullptr };
        int m_noOfEmails{ 0 };

        void setEmpty();
        void setFilename(const char* filename);
        bool setNoOfEmails();
        void loadEmails();

    public:
        EmailFile();
        EmailFile(const char* filename);
        EmailFile(const EmailFile& other);
        EmailFile& operator=(const EmailFile& other);
        ~EmailFile();

        bool saveToFile(const char* filename) const;
        void fileCat(const EmailFile& obj, const char* name = nullptr);

        std::ostream& view(std::ostream& ostr)const;

        friend std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);
    };
}
#endif 

