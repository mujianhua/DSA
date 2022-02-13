//
// Created by mujianhua on 2022/1/19.
//
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "hash.h"
#include "myExceptions.h"
#include <iostream>

using namespace std;

template<class T, class E>
class hashTable {
protected:
    int search(const K &) const;

    pair<const K, E> **table;
    hash<K> hash;
    int dSize;
    int divisor;
public:
    hashTable(int theDivisor = 11);

    ~hashTable() { delete[] table; }

    bool empty() const { return dSize == 0; }

    int size() const { return dSize; }

    pair<const K, E> *find(const K &) const;

    void insert(const pair<const K, E> &);

    void output(ostream &out) const;
};

template<class K, class E>
hashTable<K, E>::hashTable(int theDivisor) {
    divisor = theDivisor;
    dSize = 0;
    table = new pair<const K, E> *[divisor];
    for (int i = 0; i < divisor; i++)
        table[i] = nullptr;
}

template<class K, class E>
hashTable<K, int E>::search(const int &theKey) const {
    int i = (int) hash(theKey) % divisor;
    int j = i;
    //todo:
}

#endif


