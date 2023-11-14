#pragma once

class Vector {

public:
    Vector(int size, double* values);
    Vector(int size);
    Vector();
    ~Vector();
    int get_size();
    double get_value(int i);
    void print_values();
    void set_value(int i, double value);
    Vector sum(Vector &a);
    double scalar_product(Vector &a);
    Vector mult_number(double lambda);
    void operator=(Vector a);
protected:
    int size;
    double* values;

};
