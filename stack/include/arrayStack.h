//
// Created by MJH on 2022/1/14.
//

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include "stack.h"
#include "myExceptions.h"
#include "sstream"
#include "changeLength1D.h"

template<class T>
class arrayStack : public stack<int> {
private:
    int stackTop;
    int arrayLength;
    T *stack;
public:
//    arrayStack(int initialCapacity) : stack<T>(initialCapacity) {}

    arrayStack(int initialCapacity = 10);

    ~arrayStack() { delete[] stack; }

    bool empty() const { return stackTop == -1; }

    int size() const { return stackTop + 1; }

    T &top() {
        if (stackTop == -1)
            throw stackEmpty();
        return stack[stackTop];
    }

    void pop() {
        if (stackTop == -1)
            throw stackEmpty();
        stack[stackTop--].~T();
    }

    void push(const T &theElement);
};

template<class T>
arrayStack<T>::arrayStack(int initialCapacity) {
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << "must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    stack = new T[arrayLength];
    stackTop = -1;
}

template<class T>
void arrayStack<T>::push(const T &theElement) {
    if (stackTop == arrayLength - 1) {
        changeLength1D(stack, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    stack[++stackTop] = theElement;
}

#endif //ARRAYSTACK_H_
