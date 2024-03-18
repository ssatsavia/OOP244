

#ifndef SENECA_IO_H // replace with relevant names
#define SENECA_IO_H
#include <iostream>
namespace seneca{
using namespace std;

void printInt(int value, int fieldWidth);

int intDigits(int value);

int getInt(int min, int max);

void goBack(int n);

int menu(int noOfSamples);


void labelLine(int n, const char* label);

void line(int n);

}
#endif

