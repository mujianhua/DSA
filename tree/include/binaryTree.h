//
// Created by MJH on 2022/1/14.
//

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <functional>

using namespace std;

template<class T>
class binaryTree {
public:
    virtual ~binaryTree() {}

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual void preOrder(void (*)(T *)) = 0;

    // parameter is a pointer to a function whose return
    // type is void and has a single argument of type T*
    virtual void inOrder(void (*)(T *)) = 0;

    virtual void postOrder(void (*)(T *)) = 0;

    virtual void levelOrder(void (*)(T *)) = 0;
};

#endif //BINARYTREE_H_
