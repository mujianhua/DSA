#include <iostream>
#include <string>
#include "arrayStack.h"

using namespace std;
//1.pairs
//void printMatchedPairs(string expr);
//2.hanoi
//void moveAndShow(int, int, int, int);
//void towersOfHanoi(int);
//3.train and track
//void outputFromHoldingTrack();
//bool putInHoldingTrack(int c);
//bool railroad(int inputOrder[], int theNumberOfCars,
//              int theNumberOfTracks);
//4.Box
bool checkBox(int net[], int n);
int main(void) {
    int p[] = {1, 2, 2, 1, 3, 3, 4, 4};
    checkBox(p, 8);
    return 0;
}

