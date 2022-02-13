//
// Created by mujianhua on 2022/1/19.
//
#include <iostream>
#include <string>
#include "arrayStack.h"

using namespace std;

void printMatchedPairs(string expr) {
    arrayStack<int> s(10);
    int length = (int) expr.size();
    for (int i = 0; i < length; i++) {
        if (expr.at(i) == '(')
            s.push(i);
        else if (expr.at(i) == ')')
            try {
                cout << s.top() << '\t' << i << '\n';
                s.pop();
            }
            catch (stackEmpty) {
                // stack was empty, no match exists
                cout << "No match for right parenthesis"
                     << " at " << i << endl;
            }
    }
    while (!s.empty()) {
        cout << "No match for left parenthesis at "
             << s.top() << endl;
        s.pop();
    }
}

