//
// Created by MJH on 2022/1/21.
//

#pragma once

#include <stack>
#include "BinNode_TravPreorder_R.h"
#include "BinNode_TravPreorder_I1.h"
#include "BinNode_TravPreorder_I2.h"

template<typename T>
template<typename VST>
void BinNode<T>::travPre(VST &visit) {
    switch (rand() % 3) {
        case 1:
        case 2:
        default:
            travPre_R(this, visit);
            break;
    }
}
