//
// Created by MJH on 2022/1/13.
//

#ifndef VECTORLIST_H_
#define VECTORLIST_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "linearList.h"
#include "myExceptions.h"

using namespace std;

template<class T>
class vectorList : public linearList<T>{
protected:
    void checkIndex(int theIndex) const;
    vector<T>* element;
public:
};

#endif //VECTORLIST_H_
