#include <iostream>
#include "arrayList.h"
#include "linearList.h"

using namespace std;

int main() {
    linearList<double> *x = new arrayList<double>(20);
    arrayList<int> y(2), z;

    //test capacity
    cout << "Capacity of x, y and z = "
         << ((arrayList<double> *) x)->capacity() << ", "//x是指向基类的指针，没有capacity()的方法，需把它转为派生类
         << y.capacity() << ", "
         << z.capacity() << endl;
    //test size
    cout << "Initial size of x, y and z = "
         << x->size() << ", "
         << y.size() << ", "
         << z.size() << endl;
    //test empty
    if (x->empty()) cout << "x is empty" << endl;
    else cout << "x is not empty" << endl;
    if (y.empty()) cout << "y is empty" << endl;
    else cout << "y is not empty" << endl;

    return 0;
}
