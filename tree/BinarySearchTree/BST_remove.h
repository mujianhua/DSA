//
// Created by MJH on 2022/1/22.
//
#pragma once
template<typename T>
bool BST<T>::remove(const T &e) {
    BinNodePosi<T> &x = search(e);
    if (!x)
        return false;
    removeAt(x, _hot);
    BinTree<T>::_size--;
    BinTree<T>::updateHeightAbove(_hot);
    return true;
}
