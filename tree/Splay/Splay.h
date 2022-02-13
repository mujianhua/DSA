//
// Created by MJH on 2022/1/23.
//
#pragma once

#include "BST.h"

template<typename T>
class Splay : public BST<T> {
protected:
    BinNodePosi<T> splay(BinNodePosi<T> v);//
public:
    BinNodePosi<T> &search(const T &e);

    BinNodePosi<T> insert(const T &e);

    bool remove(const T &e);
};

#include "Splay_implementation.h"