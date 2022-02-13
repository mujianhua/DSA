//
// Created by MJH on 2022/1/23.
//

#pragma once

template<typename T>
bool Splay<T>::remove(const T &e) {
    if (!BinTree<T>::_root || (e != search(e)->data))
        return false;
    BinNodePosi<T> w = BinTree<T>::_root;
    if (!HasLChild(*BinTree<T>::_root)) {
        BinTree<T>::_root = BinTree<T>::_root->rc;
        if (BinTree<T>::_root)
            BinTree<T>::_root->parent = nullptr;
    } else if (!HasRChild (*BinTree<T>::_root)) {
        BinTree<T>::_root = BinTree<T>::_root->lc;
        if (BinTree<T>::_root)
            BinTree<T>::_root->parent = nullptr;
    } else {
        BinNodePosi<T> lTree = BinTree<T>::_root->lc;
        lTree->parent = nullptr;
        BinTree<T>::_root->lc = nullptr;
        BinTree<T>::_root = BinTree<T>::_root->rc;
        BinTree<T>::_root->parent = nullptr;
        search(w->data);
        BinTree<T>::_root->lc = lTree;
        lTree->parent = BinTree<T>::_root;
    }
    release(w->data);
    release(w);
    BinTree<T>::_size--;
    if (BinTree<T>::_root)
        BinTree<T>::updateHeight(BinTree<T>::_root);
    return true;
}