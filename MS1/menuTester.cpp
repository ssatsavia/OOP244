/***********************************************************************
// OOP244 Project ms1
//
// File  menuTester.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include "Menu.h"

using namespace seneca;
using namespace std;
int main() {
   Menu m("Tester Options menu:\n1- Option one\n2- Option two");
   int selection;
   cout << "Enter the following values:\nabc\n1 (with a space after 1)\n1\n0\n2\n3\n-1\n0\n----------------------------\n";
   while (m >> selection) {
      switch (selection) {
      case 1: {
         Menu sub_menu("Sub-menu of option one!\n1- sub one\n2- sub two\n3- sub two\n4- sub two", 1);
         switch (sub_menu >> selection) {
         case 1:
            cout << "   sub menu one selected" << endl << endl;
            break;
         case 2:
            cout << "   sub menu two selected" << endl << endl;
            break;
         case 0:
            cout << "   sub menu exit selected" << endl << endl;
            break;
         }
         break;
      }
      case 2:
         cout << "option two selected" << endl << endl;
         break;
      default:
         cout << "This will never happen!!!!" << endl;
         break;
      }
   }
   cout << "goodbye!" << endl;
   return 0;
}