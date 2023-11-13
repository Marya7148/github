#include <iostream>
#include "matrix.h"

using namespace std;

Matrix::Matrix (int size1, int size2, Vector* rows) {
    this->size1 = size1;
    this->size2 = size2;

    this->rows = new Vector[size1];

    for (int i = 0; i < this->size; i++) {
        this->rows[i] = rows[i];
    }

    cout << " Matrix initialisation: size " << this->size1 << ", " << this->size2 << endl;
}

Matrix::~Matrix () {
    delete[] this->values;
}

int Matrix::get_size1() {
    return size1;
}

int Matrix::get_size2() {
    return size2;
}

double Matrix::get_value(int i, int j) {
    return this->rows[i].get_value(j);
}

void Matrix::print_values() {
    for (int i = 0; i < this->size; i++) {
        this->rows[i].print_values();
        cout << endl;
    }
}

Vector Matrix::mult_vector(Vector a) {
    Vector b(size1); 
    double res = 0;
    for (int i = 0; i < size1; i++) {
        res = (rows[i]).scalar_product(a);
        b.set_value(i, res);
    }
    return b;
}
