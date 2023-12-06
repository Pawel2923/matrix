#include "matrix.h"

Matrix::Matrix() : n(0), matrix(nullptr) {}

Matrix::Matrix(int n) : n(n) {
    matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int n, int* t) : n(n) {
    matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = t[k];
            k++;
        }
    }
}

Matrix::Matrix(const Matrix& m) : n(m.n) {
    matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix& Matrix::alokuj(int n) {
    if (matrix == nullptr) {
        matrix = new int* [n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }
    }
    else {
        if (this->n != n) {
            for (int i = 0; i < this->n; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = new int* [n];
            for (int i = 0; i < n; i++) {
                matrix[i] = new int[n];
            }
        }
    }
    return *this;
}

Matrix& Matrix::wstaw(int x, int y, int wartosc) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        matrix[x][y] = wartosc;
    }
    return *this;
}

void Matrix::losuj(int x) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

