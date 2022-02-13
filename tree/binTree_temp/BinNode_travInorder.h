//
// Created by MJH on 2022/1/21.
//
#include <stack>
#include "BinNode_TravInorder_R.h"
#include "BinNode_TravInorder_I1.h"
#include "BinNode_TravInorder_I2.h"
#include "BinNode_TravInorder_I3.h"
#include "BinNode_TravInorder_I4.h"

template<typename T>
template<typename VST>
void BinNode<T>::travIn(VST &visit) {
    switch (rand() % 5) {
        case 1:
            travIn_I1(this, visit);
            break;
        case 2:
            travIn_I2(this, visit);
            break;
        case 3:
            travIn_I3(this, visit);
            break;
        case 4:
        default:
            travIn_R(this, visit);
            break;
    }
}
