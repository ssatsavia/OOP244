//
//  EmailFile.cpp
//  oopw6
//
//  Created by Sage Satsavia on 2024-03-04.
//
/***********************************************************************
// OOP244 Workshop # 6
//
// File: EmailFile.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "EmailFile.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;
namespace seneca {
    Email::Email() {}

    Email::Email(const Email& other) {
        copyData(other);
    }

    Email& Email::operator=(const Email& rhs) {
        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }
        return *this;
    }

    bool Email::load(std::ifstream& in) {
        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }
        return result;
    }

    Email::~Email() {
        delete[] m_email;
        delete[] m_name;
    }

    void Email::copyData(const Email& other) {
        m_email = new char[strlen(other.m_email) + 1];
        strcpy(m_email, other.m_email);

        m_name = new char[strlen(other.m_name) + 1];
        strcpy(m_name, other.m_name);

        strcpy(m_year, other.m_year);
    }

    EmailFile::EmailFile() : m_emailLines(nullptr), m_filename(nullptr), m_noOfEmails(0) {}

    EmailFile::EmailFile(const EmailFile& other) : m_emailLines(nullptr), m_filename(nullptr), m_noOfEmails(0) {
        *this = other; // Utilize the assignment operator to perform deep copying
    }

    void EmailFile::setEmpty() {
        delete[] m_emailLines;
        m_emailLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    void EmailFile::setFilename(const char* filename) {
        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
        }
    }
    /*void EmailFile::setFilename(const char* filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }*/

    void EmailFile::loadEmails() {
        // Initial Check
        if (m_filename == nullptr)
            return;

        // Deleting previous data to prevent memory leaks
        delete[] m_emailLines;
        m_emailLines = nullptr;

        // Open the file for reading
        std::ifstream file(m_filename);
        if (!file.is_open()) {
            std::cout << "Failed to open file: " << m_filename << std::endl;
            return;
        }

        // Counting Emails
        int count = 0;
        std::string line;
        while (std::getline(file, line)) {
            ++count;
        }
        file.clear(); // Reset eof flag
        file.seekg(0, std::ios::beg); // Reset file position to the beginning

        // Dynamically allocate an array of Email objects
        m_noOfEmails = count;
        m_emailLines = new Email[m_noOfEmails];

        // Reading and processing each line as an Email object
        for (int i = 0; i < m_noOfEmails; ++i) {
            if (!m_emailLines[i].load(file)) {
                std::cout << "Error loading email at line " << i + 1 << std::endl;
                break;
            }
        }

        file.close();
    }

    bool EmailFile::setNoOfEmails() {
        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else {
            m_noOfEmails = 0;
            string line;
            while (getline(file, line)) {
                ++m_noOfEmails;
            }
            file.close();

            if (m_noOfEmails == 0) {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                isValid = true;
            }
        }
        return isValid;
    }


    EmailFile::EmailFile(const char* filename) {
        if (filename == nullptr) {
            setEmpty();
        }
        else {
            setFilename(filename);
            if (!setNoOfEmails()) {
                setEmpty();
            }
            else {
                m_emailLines = new Email[m_noOfEmails];
                loadEmails();
            }
        }
    }

    EmailFile& EmailFile::operator=(const EmailFile& other) {
        if (this != &other) {
            // Deep copy filename
            setFilename(other.m_filename);

            // Deep copy email lines
            delete[] m_emailLines;
            m_emailLines = new Email[other.m_noOfEmails];
            for (int i = 0; i < other.m_noOfEmails; ++i) {
                m_emailLines[i] = other.m_emailLines[i];
            }

            // Update number of emails
            m_noOfEmails = other.m_noOfEmails;
        }
        return *this;
    }

    EmailFile::~EmailFile() {
        delete[] m_emailLines;
        delete[] m_filename;
    }

    bool EmailFile::saveToFile(const char* filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error: Could not open file: " << filename << std::endl;
            return false;
        }
        for (int i = 0; i < m_noOfEmails; ++i) {
            file << m_emailLines[i].m_email << "," << m_emailLines[i].m_name << "," << m_emailLines[i].m_year << "\n";
        }
        file.close();
        if (!file.good()) {
            std::cerr << "Error: Could not save to file: " << filename << "." << std::endl;
            return false;
        }
        return true;
    }

    void EmailFile::fileCat(const EmailFile& obj, const char* name) {
        if (m_emailLines == nullptr || obj.m_emailLines == nullptr)
            return;

        int totalEmails = m_noOfEmails + obj.m_noOfEmails;
        Email* mergedEmails = new Email[totalEmails];

        for (int i = 0; i < m_noOfEmails; ++i) {
            mergedEmails[i] = m_emailLines[i];
        }

        for (int i = 0; i < obj.m_noOfEmails; ++i) {
            mergedEmails[m_noOfEmails + i] = obj.m_emailLines[i];
        }

        delete[] m_emailLines;
        m_emailLines = mergedEmails;
        m_noOfEmails = totalEmails;

        if (name != nullptr) {
            if (m_filename != nullptr) {
                delete[] m_filename;
            }
            m_filename = new char[strlen(name) + 1];
            strcpy(m_filename, name);
        }

        // After concatenating, save the result to a file if a name is provided.
        if (name != nullptr) {
            saveToFile(name); // This line saves the concatenated emails to a file.
        }
    }
    //void EmailFile::fileCat(const EmailFile& obj, const char* name) {
    //    if (m_emailLines == nullptr || obj.m_emailLines == nullptr)
    //        return;

    //    int totalEmails = m_noOfEmails + obj.m_noOfEmails;
    //    Email* mergedEmails = new Email[totalEmails];

    //    for (int i = 0; i < m_noOfEmails; ++i) {
    //        mergedEmails[i] = m_emailLines[i];
    //    }

    //    for (int i = 0; i < obj.m_noOfEmails; ++i) {
    //        mergedEmails[m_noOfEmails + i] = obj.m_emailLines[i];
    //    }

    //    delete[] m_emailLines;
    //    m_emailLines = mergedEmails;
    //    m_noOfEmails = totalEmails;

    //    if (name != nullptr) {
    //        // If m_filename is already set, delete the old memory.
    //        // setFilename will allocate new memory.
    //        if (m_filename != nullptr) {
    //            delete[] m_filename;
    //            m_filename = nullptr; // Prevent double-deletion in setFilename.
    //        }
    //        setFilename(name);
    //    }
    //
    //}

    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
    {
        return text.view(ostr);
    }
}
