//
// Created by MJH on 2022/1/18.
//

#ifndef SORTEDCHAIN_H_
#define SORTEDCHAIN_H_

#include <iostream>
#include "dictionary.h"
#include "pairNode.h"

using namespace std;

template<class K, class E>
class sortedChain : public dictionary<K, E> {
protected:
    pairNode<K, E> *firstNode;
    int dSize;
public:
    sortedChain() {
        firstNode = NULL;
        dSize = 0;
    }

    ~sortedChain();

    bool empty() const { return dSize == 0; }

    int size() const { return dSize; }

    pair<const K, E> *find(const K &) const;

    void erase(const K &);

    void insert(const pair<const K, E> &);

    void output(ostream &out) const;
};

template<class K, class E>
sortedChain<K, E>::~sortedChain() {
    while (firstNode != nullptr) {
        pairNode<K, E> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class K, class E>
pair<const K, E> *sortedChain<K, E>::find(const K &theKey) const {
    pairNode<K, E> *currentNode = firstNode;
    while (currentNode != nullptr && currentNode->element.first != theKey)
        currentNode = currentNode->next;
    if (currentNode != nullptr && currentNode->element.first == theKey)
        return &currentNode->element;
    return nullptr;
}

template<class K, class E>
void sortedChain<K, E>::insert(const pair<const K, E> &thePair) {
    pairNode<K, E> *p = firstNode, *tp = nullptr;
    while (p != nullptr && p->element.first < thePair.first) {
        tp = p;
        p = p->next;
    }

    if (p != nullptr && p->element.first == thePair.first) {
        p->element.second = thePair.second;
        return;
    }

    pairNode<K, E> *newNode = new pairNode<thePair, p>;
    if (tp == nullptr)
        firstNode = newNode;
    else
        tp->next = newNode;
}

template<class K, class E>
void sortedChain<K, E>::erase(const K &theKey) {
    pairNode<K, E> *p = firstNode,
            *tp = NULL;
    while (p != NULL && p->element.first < theKey) {
        tp = p;
        p = p->next;
    }
    if (p != NULL && p->element.first == theKey) {
        if (tp == NULL) firstNode = p->next;
        else tp->next = p->next;
        delete p;
        dSize--;
    }
}

template<class K, class E>
void sortedChain<K, E>::output(ostream &out) const {
    for (pairNode<K, E> *currentNode = firstNode;
         currentNode != NULL;
         currentNode = currentNode->next)
        out << currentNode->element.first << " "
            << currentNode->element.second << "  ";
}

// overload <<
template<class K, class E>
ostream &operator<<(ostream &out, const sortedChain<K, E> &x) {
    x.output(out);
    return out;
}


#endif //SORTEDCHAIN_H_
