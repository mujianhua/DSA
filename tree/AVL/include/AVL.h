//
// Created by MJH on 2022/1/22.
//
#include "BST.h"

template<typename T>
class AVL : public BST<T> {
public:
    BinNodePosi<T> insert(const T &e);

    bool remove(const T &e);
};

#include "AVL_implementation.h"
