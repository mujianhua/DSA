//
// Created by MJH on 2022/1/23.
//

#pragma once

template<typename T>
BinNodePosi<T> &Splay<T>::search(const T &e) {
    BinNodePosi<T> p = BST<T>::search(e);
    BinTree<T>::_root = splay(p ? p : BST<T>::_hot);
    return BinTree<T>::_root;
}