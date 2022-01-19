//
// Created by mujianhua on 2022/1/19.
//
#include <iostream>
#include "arrayStack.h"

using namespace std;
//global variables

arrayStack<int> *track;
int numberOfCars;
int numberOfTracks;
int smallestCar;
int itsTrack;

void outputFromHoldingTrack() {
    track[itsTrack].pop();
    cout << "Move car " << smallestCar << " from holding track "
         << itsTrack << " to output track" << '\n';

    smallestCar = numberOfCars + 2;//question: + 2??
    for (int i = 1; i <= numberOfTracks; i++)
        if (!track[i].empty() && track[i].top() < smallestCar) {
            smallestCar = track[i].top();
            itsTrack = i;
        }
}

bool putInHoldingTrack(int c) {
    int bestTrack = 0,
            bestTop = numberOfCars + 1;
    //找出top()最小的track
    for (int i = 1; i <= numberOfTracks; i++)
        if (!track[i].empty()) {
            int topCar = track[i].top();
            if (c < topCar && topCar < bestTop) {
                bestTop = topCar;
                bestTrack = i;//................都找最好的一个车道
            }
        } else if (bestTrack == 0)bestTrack = i;
    if (bestTrack == 0)
        return false;
    track[bestTrack].push(c);
    cout << "Move car " << c << " from input track "
         << "to holding track " << bestTrack << '\n';
    if (c < smallestCar) {
        smallestCar = c;
        itsTrack = bestTrack;
    }
    return true;
}

bool railroad(int inputOrder[], int theNumberOfCars,
              int theNumberOfTracks) {
    numberOfCars = theNumberOfCars;
    numberOfTracks = theNumberOfTracks;
    track = new arrayStack<int>[numberOfTracks + 1];
    int nextCarToOutput = 1;
    smallestCar = numberOfCars + 1;

    for (int i = 1; i <= numberOfCars; i++) {
        if (inputOrder[i] == nextCarToOutput) {
            cout << "Move car " << inputOrder[i]
                 << " from input track to output track" << '\n';
            nextCarToOutput++;

            while (smallestCar == nextCarToOutput) {
                outputFromHoldingTrack();
                nextCarToOutput++;
            }
        } else if (!putInHoldingTrack(inputOrder[i]))
            return false;
    }
    return true;
}