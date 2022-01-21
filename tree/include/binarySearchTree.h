//
// Created by mujianhua on 2022/1/20.
//
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "bsTree.h"
#include "linkedBinaryTree.h"

using namespace std;

template<class K, class E>
class binarySearchTree : public bsTree<K, E>,
                         public linkedBinaryTree<pair<const K, E>> {
public:
    // method of dictionary
    bool empty() const { return treeSize == 0; }

    int size() const { return treeSize; }

    pair<const K, E> *find(const K &theKey) const;

    void insert(const pair<const K, E> &thePair);

    void erase(const K &theKey);

    // additional method of bsTree
    void ascend() {inOrderOutput();}
};

template<class K, class E>
pair<const K, E> *binarySearchTree<K, E>::find(const K &theKey) const {
    binarySearchTree<pair<const K, E>> *p = root;

}

#endif

