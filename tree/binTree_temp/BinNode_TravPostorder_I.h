//
// Created by MJH on 2022/1/21.
//
//question:...
#pragma once

template<typename T>
static void gotoLeftmostLeaf(std::stack<BinNodePosi<T>> &S) {
    while (BinNodePosi<T> x = S.top())
        if (HasLChild(*x)) {
            if (HasRChild(*x))
                S.push(x->rc);
            S.push(x->lc);
        } else
            S.push(x->rc);
    S.pop();
}

template<typename T, typename VST>
void travPost_I(BinNodePosi<T> x, VST &visit) {
    std::stack<BinNodePosi<T>> S;
    if (x) S.push(x);//根节点入栈
    while (!S.empty()) {
        if (S.top() != x->parent)
            gotoLeftmostLeaf(S);
        x = S.top();
        S.pop();
        visit(x->data);
    }
}
