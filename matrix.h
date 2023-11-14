#pragma once

#include "vector.h"



class Matrix : public Vector {

public:
    Matrix(int size1, int size2,  Vector* rows);
    ~Matrix();
    int get_size1();
    int get_size2();
    double get_value(int i, int j);
    void print_values();
    Vector mult_vector(Vector a);

protected:
    int size1, size2;
    Vector* rows;

};
