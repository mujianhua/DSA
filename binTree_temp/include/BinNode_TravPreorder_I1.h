//
// Created by MJH on 2022/1/21.
//
#include <stack>

#pragma once

template<typename T, typename VST>
void travPre_I1(BinNodePosi<T> x, VST &visit) {
    std::stack<BinNodePosi<T>> S;//辅助栈
    if (x)
        S.push(x);//根节点入栈
    while (!S.empty()) {
        x = S.pop();
        visit(x->data);
        if (HasRChild(*x))
            S.push(x->rc);
        if (HasLChild(*x))
            S.push(x->lc);
    }
}
