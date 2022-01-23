
//
// Created by MJH on 2022/1/23.
//

#pragma once

template<typename T>
BinNodePosi<T> Splay<T>::insert(const T &e) {
    if (!BinTree<T>::_root) {
        BinTree<T>::_size++;
        BinTree<T>::_root = new BinNode<T>(e);
    }
    if (e == search(e)->data)
        return BinTree<T>::_root;
    BinTree<T>::_size++;
    BinNodePosi<T> t = BinTree<T>::_root;
    if (BinTree<T>::_root->data < e){
        t->parent = BinTree<T>::_root = new BinNode<T>(e, nullptr, t, t->rc);
        if (HasRChild(*t)){
            t->rc->parent = BinTree<T>::_root;
            t->rc = nullptr;
        }
    } else{
        t->parent = BinTree<T>::_root = new BinNode<T>(e, nullptr, t->lc, t);
        if (HasLChild(*t)){
            t->lc->parent = BinTree<T>::_root;
            t->lc = nullptr;
        }
    }
    BinTree<T>::updateHeightAbove(t);
    return BinTree<T>::_root;
}