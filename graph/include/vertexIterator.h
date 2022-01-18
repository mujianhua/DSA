//
// Created by mujianhua on 2022/1/16.
//
#ifndef VERTEXITERATOR_H_
#define VERTEXITERATOR_H_

using namespace std;

template<class T>
class vertexIterator {
public:
    virtual ~vertexIterator() {}

    virtual int next() = 0;

    virtual int next(T &) = 0;
};

#endif

