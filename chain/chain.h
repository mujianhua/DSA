//
// Created by MJH on 2022/1/13.
//

#ifndef CHAIN_H_
#define CHAIN_H_

#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include "linearList.h"
#include "chainNode.h"
#include "myExceptions.h"

using namespace std;

template<class T>
class chain : public linearList<T> {
public:
    chain(int initialCapacity = 10);

    chain(const chain<T> &);

    ~chain();

    //methods
    bool empty() const { return listSize == 0; }

    int size() const { return listSize; }

    T &get(int theIndex) const;

    int indexOf(const T &theElement) const;

    void erase(int theIndex);

    void insert(int theIndex, const T &theElement);

    void output(ostream &out) const;

    class iterator;

    iterator begin() { return iterator(firstNode); }

    iterator end() { return iterator(nullptr); }

    class iterator {
    protected:
        chainNode<T> *node;
    public:
        typedef forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference;
        typedef T *pointer;
        typedef T &reference;

        iterator(chainNode<T> *theNode = nullptr) { node = theNode; }

        T &operator*() const { return node->element; }

        T *operator->() const { return &node->element; }

        iterator &operator++() {
            node = node->next;
            return *this;
        }

        iterator operator++(int n) {
            iterator old = *this;
            node = node->next;
            return old;
        }

        bool operator!=(const iterator right) const { return node != right.node; }

        bool operator==(const iterator right) const { return node == right.node; }
    };
protected:
    void checkIndex(int theIndex) const;

    chainNode<T> *firstNode;
    int listSize;
};


template<class T>
chain<T>::chain(int initialCapacity) {
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << "must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = nullptr;
    listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T> &theList) {
    listSize = theList.listSize;
    if (listSize == 0) {
        firstNode = nullptr;
        return;
    }
    chainNode<T> *sourceNode = theList.firstNode;
    //复制链表theList的首元素
    firstNode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    chainNode<T> *targetNode = firstNode;
    while (sourceNode != nullptr) {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = nullptr;
}

template<class T>
chain<T>::~chain<T>() {
    while (firstNode != nullptr) {
        chainNode<T> *nextNode = firstNode;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
void chain<T>::checkIndex(int theIndex) const {// Verify that theIndex is between 0 and listSize - 1.
    if (theIndex < 0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template<class T>
T &chain<T>::get(int theIndex) const {
    checkIndex(theIndex);
    chainNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;
    return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T &theElement) const {
    chainNode<T> *currentNode = firstNode;
    int index = 0;
    while (currentNode != nullptr && currentNode->element != theElement) {
        index++;
        currentNode = currentNode->next;
    }
    if (currentNode == nullptr)
        return -1;
    else
        return index;
}

template<class T>
void chain<T>::erase(int theIndex) {
    checkIndex(theIndex);
    chainNode<T> *deleteNode;
    if (theIndex == 0) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;
        deleteNode = p->next;
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
    if (theIndex == 0)
        firstNode = new chainNode<T>(theElement, firstNode);
    else {
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

template<class T>
void chain<T>::output(ostream &out) const {
    for (chainNode<T> *currentNode = firstNode;
         currentNode != nullptr; currentNode = currentNode->next)
        out << currentNode->element;
}

template<class T>
ostream &operator<<(ostream &out, const chain<T> &x) {
    x.output(out);
    return out;
}

#endif //CHAIN_H_
