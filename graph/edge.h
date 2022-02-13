//
// Created by mujianhua on 2022/1/16.
//

#ifndef EDGE_H_
#define EDGE_H_

using namespace std;

template<class T>
class edge{
public:
    virtual ~edge() {}
    virtual int vertex1() const = 0;
    virtual int vertex2() const = 0;
    virtual T weight() const = 0;
};

#endif //EDGE_H_
