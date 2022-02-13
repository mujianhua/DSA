//
// Created by MJH on 2022/1/21.
//


#pragma once

template<typename T, typename VST>
void travIn_I2(BinNodePosi<T> x, VST &visit) {
    std::stack<BinNodePosi<T>> S;
    while (true) {
        if (x) {
            S.push(x);
            x = x->lc;
        } else if (!S.empty()) {
            x = S.top();
            S.pop();
            visit(x->data);
            x = x->rc;
        } else break;
    }
}