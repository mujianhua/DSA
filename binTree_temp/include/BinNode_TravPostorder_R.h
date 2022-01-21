//
// Created by MJH on 2022/1/21.
//

#pragma once

template<typename T, typename VST>
void travPost_R(BinNodePosi<T> x, VST &visit) {
    //二叉树后序遍历算法（递归版）
    if (!x) return;
    travPost_R(x->lc, visit);
    travPost_R(x->rc, visit);
    visit(x->data);
}
