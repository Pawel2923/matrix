#include "matrix.h"


Matrix::Matrix(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
}
Matrix::Matrix(int n, int* t) {
    int** matrix = new int* [n];
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
Matrix::Matrix(const Matrix& m) {
	int** matrix = new int* [m.n];
	for (int i = 0; i < m.n; i++) {
		matrix[i] = new int[m.n];
	}
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
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

Matrix::losuj(int x)
{
	srand(time(NULL));
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}