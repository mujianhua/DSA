//
// Created by MJH on 2022/1/22.
//

#pragma once

template<typename T>
BinNodePosi<T> BST<T>::rotateAt(BinNodePosi<T> v) {
    if (!v) {
        printf("\a\nFail to rotate a null node\n");
        exit(-1);
    }
    BinNodePosi<T> p = v->parent;
    BinNodePosi<T> g = p->parent;
    if (IsLChild(*p)) {
        if (IsLChild(*v)) {
            //zig-zig
            p->parent = g->parent;
            rotateAt(v, p, g, v->lc, v->rc, p->rc, g->rc);
        } else {
            //zig-zag
            v->parent = g->parent;
            rotateAt(p, v, g, p->lc, v->lc, v->rc, g->rc);
        }
    } else if (IsRChild(*v)) {
        //zag-zag
        p->parent = g->parent;
        rotateAt(g, p, v, g->lc, p->lc, v->lc, v->rc);
    } else {
        //zag-zig
        v->parent = g->parent;
        rotateAt(g, v, p, g->lc, v->lc, v->rc, p->rc);
    }
}