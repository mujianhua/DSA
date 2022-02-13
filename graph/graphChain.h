
//
// Created by MJH on 2022/1/16.
//

#ifndef GRAPHCHAIN_H_
#define GRAPHCHAIN_H_

#include "chainNode.h"
#include "chainWithIterator.h"

using namespace std;

template<class T>
class graphChain : public chain<T> {
public:
    T *eraseElement(int theVertex) {
        // Delete node with element == theVertex.
        // Return pointer to deleted element.
        // Return NULL if no matching element.
        chainNode<T> *current = firstNode,
                *trail = nullptr;
        while (current != nullptr && current->element != theVertex){
            trail = current;
            current = current->next;
        }
        if (current == nullptr)
            return nullptr;
        T *theElement = &current->element;
        if (trail != nullptr)
            trail->next = current->next;
        else
            firstNode = current->next;

        delete current;
        listSize--;
        return theElement;
    }
};

#endif //GRAPHCHAIN_H_
