//
// Created by MJH on 2022/1/13.
//

#ifndef CHANGELENGTH1D_H_
#define CHANGELENGTH1D_H_

#include <string>
#include <algorithm>
#include "myExceptions.h"

using namespace std;

template<class T>
void changeLength1D(T *&a, int oldLength, int newLength) {
    if (newLength < 0)
        throw illegalParameterValue("the length must be >= 0");
    T *temp = new T[newLength];
    int number = min(oldLength, newLength);  //需要复制的元素个数
    //将a指向的数组中的number个元素复制到temp指向的数组中
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

#endif //CHANGELING1D_H_
