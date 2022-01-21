//
// Created by MJH on 2022/1/21.
//

#pragma once

template<typename T>
BinNodePosi<T> BinNode<T>::insertAsLC(const T &e) {
    return lc = new BinNode(e, this);//将e作为当前节点的左孩子插入二叉树
}

template<typename T>
BinNodePosi<T> BinNode<T>::insertAsRC(const T &e) {
    return rc = new BinNode(e, this);
}
