#ifndef SENECA_Menu_H
#define SENECA_Menu_H

#include <iostream>

namespace seneca {

class Menu {
private:
    const char* m_text; // Pointer to hold the content of the menu
    int m_numOptions;   // Number of options in the menu
    int m_numTabs;      // Number of indentation tabs

public:
    Menu(const char* menuContent, int numberOfTabs = 0);
    ~Menu();

    // Disable copy and assignment
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;

    void display() const;

    int& operator>>(int& selection); // Updated declaration
};

}

#endif /* Menu_h */
