//
// Created by MJH on 2022/1/20.
//
#define stature(p) ((p) ? (p)->height : -1) //其余BST中节点的高度（NUll视作空树，对应于-1）
typedef enum {
    RB_RED, RB_BLACK
} RBColor;
template<typename T>
struct BinNode;
template<typename T> using BinNodePosi = BinNode<T> *;

template<typename T>
struct BinNode {
    // member
    T data;
    BinNodePosi<T> parent, lc, rc;
    int height;
    int npl;// Null Path Length
    RBColor color;

    //construct
    BinNode() : parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(0), color(RB_RED) {}

    BinNode(T e, BinNodePosi<T> p = nullptr, BinNodePosi<T> lc = nullptr, BinNodePosi<T> rc = nullptr,
            int h = 0, int l = 1, RBColor c = RB_RED) :
            data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

    //Operation interface
    int size();//当前节点后代总数

    BinNodePosi<T> insertAsLC(T const &); //作为当前节点的左孩子插入新节点
    BinNodePosi<T> insertAsRC(T const &); //作为当前节点的右孩子插入新节点
    BinNodePosi<T> succ(); //取当前节点的直接后继
    template<typename VST>
    void travLevel(VST &); //子树层次遍历
    template<typename VST>
    void travPre(VST &); //子树先序遍历
    template<typename VST>
    void travIn(VST &); //子树中序遍历
    template<typename VST>
    void travPost(VST &); //子树后序遍历
    // 比较器、判等器
    bool operator<(BinNode const &bn) { return data < bn.data; } //小于
    bool operator==(BinNode const &bn) { return data == bn.data; } //等于
};
#include "BinNode_implementation.h"