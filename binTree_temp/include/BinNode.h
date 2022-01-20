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
};