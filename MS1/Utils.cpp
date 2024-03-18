//
//  Utils.cpp
//  MS1
//
//  Created by Sage Satsavia on 2024-03-11.
//

/***********************************************************************
// OOP244 Project
//
// File  Utils.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <ctime>
#include "Utils.h"
using namespace std;
namespace seneca {
   // start provided code
   bool debug = false;
   Utils U;
   int Utils::getTime() {
      int mins = -1;
      if (debug) {
         int duration[]{ 3,5,9,20,30 };
         mins = (m_testMins %= 1440);
         m_testMins += duration[m_testIndex++ % 5];
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
   void Utils::setDebugTime(int hour, int min) {
      seneca::debug = true;
      m_testMins = hour * 60 + min;
   }
   
}

