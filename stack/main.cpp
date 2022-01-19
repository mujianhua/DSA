#include <iostream>
#include "arrayStack.h"

void printMatchedPairs(string expr);

int main() {
    string expr;
    expr = "(d+(a+b)*c*(d+e)-f))(()";
    printMatchedPairs(expr);
    return 0;
}
