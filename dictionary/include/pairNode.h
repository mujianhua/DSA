//
// Created by MJH on 2022/1/18.
//

#ifndef PAIRNODE_H_
#define PAIRNODE_H_

using namespace std;

template<class K, class E>
struct pairNode {
    typedef pair<const K, E> pairType;
    pairType element;
    pairNode<K, E> *next;

    pairNode(const pairType &thePair) : element(thePair) {}

    pairNode(const pairType &thePair, pairNode<K, E> *theNext) : element(thePair) { next = theNext; }
};

#endif //PAIRNODE_H_
