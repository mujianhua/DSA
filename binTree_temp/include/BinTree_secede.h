//
// Created by MJH on 2022/1/21.
//

#pragma once

template<typename T>
BinTree<T> *BinTree<T>::secede(BinNodePosi<T> x) {
    //二叉树子树分离算法：将子树x从当前树中摘除，将其封装为一棵独立子树返回
    FromParentTo(*x) = nullptr;
    updateHeightAbove(x);
    BinTree<T> *S = new BinTree<T>;
    S->_root = x;
    x->parent = nullptr;
    S->_size = x->size();
    _size -= S->_size;
    return S;
}
