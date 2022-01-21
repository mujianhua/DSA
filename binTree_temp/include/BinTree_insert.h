//
// Created by MJH on 2022/1/21.
//
#pragma once

template<typename T>
BinNodePosi<T> BinTree<T>::insert(T const &e) {
    _size = 1;
    return _root = new BinNode<T>(e);
}

template<typename T>
BinNodePosi<T> BinTree<T>::insert(const T &e, BinNodePosi<T> x) {
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

template<typename T>
BinNodePosi<T> BinTree<T>::insert(BinNodePosi<T> x, const T &e) {
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}