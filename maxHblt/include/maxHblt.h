//
// Created by mujianhua on 2022/1/16.
//

#ifndef MAXHBLT_H_
#define MAXHBLT_H_

#include "maxPriorityQueue.h"
#include "linkedBinaryTree.h"
#include "binaryTreeNode.h"
#include "myExceptions.h"
#include <sstream>

using namespace std;

template<class T>
class maxHblt : public maxPriorityQueue<T>,
                public linkedBinaryTree<pair<int, T>> {

};

#endif //MAXHBLT_H_
