


#ifndef SENECA_GRAPH_H // replace with relevant names
#define SENECA_GRAPH_H
#include <iostream>
namespace seneca{


const int MAX_NO_OF_SAMPLES = 20;
const int GRAPH_WIDTH = 65;
void getSamples(int samples[], int noOfSamples);

int findMax(int samples[], int noOfSamples);

void printBar(int val, int max);

void printGraph(int samples[], int noOfSamples, const char* label);

}
#endif





