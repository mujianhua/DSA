//
// Created by MJH on 2022/1/18.
//

#ifndef MATRIX_H_
#define MATRIX_H_

#include "myExceptions.h"

using namespace std;

template<class T>
class matrix {
    friend ostream &operator<<(ostream &, const matrix<T> &);

public:
    matrix(int theRows, int theColumns);

    matrix(const matrix<T> &);

    ~matrix() { delete[] element; }

    int rows() const { return theRows; }

    int columns() const { return theColumns; }

    T &operator()(int i, int j) const;

    matrix<T> &operator=(const matrix<T> &);

    matrix<T> operator+() const;

    matrix<T> operator+(const matrix<T> &) const;

    matrix<T> operator-() const;

    matrix<T> operator-(const matrix<T> &) const;

    matrix<T> operator*(const matrix<T> &) const;

    matrix<T> &operator+=(const T &);

private:
    int theRows, theColumns;
    T *element;
};

template<class T>
matrix<T>::matrix<class T>(int theRows, int theColumns) {
    if (theRows < 0 || theColumns < 0)
        throw illegalParameterValue("Rows and columns must be >= 0");
    if ((theRows == 0 || theColumns == 0) && (theRows != 0 || theColumns != 0))
        throw illegalParameterValue
                ("Either both or neither rows and columns should be zero");
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[theRows * theColumns];
}

template<class T>
matrix<T>::matrix(const matrix<T> &m) {
    // Copy constructor for matrices.
    // create matrix
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[theRows * theColumns];

    // copy each element of m
    copy(m.element,
         m.element + theRows * theColumns,
         element);
}

#endif //MATRIX_H_
