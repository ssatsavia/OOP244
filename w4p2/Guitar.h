//
//  Guitar.h
//  WORKSHOP4 PART 2
//
//  Created by Sage Satsavia on 2024-02-12.
//

/***********************************************************************
// OOP244 Workshop #4 p2: tester program
// File  main.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                              Date                  Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
namespace seneca{

  const int MAT_LEN = 10;

   class GuitarStr
   {
      char m_material[MAT_LEN];
      double m_gauge;

   public:
      GuitarStr();
      GuitarStr(const char* ma, double ga);
      const char* material()const;
      double gauge()const;
   };
   
   class Guitar
   {
      GuitarStr* m_strings;
      int m_numStrings;
      char m_model[16];

   public:
      Guitar(const char* mod = "Stratocaster");
      Guitar(GuitarStr strs[], int ns, const char* mod);
      ~Guitar();
      bool changeString(const GuitarStr& gs, int sn);
      void reString(GuitarStr strs[], int ns);
      void deString();
      bool strung() const;
      bool matchGauge(double ga) const;
      std::ostream& display(ostream& os = cout) const;
   };
}

#endif
