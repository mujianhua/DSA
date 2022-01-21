//
// Created by MJH on 2022/1/20.
//
#pragma once

#include "BinNode.h"

template<typename T>
class BinTree {
protected:
    int _size;
    BinNodePosi<T> _root;

    // 在某些种类的二叉树，高度定义有所不同，因此这里将updateHeight()定义为保护级的虚方法，以便派生类在必要时重写
    virtual int updateHeight(BinNodePosi<T> x);

    void updateHeightAbove(BinNodePosi<T> x);

public:
    BinTree() : _size(0), _root(nullptr) {}

    ~BinTree() { if (0 < _size) remove(_root); }

    int size() const { return _size; }

    bool empty() const { return !_root; }

    BinNodePosi<T> root() const { return _root; }

    BinNodePosi<T> insert(T const &);

    BinNodePosi<T> insert(T const &, BinNodePosi<T>);// insert left child

    BinNodePosi<T> insert(BinNodePosi<T>, T const &);// insert right child

    BinNodePosi<T> attach(BinTree<T> *&, BinNodePosi<T>);//接入左子树

    BinNodePosi<T> attach(BinNodePosi<T>, BinTree<T> *&);

    int remove(BinNodePosi<T>);//删除以位置x处节点为根的子树，返回该子树原先的规模

    BinTree<T> *secede(BinNodePosi<T>);//子树分离

    template<typename VST>
    void travLevel(VST &visit) { if (_root) _root->travLevel(visit); }

    template<typename VST>
    void travPre(VST &visit) { if (_root) _root->travPre(visit); }

    template<typename VST>
    void travIn(VST &visit) { if (_root) _root->travIn(visit); }

    template<typename VST>
    void travPost(VST &visit) { if (_root) _root->travPost(visit); }

    bool operator<(BinTree<T> const &t) //比较器
    { return _root && t._root && lt(_root, t._root); }

    bool operator==(BinTree<T> const &t) //判等器
    { return _root && t._root && (_root == t._root); }
};

#include "BinTree_implementation.h"
