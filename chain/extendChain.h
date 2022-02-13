//
// Created by MJH on 2022/1/14.
//

#ifndef EXTENDCHAIN_H_
#define EXTENDCHAIN_H_

#include <iostream>
#include <sstream>
#include <string>
#include "extendLinearList.h"
#include "chain.h"
#include "myExceptions.h"

using namespace std;

template<class T>
class extendChain : public extendLinearList<T>, public chain<T> {
public:
    extendChain(int initialCapacity = 10) : chain<T>(initialCapacity) {}

    extendChain(const extendChain<T> &c) : chain<T>(c) {}

    bool empty() const { return listSize == 0; }//todo:能否访问protected?
    int size() const { return listSize; }

    T &get(int theIndex) const { return chain<T>::get(theIndex); }
    int indexOf(const T &theElement) const { return chain<T>::indexOf(theElement); }
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void clear(){
        while (firstNode != nullptr){
            chainNode<T> *nextNode = firstNode;
            delete firstNode;
            firstNode = nextNode;
        }
    }


protected:
    chainNode<T> *lastNode;
};

#endif //EXTENDCHAIN_H_
