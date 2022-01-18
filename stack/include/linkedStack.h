//
// Created by MJH on 2022/1/14.
//

#ifndef linkedStack_H_
#define linkedStack_H_

#include "stack.h"
#include "myExceptions.h"
#include "chainNode.h"
#include <sstream>

using namespace std;

template<class T>
class linkedStack : public stack<T> {
private:
    chainNode<T> *stackTop;
    int stackSize;
public:
    linkedStack(int initialCapacity = 10) {
        stackTop = nullptr;
        stackSize = 0;
    }
    ~linkedStack();
    bool empty() const {return stackSize == 0;}
    int size() const {return stackSize;}
    T &top(){
        if (stackSize == 0)
            throw stackEmpty();
        return stackTop->element;
    }
    void pop();
    void push(const T &theElement){
        stackTop = new chainNode<T>(theElement, stackTop);
        stackSize++;
    }
};

template<class T>
linkedStack<T>::~linkedStack(){
    while (stackTop != nullptr){
        chainNode<T> *nextNode = stackTop->next;
        delete stackTop;
        stackTop = nextNode;
    }
}

template<class T>
void linkedStack<T>::pop(){
    if (stackSize ==0)
        throw stackEmpty();
    chainNode<T> *nextNode = stackTop->next;
    delete stackTop;
    stackTop = nextNode;
    stackSize --;
}

#endif //linkedStack_H_
