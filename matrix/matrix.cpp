#include <iostream>
#include "matrix.h"

using namespace std;

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

void Matrix::losuj() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void Matrix::diagonalna(int* t) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        matrix[i][i] = t[k];
        k++;
    }
}

void Matrix::diagonalna_k(int k, int* t) {
    int l = 0;
    for (int i = 0; i < n; i++) {
        matrix[i][i + k] = t[l];
        l++;
    }
}

void Matrix::kolumna(int x, int* t) {
    for (int i = 0; i < n; i++) {
        matrix[i][x] = t[i];
    }
}

void Matrix::wiersz(int y, int* t) {
    for (int i = 0; i < n; i++) {
        matrix[y][i] = t[i];
    }
}

void Matrix::przekatna() {
    for (int i = 0; i < n; i++) {
        matrix[i][i] = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matrix[i][j] = 0;
            }
        }
    }
}

void Matrix::pod_przekatna() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                matrix[i][j] = 1;
            }
            else {
                matrix[i][j] = 0;
            }
        }
    }
}

void Matrix::nad_przekatna() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                matrix[i][j] = 1;
            }
            else {
                matrix[i][j] = 0;
            }
        }
    }
}

void Matrix::dowroc() {
    int** matrix2 = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix2[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix2[i][j] = matrix[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = matrix2;
}

int Matrix::pokaz(int x, int y) {
    return matrix[x][y];
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

// Przeci�zenia operator�w dodawania

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

// Przeci��enia operator�w odejmowania

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

// Przeci��enia operator�w mno�enia

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

// Przeci��enia operator�w inkrementacji i dekrementacji

Matrix& Matrix::operator++(int) {
	for (int i = 0; i < n * n; i++) {
		macierz[i]++;
	}
	return *this;
}

Matrix& Matrix::operator--(int) {
	for (int i = 0; i < n * n; i++) {
		macierz[i]--;
	}
	return *this;
}

// Przeci��enia opreator�w przypisania

Matrix& Matrix::operator+=(int a) {
	for (int i = 0; i < n * n; i++) {
		macierz[i] += a;
	}
	return *this;
}

Matrix& Matrix::operator-=(int a) {
	for (int i = 0; i < n * n; i++) {
		macierz[i] -= a;
	}
	return *this;
}

Matrix& Matrix::operator*=(int a) {
	for (int i = 0; i < n * n; i++) {
		macierz[i] *= a;
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

Matrix::operator double() {
	double suma = 0;
	for (int i = 0; i < n * n; i++) {
		suma += macierz[i];
	}
	return suma;
}

// Przeci��enia operator�w por�wnania

bool Matrix::operator==(const Matrix& m) {
	if (n != m.n) {
		return false;
	}
	for (int i = 0; i < n * n; i++) {
		if (macierz[i] != m.macierz[i]) {
			return false;
		}
	}
	return true;
}

bool Matrix::operator>(const Matrix& m) {
	if (n != m.n) {
		return false;
	}
	for (int i = 0; i < n * n; i++) {
		if (macierz[i] <= m.macierz[i]) {
			return false;
		}
	}
	return true;
}

bool Matrix::operator<(const Matrix& m) {
	if (n != m.n) {
		return false;
	}
	for (int i = 0; i < n * n; i++) {
		if (macierz[i] >= m.macierz[i]) {
			return false;
		}
	}
	return true;
}