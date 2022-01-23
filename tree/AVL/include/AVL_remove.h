//
// Created by MJH on 2022/1/23.
//

#pragma once

template<typename T>
bool AVL<T>::remove(const T &e) {
    BinNodePosi<T> &x = BST<T>::search(e);
    if (!x)
        return false;
    removeAt(x, BST<T>::_hot);
    BinTree<T>::_size--;
    for (BinNodePosi<T> g = BST<T>::_hot; g; g = g->parent) {
        if (!AvlBalanced(*g))
            g = FromParentTo(*g) = BST<T>::rotateAt(tallerChild(tallerChild(g)));
        BinTree<T>::updateHeight(g);
    }
    return true;
}