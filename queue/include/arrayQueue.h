//
// Created by MJH on 2022/1/14.
//

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

#include "queue.h"
#include "myExceptions.h"
#include <sstream>

using namespace std;

template<class T>
class arrayQueue : public queue<T> {
private:
    int theFront;
    int theBack;
    int arrayLength;
    T *queue;
public:
    arrayQueue(int initialCapacity = 10);

    ~arrayQueue() { delete[] queue; }

    bool empty() const { return theFront == theBack; }

    int size() const { return (theBack - theFront + arrayLength) % arrayLength; }

    T &front() {
        if (theFront == theBack)
            throw queueEmpty();
        return queue[(theFront + 1) % arrayLength];//fixme: why + 1 ??????????
    }

    T &back() {
        if (theFront == theBack)
            throw queueEmpty();
        return queue[theBack];
    }

    void pop() {
        if (theFront == theBack)
            throw queueEmpty();
        theFront = (theFront + 1) % arrayLength;
        queue[theFront].~T();
    }

    void push(const T &theElement);
};

template<class T>
arrayQueue<T>::arrayQueue(int initialCapacity) {
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << "must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    queue = new T[arrayLength];
    theFront = 0;
    theBack = 0;
}

template<class T>
void arrayQueue<T>::push(const T &theElement) {
    // increase array length if necessary
    if ((theBack + 1) % arrayLength = theFront) {
        T *newQueue = new T[2 * arrayLength];
        int start = (theFront + 1) % arrayLength;
        if (start < 2)
            copy(queue + start, queue + arrayLength, newQueue);
        else {
            copy(queue + start, queue + arrayLength, newQueue);
            copy(queue, queue + theBack + 1, newQueue + arrayLength -start);
        }
        theFront = 2 * arrayLength - 1;
        theBack = arrayLength - 2;
        queue = newQueue;
    }

    theBack = (theBack + 1) % arrayLength;
    queue[theBack] = theElement;
}

#endif //ARRAYQUEUE_H_
