#include <iostream>
#include <string>
#include "arrayStack.h"

using namespace std;
//1.pairs
//void printMatchedPairs(string expr);
//2.hanoi
//void moveAndShow(int, int, int, int);
//void towersOfHanoi(int);
void outputFromHoldingTrack();
bool putInHoldingTrack(int c);
bool railroad(int inputOrder[], int theNumberOfCars,
              int theNumberOfTracks);

int main(void) {
    int p[] = {0, 3, 6, 9, 2, 4, 7, 1, 8, 5};
    railroad(p, 9, 3);
    return 0;
}
