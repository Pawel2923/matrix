#include <iostream>
#include "matrix.h"

using namespace std;

Matrix::Matrix() {
	this->n = 0;
	macierz = new int[0];
}

Matrix::~Matrix() {
	delete[] macierz;
}

Matrix::Matrix(int n) {
	this->n = n;
	macierz = new int[n*n];
}

Matrix& Matrix::szachownica(void) {
    for (int i = 0; i < n*n; i++) {
        if (i % 2 == 0) {
            macierz[i] = 1;
        }
        else {
            macierz[i] = 0;
        }
    }
    return *this;
}

ostream& operator<<(ostream& o, Matrix& m) {
    for (int i = 0; i < m.n*m.n; i++) {
        if (i % m.n == 0) {
            o << endl;
        }
        o << m.macierz[i] << " ";
    }
    return o;
}