//
// Created by MJH on 2022/1/14.
//

#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

using namespace std;

template<class T>
struct binaryTreeNode {
    T element;
    binaryTreeNode<T> *leftChild, *rightChild;

    binaryTreeNode() { leftChild = rightChild = nullptr; }

    binaryTreeNode(const T &theElement) : element(theElement) {
        leftChild = rightChild = nullptr;
    }

    binaryTreeNode(const T& theElement, binaryTreeNode *theLeftChild,
                   binaryTreeNode *theRightChild):element(theElement){
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};

#endif //BINARYTREENODE_H_
