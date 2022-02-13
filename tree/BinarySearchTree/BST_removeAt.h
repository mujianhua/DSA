//
// Created by MJH on 2022/1/22.
//

#pragma once

template<typename T>
static BinNodePosi<T> removeAt(BinNodePosi<T> &x, BinNodePosi<T> &hot) {
    BinNodePosi<T> w = x;
    BinNodePosi<T> succ = nullptr;
    if (!HasLChild(*x))
        succ = x = x->rc;
    else if (!HasRChild(*x))
        succ = x = x->lc;
    else {
        w = w->succ();
        swap(x->data, w->data);
        BinNodePosi<T> u = w->parent;
        ((u == x) ? u->rc : u->lc) = succ = w->rc;//mark
    }
    hot = w->parent;
    if (succ)
        succ->parent = hot;
    release(w->data);
    release(w);
    return succ;
}