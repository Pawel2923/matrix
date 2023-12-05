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

Matrix::Matrix(int n, int* t) {
	this->n = n;
	macierz = new int[n*n];
	for (int i = 0; i < n * n; i++) {
		macierz[i] = t[i];
	}
}

Matrix::Matrix(Matrix& m) {
	this->n = m.n;
	macierz = new int[n*n];
	for (int i = 0; i < n * n; i++) {
		macierz[i] = m.macierz[i];
	}
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

// Przeciązenia operatorów dodawania

Matrix& Matrix::operator+(Matrix& m) {
	Matrix* wynik = new Matrix(n);
    for (int i = 0; i < n * n; i++) {
		wynik->macierz[i] = macierz[i] + m.macierz[i];
	}
	return *wynik;
}

Matrix& Matrix::operator+(int a) {
	Matrix* wynik = new Matrix(n);
    for (int i = 0; i < n * n; i++) {
		wynik->macierz[i] = macierz[i] + a;
	}
	return *wynik;
}

Matrix operator+(int a, Matrix& m) {
	Matrix* wynik = new Matrix(m.n);
	for (int i = 0; i < m.n * m.n; i++) {
		wynik->macierz[i] = m.macierz[i] + a;
	}
	return *wynik;
}

// Przeciążenia operatorów odejmowania

Matrix& Matrix::operator-(int a) {
	Matrix* wynik = new Matrix(n);
	for (int i = 0; i < n * n; i++) {
		wynik->macierz[i] = macierz[i] - a;
	}
	return *wynik;
}

Matrix operator-(int a, Matrix& m) {
	Matrix* wynik = new Matrix(m.n);
	for (int i = 0; i < m.n * m.n; i++) {
		wynik->macierz[i] = a - m.macierz[i];
	}
	return *wynik;
}

// Przeciążenia operatorów mnożenia

Matrix& Matrix::operator*(Matrix& m) {
	Matrix* wynik = new Matrix(n);
	for (int i = 0; i < n * n; i++) {
		wynik->macierz[i] = macierz[i] * m.macierz[i];
	}
	return *wynik;
}

Matrix& Matrix::operator*(int a) {
	Matrix* wynik = new Matrix(n);
	for (int i = 0; i < n * n; i++) {
		wynik->macierz[i] = macierz[i] * a;
	}
	return *wynik;
}

Matrix operator*(int a, Matrix& m) {
	Matrix* wynik = new Matrix(m.n);
	for (int i = 0; i < m.n * m.n; i++) {
		wynik->macierz[i] = m.macierz[i] * a;
	}
	return *wynik;
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

Matrix::operator double() {
	double suma = 0;
	for (int i = 0; i < n * n; i++) {
		suma += macierz[i];
	}
	return suma;
}