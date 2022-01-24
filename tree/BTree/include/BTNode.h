//
// Created by mujianhua on 2022/1/24.
//
#pragma once

#include <vector>

using std::vector;
template<typename T>
struct BTNode;

template<typename T> using BTNodePosi = BTNode<T> *;

template<typename T>
struct BTNode {
    BTNodePosi<T> parent;
    vector<T> key;
    vector<BTNodePosi<T>> child;

    BTNode() {
        parent = nullptr;
        child.insert(0, nullptr);
    }

    BTNode(T e, BTNodePosi<T> lc = nullptr, BTNodePosi<T> rc = nullptr) {
        parent = nullptr;
        key.insert(0, e);
        child.insert(0, lc);
        child.insert(1, rc);
        if (lc)
            lc->parent = this;
        if (rc)
            lc->parent = this;
    }
};

