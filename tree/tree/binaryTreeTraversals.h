//
// Created by MJH on 2022/1/14.
//

#include <iostream>
#include "arrayQueue.h"
#include "binaryTreeNode.h"
#include "myExceptions.h"

using namespace std;

template<class T>
void visit(binaryTreeNode<T> *x){
    cout << x->element << ' ';
}

template<class T>
void preOrder(binaryTreeNode<T> *t){
    if (t != nullptr){
        visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template<class T>
void inOrder(binaryTreeNode<T> *t){
    if (t != nullptr){
        inOrder(t->leftChild);
        visit(t);
        inOrder(t->leftChild);
    }
}

template<class T>
void postOrder(binaryTreeNode<T> *t){
    if (t!= nullptr){
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        visit(t);
    }
}

template<class T>
void levelOrder(binaryTreeNode<T> *t){
    arrayQueue<binaryTreeNode<T> *t> q;
    while (t != nullptr){
        visit(t);
        if (t->leftChild != nullptr)
            q.push(t->leftChild);
        if (t->rightChild != nullptr)
            q.push(t->rightChild);
        try {t = q.front();}
        catch (queueEmpty) {return;}
        q.pop();
    }
}