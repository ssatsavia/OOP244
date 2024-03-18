

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "StMark.h"
#include "file.h"
#include "graph.h"

using namespace std;
namespace seneca
{
    /// <summary>
    /// Tries to open the students' mark data file.
    /// If successful it will print a report based on the
    /// date in the file.
    /// </summary>
    /// <param name="filename">, holds the data file name</param>
    /// <returns>True if the date files is opened succesfully,
    /// otherwise returns false</returns>
    ///
    bool printReport(const char* filename)
    {
        int markCounts[10] = { 0 }; // Hold data in different ranges
        struct StMark mark[MAX_NO_RECS]; // To hold records
        int numRecords = readMarks(mark); //Calculate number of records


        if (!openFile(filename)) {
            return false;
        }

        // Bubble sort
        bubbleSort(mark, numRecords);

        for (int i = 0; i < numRecords; ++i) {
            int group = mark[i].mark / 10;
            if (group == 10) group = 9; // for marks 100
            markCounts[group]++;
        }

        // Print the graph
        printGraph(markCounts, 10, "Students' mark distribution");

        // Print the sorted records
        for (int i = 0; i < numRecords; ++i) {
            cout << setw(3) << (i + 1) << " : [" << setw(3) << mark[i].mark << "] " << mark[i].name << " " << mark[i].surname << "\n";
        }

        closeFile();
        return true;
    }

    void bubbleSort(StMark* studentArray, int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (studentArray[j].mark < studentArray[j + 1].mark) {
                    // Swap studentArray[j] and studentArray[j + 1]
                    StMark temp = studentArray[j];
                    studentArray[j] = studentArray[j + 1];
                    studentArray[j + 1] = temp;
                }
            }
        }
    }

}
