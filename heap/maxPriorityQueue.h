//
// Created by MJH on 2022/1/15.
//

#ifndef MAXPRIORITYQUEUE_H_
#define MAXPRIORITYQUEUE_H_

using namespace std;

template<class T>
class maxPriorityQueue {
public:
    virtual ~maxPriorityQueue();

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual const T &top() = 0;

    virtual void pop() = 0;

    virtual void push(const T &theElement) = 0;
};

#endif //MAXPRIORITYQUEUE_H_
