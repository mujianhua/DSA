//
// Created by MJH on 2022/1/18.
//

#ifndef CIRCULARLISTWITHHEADER_H_
#define CIRCULARLISTWITHHEADER_H_

#include<iostream>
#include<sstream>
#include<string>
#include "chainNode.h"
#include "myExceptions.h"

using namespace std;

template<class T>
class circularListWithHeader {
public:
    // constructor
    circularListWithHeader();

    // some methods
    int size() const { return listSize; }

    int indexOf(const T &theElement) const;

    void insert(int theIndex, const T &theElement);

    void output(ostream &out) const;

protected:
    void checkIndex(int theIndex) const;// throw illegalIndex if theIndex invalid
    chainNode<T> *headerNode;  // pointer to header node
    int listSize;              // number of elements in list
};

template<class T>
circularListWithHeader<T>::circularListWithHeader() {
    headerNode = new chainNode<T>();
    headerNode->next = headerNode;
    listSize = 0;
}

template<class T>
void circularListWithHeader<T>::checkIndex(int theIndex) const {
    // Verify that theIndex is between 0 and listSize - 1.
    if (theIndex < 0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template<class T>
int circularListWithHeader<T>::indexOf(const T &theElement) const {
    headerNode->element = theElement;
    chainNode<T> *currentNode = headerNode->next;
    int index = 0;
    while (currentNode->element != theElement) {
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == headerNode)
        return -1;
    else
        return index;
}

template<class T>
void circularListWithHeader<T>::insert(int theIndex, const T &theElement) {
    // invalid index
    if (theIndex < 0 || theIndex > listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    chainNode<T> *p = headerNode;
    for (int i = 0; i < theIndex; i++) {
        p = p->next;
    }
    p->next = new chainNode<T>(theElement, p->next);
    listSize++;
}

template<class T>
void circularListWithHeader<T>::output(ostream &out) const {
    for (chainNode<T> *currentNode = headerNode->next;
            currentNode != headerNode;
            currentNode = currentNode->next)
        out << currentNode->element << " ";
}

template<class T>
ostream &operator<<(ostream &out, const circularListWithHeader<T> &x){
    x.output(out);
    return out;
}

#endif //CIRCULARLISTWITHHEADER_H_
