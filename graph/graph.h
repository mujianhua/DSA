//
// Created by mujianhua on 2022/1/16.
//

#ifndef GRAPH_H_
#define GRAPH_H_

#include "vertexIterator.h"
#include "arrayQueue.h"

template<class T>
class graph {
public:
    virtual ~graph() {}

    virtual int numberOfVertices() const = 0;

    virtual int numberOfEdges() const = 0;

    virtual bool existEdge(int, int) const = 0;

    virtual void insertEdge(edge<T> *) = 0;

    virtual void eraseEdge(int, int) = 0;

    virtual int degree(int) const = 0;

    virtual int inDegree(int) const = 0;

    virtual int outDegree(int) const = 0;

    virtual bool directed() const = 0;

    virtual bool weighted() const = 0;

    virtual vertexIterator<T> *iterator(int) = 0;

    virtual void bfs(int v, int reach[], int label) {
        arrayQueue<int> q(10);
        reach[v] = label;
        q.push(v);
        while (!q.empty()) {
            int w = q.front();
            q.pop();

            vertexIterator<T> *iw = iterator(w);
            int u;
            while ((u = iw->next()) != 0)
                if (reach[u] == 0) {
                    q.push(u);
                    reach[u] = label;
                }
            delete iw;
        }
    }
};

#endif //GRAPH_H_
