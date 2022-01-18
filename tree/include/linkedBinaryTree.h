//
// Created by MJH on 2022/1/14.
//

#ifndef LINKEDBINARYTREE_H_
#define LINKEDBINARYTREE_H_

using namespace std;

#include <iostream>
#include "binaryTree.h"
#include "arrayQueue.h"
#include "binaryTreeNode.h"
#include "myExceptions.h"
//#include "booster.h"

template<class E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E>> {
protected:
    binaryTreeNode<E> *root;
    int treeSize;

    static void (*visit)(binaryTreeNode<E> *);//todo: function pointer
    static void preOrder(binaryTreeNode<E> *t);

    static void inOrder(binaryTreeNode<E> *t);

    static void postOrder(binaryTreeNode<E> *t);

    static void dispose(binaryTreeNode<E> *t);

    static int height(binaryTreeNode<E> *t);

public:
    linkedBinaryTree() {
        root = nullptr;
        treeSize = 0;
    }

    ~linkedBinaryTree() { erase(); }

    bool empty() const { return treeSize == 0; }

    int size() const { return treeSize; }

    //todo 公有遍历方法preOrder先给静态数据成员visit赋值，得到访问节点的函数，然后调用私有递归方法
    void preOrder(void(*theVisit)(binaryTreeNode<E> *)) {
        visit = theVisit;
        preOrder(root);
    }

    void inOrder(void(*theVisit)(binaryTreeNode<E> *)) {
        visit = theVisit;
        inOrder(root);
    }

    void postOrder(void(*theVisit)(binaryTreeNode<E> *)) {
        visit = theVisit;
        postOrder(root);
    }

    void levelOrder(void(*)(binaryTreeNode<E> *));

    void erase() {
        postOrder(dispose);
        root = nullptr;
        treeSize = 0;
    }
};

template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t) {
    if (t != nullptr) {
        linkedBinaryTree<E>::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template<class E>
void linkedBinaryTree<E>::inOrder(binaryTreeNode<E> *t) {// Inorder traversal.
    if (t != nullptr) {
        inOrder(t->leftChild);
        linkedBinaryTree<E>::visit(t);
        inOrder(t->rightChild);
    }
}

template<class E>
void linkedBinaryTree<E>::postOrder(binaryTreeNode<E> *t) {// Postorder traversal.
    if (t != nullptr) {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        linkedBinaryTree<E>::visit(t);
    }
}

//todo:height
template<class E>
int linkedBinaryTree<E>::height(binaryTreeNode<E> *t) {
    if (t == nullptr)
        return 0;
    int hl = height(t->leftChild);
    int hr = height(t->rightChild);
    if (hl > hr)
        return ++hl;
    else
        return ++hr;
}

#endif //LINKEDBINARYTREE_H_
