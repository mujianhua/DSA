//
// Created by MJH on 2022/1/21.
//

#pragma

template<typename T>
static void goAlongVine(BinNodePosi<T> x, std::stack<BinNodePosi<T>> &S) {
    while (x) {
        S.push(x);
        x = x->lc;
    }
}

template<typename T, typename VST>
void travIn_I1(BinNodePosi<T> x, VST &visit) {
    // todo : 体会一下
    std::stack<BinNodePosi<T>> S;
    while (true) {
        goAlongVine(x, S);
        if (S.empty()) break;
        x = S.pop();
        visit(x->data);
        x = x->rc;
    }
}
