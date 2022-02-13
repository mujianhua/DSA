//
// Created by MJH on 2022/1/21.
//

#pragma once

template<typename T, typename VST>
static void visitAlongVine(BinNodePosi<T> x, VST &visit, std::stack<BinNodePosi<T>> &S) {
    while (x) {
        visit(x->data);
        S.push(x->rc);
        x = x->lc;
    }
}

template<typename T, typename VST>
void travPre_I2(BinNodePosi<T> x, VST &visit) {
    std::stack<BinNodePosi<T>> S;
    while (true) {
        visitAlongVine(x, visit, S);
        if (S.empty()) break;
        x = S.top();
        S.pop();
    }
}
