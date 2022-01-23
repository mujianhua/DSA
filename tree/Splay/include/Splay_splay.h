//
// Created by MJH on 2022/1/23.
//

#pragma once

template<typename NodePosi>
inline
void attachAsLC(NodePosi lc, NodePosi p) {
    p->lc = lc;
    if (lc)
        lc->parent = p;
}

template<typename NodePosi>
inline
void attachAsRC(NodePosi p, NodePosi rc) {
    p->lc = rc;
    if (rc)
        rc->parent = p;
}


template<typename T>
BinNodePosi<T> Splay<T>::splay(BinNodePosi<T> v) {
    if (!v)
        return nullptr;
    BinNodePosi<T> p;
    BinNodePosi<T> g;
    while ((p = v->parent) && (g = p->parent)) {
        BinNodePosi<T> gg = g->parent;
        if (IsLChild(*v))
            if (IsLChild(*p)) {
                attachAsLC(p->rc, g);
                attachAsLC(v->rc, p);
                attachAsRC(p, g);
                attachAsRC(v, p);
            } else {
                attachAsLC(v->rc, p);
                attachAsRC(g, v->lc);
                attachAsLC(g, v);
                attachAsRC(v, p);
            }
        else if (IsRChild(*p)) {
            attachAsRC(g, p->lc);
            attachAsRC(p, v->lc);
            attachAsLC(g, p);
            attachAsLC(p, v);
        } else {
            attachAsRC(p, v->lc);
            attachAsLC(v->rc, g);
            attachAsRC(v, g);
            attachAsLC(p, v);
        }
        if (!gg)
            v->parent = nullptr;
        else
            (g == gg->lc) ? attachAsLC(v, gg) : attachAsRC(gg, v);
        BinTree<T>::updateHeight(g);
        BinTree<T>::updateHeight(p);
        BinTree<T>::updateHeight(v);
    }
    if (p = v->parent) {
        if (IsLChild(*v)) {
            attachAsLC(v->rc, p);
            attachAsRC(v, p);
        } else {
            attachAsRC(p, v->lc);
            attachAsLC(p, v);
        }
    }
    v->parent = nullptr;
    return v;
}