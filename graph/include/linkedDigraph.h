//
// Created by MJH on 2022/1/16.
//

#ifndef LINKEDDIGRAPH_H_
#define LINKEDDIGRAPH_H_

#include <iostream>
#include <sstream>
#include "graph.h"
#include "vertexIterator.h"
#include "myExceptions.h"
#include "graphChain.h"
#include "arrayQueue.h"
#include "unweightedEdge.h"

using namespace std;

class linkedDigraph : public graph<bool> {
protected:
    int n;
    int e;
    graphChain<int> *aList;
public:
    linkedDigraph(int numberOfVertices = 0) {
        if (numberOfVertices < 0)
            throw illegalParameterValue("number of vertices must be >= 0");
        n = numberOfVertices;
        e = 0;
        aList = new graphChain<int>[n + 1];
    }

    ~linkedDigraph() { delete[] aList; }

    int numberOfVertices() const { return n; }

    int numberOfEdges() const { return e; }

    bool directed() const { return true; }

    bool weighted() const { return false; }

    bool existEdge(int i, int j) const {
        if (i < 1 || j < 1 || i > n || j > n || aList[i].indexOf(j) == -1)
            return false;
        else
            return true;
    }

    void insertEdge(edge<bool> *theEdge) {
        int v1 = theEdge->vertex1();
        int v2 = theEdge->vertex2();
        if (v1 < 1 || v2 < 1 || v1 > n || v2 > n || v1 == v2) {
            ostringstream s;
            s << "(" << v1 << "," << v2 << ") is not a permissible edge";
            throw illegalParameterValue(s.str());
        }
        if (aList[v1].indexOf(v2) == -1) {
            //new edge
            aList[v1].insert(0, v2);
            e++;
        }
    }

    void insertEdgeNoCheck(edge<bool> *theEdge) {
        aList[theEdge->vertex1()].insert(0, theEdge->vertex2());
        e++;
    }

    void eraseEdge(int i, int j) {
        if (i >= 1 && j >= 1 && i <= n && j <= n) {
            int *v = aList[i].eraseElement(j);
            if (v != nullptr)
                e--;
        }
    }

    void checkVertex(int theVertex) const {// Verify that i is a valid vertex.
        if (theVertex < 1 || theVertex > n) {
            ostringstream s;
            s << "no vertex " << theVertex;
            throw illegalParameterValue(s.str());
        }
    }

    int degree(int theVertex) const { throw undefinedMethod("degree() undefined"); }

    int outDegree(int theVertex) const {
        checkVertex(theVertex);
        return aList[theVertex].size();
    }

    int inDegree(int theVertex) const {
        checkVertex(theVertex);
        int sum = 0;
        for (int j = 0; j <= n; j++)
            if (aList[j].indexOf(theVertex) != -1)
                sum++;
        return sum;
    }

    class myIterator : public vertexIterator<bool> {
    protected:
        chainNode<int> *currentNode;
    public:
        myIterator(chainNode<int> *theNode) { currentNode = theNode; }

        ~myIterator() {}

        int next() {
            int nextVertex = currentNode->element;
            currentNode = currentNode->next;
            return nextVertex;
        }

        int next(bool &theWeight) {
            // Return next vertex if any. Return 0 if no next vertex.
            // Set theWeight = edge weight.
            // find next adjacent vertex
            if (currentNode == NULL)
                return 0;
            int nextVertex = currentNode->element;
            currentNode = currentNode->next;
            theWeight = true;
            return nextVertex;
        }
    };

    myIterator *iterator(int theVertex){
        checkVertex(theVertex);
        return new myIterator(aList[theVertex].firstNode);
    }

    void bfs(int v, int reach[], int label){
        arrayQueue<int> q(10);
        reach[v] = label;
        q.push(v);
        while (!q.empty()){
            int w = q.front();
            q.pop();
            for (chainNode<int> *u = aList[w].firstNode; u != nullptr; u = u->next)
                if (reach[u->element] == 0){
                    q.push(u->element);
                    reach[u->element] = label;
                }
        }
    }

};

#endif //LINKEDDIGRAPH_H_
