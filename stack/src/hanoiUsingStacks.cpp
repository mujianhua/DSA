//
// Created by mujianhua on 2022/1/19.
// test
#include <iostream>
#include "arrayStack.h"

using namespace std;
arrayStack<int> tower[4];

void moveAndShow(int n, int x, int y, int z) {
    // Move the top n disks from tower x to tower y showing states.
    // Use tower z for intermediate storage.
    if (n > 0) {
        moveAndShow(n - 1, x, z, y);
        int d = tower[x].top();   // move a disk from top of
        tower[x].pop();           // tower x to top of
        tower[y].push(d);         // tower y
        // showState();              // show state of 3 towers
        // substitute showState code for test run
        cout << "Move disk " << d << " from tower "
             << x << " to top of tower " << y << endl;
        moveAndShow(n - 1, z, y, x);
    }
}

void towersOfHanoi(int n) {
    // Preprocessor for moveAndShow.
    for (int d = n; d > 0; d--) // initialize
        tower[1].push(d); // add disk d to tower 1
    // move n disks from tower 1 to 3 using 2 as
    // intermediate tower
    moveAndShow(n, 1, 2, 3);
    for (int m = n; m > 0; m--){
        int show = tower[2].top();
        cout << show << '\t';
        tower[2].pop();
    }
}


// Move the top n disks from tower x to tower y showing states.
// Use tower z for intermediate storage.

