//
// Created by MJH on 2022/1/21.
//

#pragma once

template<typename T, typename VST>
void travIn_I3(BinNodePosi<T> x, VST &visit) {
    bool backtrack = false;
    while (true) {
        if (!backtrack && HasLChild(*x))
            x = x->lc;
        else {
            visit(x->data);
            if (HasRChild(*x)) {
                x = x->rc;
                backtrack = false;
            } else {
                if (!(x = x->succ())) break;
                backtrack = true;
            }
        }
    }
}
