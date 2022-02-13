//
// Created by MJH on 2022/1/21.
//

#pragma once

template<typename T>
static int removeAt(BinNodePosi<T> x) {
    if (!x)
        return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    release(x->data);
    release(x);
    return n;
}

template<typename T>
int BinTree<T>::remove(BinNodePosi<T> x) {
    FromParentTo(*x) = nullptr;//切断来自父节点的指针
    updateHeightAbove(x->parent);
    int n = removeAt(x);
    _size -= n;
    return n;
}

