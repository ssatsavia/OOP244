//
//  main.cpp
//  WORKSHSHOP1 PART2
//
//  Created by Himanshu Nayyar on 2024-01-22.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StMark.h"
#include "file.h"

using namespace std;
using namespace seneca;

int main()
{
    char fileNameEntered[20] = {""};
    bool exit = false;
    while (!exit)
    {
        cout << "Enter filename to generate report for or 'X' to exit:" << endl << "> ";
        cin >> fileNameEntered;

        if (strcmp(fileNameEntered, "X") == 0)
        {
            cout << "Exiting program!" << endl;
            exit = true;
        }
        else
        {
            if (!openFile(fileNameEntered))
                cout << "Cannot open \"" << fileNameEntered << "\"!" << endl;
            else
                printReport(fileNameEntered);
        }
    }
}
