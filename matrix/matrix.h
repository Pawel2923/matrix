#pragma once
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
	int n;
	int* macierz;

public:
	Matrix(void);
	Matrix(int n);
	Matrix(int n, int* t);
	Matrix(Matrix& m);
	~Matrix(void);
	Matrix& alokuj(int n);
	Matrix& wstaw(int x, int y, int wartosc);
	int pokaz(int x, int y);
	Matrix& dowroc(void);
	Matrix& losuj(void);
	Matrix& losuj(int x);
	Matrix& diagonalna(int* t);
	Matrix& diagonalna_k(int k, int* t);
	Matrix& kolumna(int x, int* t);
	Matrix& wiersz(int y, int* t);
	Matrix& przekatna(void);
	Matrix& pod_przekatna(void);
	Matrix& nad_przekatna(void);
	Matrix& szachownica(void);
	Matrix& operator+(Matrix& m);
	Matrix& operator*(Matrix& m);
	Matrix& operator+(int a);
	Matrix& operator*(int a);
	Matrix& operator-(int a);
	friend Matrix operator+(int a, Matrix& m);
	friend Matrix operator*(int a, Matrix& m);
	friend Matrix operator-(int a, Matrix& m);
	Matrix& operator++(int);
	Matrix& operator--(int);
	Matrix& operator+=(int a);
	Matrix& operator-=(int a);
	Matrix& operator*=(int a);
	operator double();
	friend std::ostream& operator<<(std::ostream& o, Matrix& m);
	bool operator==(const Matrix& m);
	bool operator>(const Matrix& m);
	bool operator<(const Matrix& m);
};

#endif // !MATRIX_H
