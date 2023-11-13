#include <iostream>
#include <stdio.h>
#include "vector.h"
#include "matrix.h"

using namespace std;

int alpha = 0.01;

int main () {
    double values1[3] = {2, -1, 0};
    double values2[3] = {-1, 2, -1};
    double values3[3] = {0, -1, 2};
    Vector rows1(3, values1);
    Vector rows2(3, values2);
    Vector rows3(3, values3);
    Vector rows_[3] = {rows1, rows2, rows3};
    Vector rows(3, rows_);
    Matrix A(3, 3, rows);

    double values[3] = {1, -1, 2};
    Vector b(3, values);
    b = b.mult_number(-1);

    Vector x(3), y(3);

    for(int n = 0, n < 10, n++) {
        y = A.mult_vector(x);
        y = y.sum(b);
        y = y.mult_number(alpha);
        x = x.sum(y);
    }
    x.print_values();
    return 0;
}