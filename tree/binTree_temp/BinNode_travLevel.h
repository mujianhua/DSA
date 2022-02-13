//
// Created by MJH on 2022/1/22.
//
#include <queue>

template<typename T>
template<typename VST>
void BinNode<T>::travLevel(VST &visit) {
    std::queue<BinNode<T>> Q;
    Q.push(this);//根节点入栈
    while (!Q.empty()) {
        BinNodePosi<T> x = Q.front();
        Q.pop();
        visit(x->data);
        if (HasLChild(*x)) Q.push(x->lc);
        if (HasRChild(*x)) Q.push(x->rc);
    }
}

