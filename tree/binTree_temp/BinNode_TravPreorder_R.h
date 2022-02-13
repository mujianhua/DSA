//
// Created by MJH on 2022/1/21.
//

#pragma once

//元素类型、操作器
template<typename T, typename VST>
void travPre_R(BinNodePosi<T> x, VST &visit) {
    if (!x) return;
    visit(x->data);
    travPre_R(x->lc, visit);
    travPre_R(x->rc, visit);
}

