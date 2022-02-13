//
// Created by mujianhua on 2022/1/20.
//
#include <iostream>
#include "arrayStack.h"

bool checkBox(int net[], int n) {
    arrayStack<int> *s = new arrayStack<int>(n);
    for (int i = 0; i < n; i++) {
        if (!s->empty())
            if (net[i] == net[s->top()])//.................
                s->pop();
            else s->push(i);
        else s->push(i);
    }
    if (s->empty()){
        std::cout << "Switch box is routable" << '\n';
        return true;
    }
    std::cout << "Switch box is not routable" << '\n';
    return false;
}
