//
// Created by MJH on 2022/1/22.
//

#pragma once
template<typename T>
BinNodePosi<T> BST<T>::insert(const T &e) {
    BinNodePosi<T> &x = search(e);
    if (x)
        return x;
    x = new BinNode<T>(e, _hot);
    BinTree<T>::_size ++;
    BinTree<T>::updateHeightAbove(x);
    return x;
}