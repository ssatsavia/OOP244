//
//  Menu.cpp
//  MS1
//
//  Created by Sage Satsavia on 2024-03-11.
//

#include "Menu.h"
#include <cstring> // For strlen
#include <iostream>

namespace seneca {
using namespace std;

Menu::Menu(const char* menuContent, int numberOfTabs) : m_numTabs(numberOfTabs) {
    // Dynamically allocate memory for menu content
    m_text = new char[strlen(menuContent) + 1];
    strcpy(const_cast<char*>(m_text), menuContent);
    
    // Count the number of options in the menu
    m_numOptions = 0;
    for (size_t i = 0; m_text[i] != '\0'; ++i) {
        if (m_text[i] == '\n') {
            ++m_numOptions;
        }
    }
    // Increment to count the last option after the last newline
    ++m_numOptions;
}

Menu::~Menu() {
    delete[] m_text; // Deallocate memory
}

void Menu::display() const {
    for (int m = 0; m < m_numTabs; ++m)
    {
        std::cout << "   ";
    }

    for (unsigned int i = 0; i < strlen(m_text); i++) {
        if (m_text[i] == '\n') {
            cout << '\n';
            for (int j = 0; j < m_numTabs; ++j) {
                std::cout << "   ";
            }
        }
        else {
            cout << m_text[i];
        }
    }

    cout << "\n";
    for (int k = 0; k < m_numTabs; ++k) {
        std::cout << "   ";

    }
    std::cout << "0- Exit\n";
    for (int l = 0; l < m_numTabs; ++l)
    {
        std::cout << "   ";
    }
    std::cout << "> ";




}



int& Menu::operator>>(int& selection) {
        display();
        bool validInput = false;
        while (!validInput) {
            cin >> selection;
            validInput = true; // Resetting the flag here

            if (cin.fail()) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                validInput = false; // Reset the flag on invalid input
            }
            else if (cin.peek() != '\n') {
                cout << "Only enter an integer, try again: ";
                cin.ignore(1000, '\n'); // Ignore the rest of the line
                validInput = false; // Reset the flag on invalid input
            }
            else if (selection < 0 || selection >= m_numOptions) {
                cout << "Invalid value enterd, retry[0 <= value <= " << m_numOptions - 1 << "]: ";
                validInput = false; // Reset the flag on invalid input
            }
        }

        return selection;
    }
}
