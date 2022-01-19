//
// Created by MJH on 2022/1/14.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

template<class T>
class stack {
public:
    virtual ~stack() {}

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual T &top() = 0;//woshishabi... 不带const.........

    virtual void pop() = 0;

    virtual void push(const T &theElement) = 0;
};

#endif //STACK_STACK_H