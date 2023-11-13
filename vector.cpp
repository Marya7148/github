#include <iostream>
#include "vector.h"

using namespace std;


Vector::Vector (int size, double* values) {
    this->size = size;
    values = new double[size];
    this->values = values;
    cout << " Vector initialisation: size = " << this->size << endl;
}

Vector::Vector (int size) {
    this->size = size;
    values = new double[size];
    for (int i = 0; i < size; i++) {
        values[i] = 0;
    }
    //cout << " Vector initialisation: size = " << this->size << endl;
}


Vector::Vector () {
    this->size = 0;
}

Vector::~Vector () {
    delete[] this->values;
}

int Vector::get_size() {
    return size;
}

double Vector::get_value(int i) {
    return this->values[i];}

void Vector::print_values() {
    for (int i = 0; i < this->size; i++) {
        cout << this->values[i] << " ";
    }
    cout << endl;
}

void Vector::set_value(int i, double value) {
    this->values[i] = value;
}

Vector Vector::sum(Vector &a) {
    if(this->size != a.get_size()) {
        cout << "Different sizes!" << endl;
        return 1;
    }
    else {
        double value = 0;
        Vector sum_vec(this->size, this->values);
        for (int i = 0; i < this->size; i++) {
            value = sum_vec.get_value(i) + a.get_value(i);
            sum_vec.set_value(i, value);
        }
        return sum_vec;
    }
}

double Vector::scalar_product(Vector &a) {
    if(this->size != a.get_size()) {
        cout << "Different sizes!" << endl;
        return 1;
    }
    else {
        double res = 0;
        for (int i = 0; i < this->size; i++) {
            res += this->values[i] * a.get_value(i);
            
        }
        return res;
    }
}

Vector Vector::mult_number(double lambda) {
    double value = 0;
    Vector res_vec(this->size, this->values);
    for (int i = 0; i < this->size; i++) {
        value = res_vec.get_value(i) * lambda;
        res_vec.set_value(i, value);
    }
    return res_vec;
}

void Vector::operator=(Vector a) {
    for (int i = 0; i < this->size; i++) { 
        this->values[i] = a.get_value(i);
    }
}
