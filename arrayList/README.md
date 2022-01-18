**ostream有bug，未修改**

###copy的用法
```c++
void changeLength1D(T *&a, int oldLength,int newLength) {
    if (newLength < 0)
        throw illegalParameterValue("the length must be >= 0");
    T *temp = new T[newLength];
    int number = min(oldLength, newLength);  //需要复制的元素个数
    //将a指向的数组中的number个元素复制到temp指向的数组中
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}
```