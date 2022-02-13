//
// Created by MJH on 2022/1/14.
//

#ifndef EXTENDLINEARLIST_H_
#define EXTENDLINEARLIST_H_

#include <iostream>
#include "linearList.h"

using namespace std;

template<class T>
class extendLinearList : linearList<T>{
public:
    virtual ~extendLinearList() {}
    virtual void clear() = 0;
    virtual void push_back(const T &theElement) = 0;
};

#endif //EXTENDLINEARLIST_H_
