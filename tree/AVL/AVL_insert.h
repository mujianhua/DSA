//
// Created by MJH on 2022/1/22.
//

#pragma once

template<typename T>
BinNodePosi<T> AVL<T>::insert(const T &e) {
    BinNodePosi<T> &x = search(e);
    if (x)
        return x;
    BinNodePosi<T> xx = x = new BinNode<T>(e, BST<T>::_hot);
    BinNode<T>::_size++;
    for (BinNodePosi<T> g = BST<T>::_hot; g; g = g->parent) {
        if (!AvlBalanced(*g)) {
            //bug:?? 宏定义
            FromParentTo(*g) = BST<T>::rotateAt(tallerChild(tallerChild(g)));
            break;
        } else
            BinTree<T>::updateHeight(g);
    }
    return xx;
}