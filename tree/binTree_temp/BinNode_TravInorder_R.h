//
// Created by MJH on 2022/1/21.
//
#pragma once

template<typename T, typename VST>
void travIn_R(BinNodePosi<T> x, VST &visit) { //二叉树中序遍历算法（递归版）
    if (!x) return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}
