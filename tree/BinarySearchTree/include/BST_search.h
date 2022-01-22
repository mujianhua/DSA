//
// Created by MJH on 2022/1/22.
//

#pragma once

template<typename T>
BinNodePosi<T> &BST<T>::search(const T &e) {
    if (!BinTree<T>::_root || e == BinTree<T>::_root->data) {
        //bug: protected 的变量为什么派生类还是不能用.......???????????????
        _hot = nullptr;
        return BinTree<T>::_root;
    }
    for (_hot = BinTree<T>::_root;;) {
        BinNodePosi<T> &v = (e < _hot->data) ? _hot->lc : _hot->rc;
        if (!v || e == v->data)
            return v;
        _hot = v;
    }
}
