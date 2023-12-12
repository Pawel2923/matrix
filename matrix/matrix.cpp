#include <iostream>
#include <fstream>
#include <string>
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
            if (k < n * n) {
                matrix[i][j] = t[k];
                k++;
            }
            else {
                matrix[i][j] = 0;
            }
        }
    }
}

Matrix::Matrix(Matrix& m) : n(m.n) {
    matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
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
    this->n = n;
    return *this;
}

Matrix& Matrix::wstaw(int x, int y, int wartosc) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        matrix[x][y] = wartosc;
    }
    return *this;
}

Matrix& Matrix::losuj(int x) {
    // Losowanie cyfr od 0 do 9
    int* randNum = new int[x];
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < x; i++) {
        randNum[i] = rand() % 10;
    }

    // Wstawianie liczb do macierzy w losowych miejscach
    int k = 0;
    int* randX = new int[x];
    int* randY = new int[x];
    for (int i = 0; i < x; i++) {
		randX[i] = rand() % n;
		randY[i] = rand() % n;
		matrix[randX[i]][randY[i]] = randNum[k];
		k++;
	}

    return *this;
}

Matrix& Matrix::losuj() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    return *this;
}

Matrix& Matrix::diagonalna(int* t) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        matrix[i][i] = t[k];
        k++;
    }
    return *this;
}

Matrix& Matrix::diagonalna_k(int k, int* t) {
    int l = 0;
    for (int i = 0; i < n; i++) {
        matrix[i][i + k] = t[l];
        l++;
    }
    return *this;
}

Matrix& Matrix::kolumna(int x, int* t) {
    for (int i = 0; i < n; i++) {
        matrix[i][x] = t[i];
    }
    return *this;
}

Matrix& Matrix::wiersz(int y, int* t) {
    for (int i = 0; i < n; i++) {
        matrix[y][i] = t[i];
    }
    return *this;
}

Matrix& Matrix::przekatna() {
    for (int i = 0; i < n; i++) {
        matrix[i][i] = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matrix[i][j] = 0;
            }
        }
    }
    return *this;
}

Matrix& Matrix::pod_przekatna() {
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
    return *this;
}

Matrix& Matrix::nad_przekatna() {
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
    return *this;
}

Matrix& Matrix::dowroc() {
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
    return *this;
}

int Matrix::pokaz(int x, int y) {
    return matrix[x][y];
}

Matrix& Matrix::szachownica() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = (i + j) % 2 == 0 ? 1 : 0;
        }
    }
    return *this;
}

// Przeciezenia operatorow dodawania

Matrix& Matrix::operator+(Matrix& m) {
	Matrix* matrix2 = new Matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix2->matrix[i][j] = matrix[i][j] + m.matrix[i][j];
		}
	}
	return *matrix2;
}

Matrix& Matrix::operator+(int a) {
	Matrix* matrix2 = new Matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix2->matrix[i][j] = matrix[i][j] + a;
		}
	}
	return *matrix2;
}

Matrix& operator+(int a, Matrix& m) {
	Matrix* matrix2 = new Matrix(m.n);
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; ++j) {
			matrix2->matrix[i][j] = m.matrix[i][j] + a;
		}
	}
	return *matrix2;
}

// Przeciazenia operatorow odejmowania

Matrix& Matrix::operator-(int a) {
	Matrix* matrix2 = new Matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix2->matrix[i][j] = matrix[i][j] - a;
		}
	}
	return *matrix2;
}

Matrix& operator-(int a, Matrix& m) {
	Matrix* matrix2 = new Matrix(m.n);
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; ++j) {
			matrix2->matrix[i][j] = m.matrix[i][j] - a;
		}
	}
	return *matrix2;
}

// Przeciazenia operatorow mnozenia

Matrix& Matrix::operator*(Matrix& m) {
	Matrix* matrix2 = new Matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix2->matrix[i][j] = 0;
            for (int k = 0; k < n; ++k) {
				matrix2->matrix[i][j] += matrix[i][k] * m.matrix[k][j];
			}
		}
	}
	return *matrix2;
}

Matrix& Matrix::operator*(int a) {
	Matrix* matrix2 = new Matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix2->matrix[i][j] = matrix[i][j] * a;
		}
	}
	return *matrix2;
}

Matrix& operator*(int a, Matrix& m) {
	Matrix* matrix2 = new Matrix(m.n);
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; ++j) {
			matrix2->matrix[i][j] = m.matrix[i][j] * a;
		}
	}
	return *matrix2;
}

// Przeciazenia operatorow inkrementacji i dekrementacji

Matrix& Matrix::operator++(int) {
	Matrix* matrix2 = new Matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix2->matrix[i][j] = matrix[i][j] + 1;
		}
	}
	return *matrix2;
}

Matrix& Matrix::operator--(int) {
	Matrix* matrix2 = new Matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix2->matrix[i][j] = matrix[i][j] - 1;
		}
	}
	return *matrix2;
}

// Przeciazenia operatorow przypisania

Matrix& Matrix::operator+=(int a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix[i][j] += a;
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(int a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix[i][j] -= a;
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(int a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix[i][j] *= a;
		}
	}
	return *this;
}

// Przeciazenia operatora () - wszystkie cyfry sa powiekszone o czesc calkowita podanej liczby

Matrix& Matrix::operator()(double a) {
	int b = static_cast<int>(a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
			matrix[i][j] += b;
		}
	}
	return *this;
}

// Przeciazenia operatorow strumieniowych

std::ostream& operator<<(std::ostream& o, Matrix& m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; ++j) {
			o << m.matrix[i][j] << " ";
		}
		o << std::endl;
	}
	return o;
}

// Przeciazenia operatorow porownan

bool Matrix::operator==(const Matrix& m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != m.matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool Matrix::operator>(const Matrix& m) {
	double suma1 = 0;
	double suma2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
			suma1 += matrix[i][j];
			suma2 += m.matrix[i][j];
		}
	}
	return suma1 > suma2;
}

bool Matrix::operator<(const Matrix& m) {
	double suma1 = 0;
	double suma2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
			suma1 += matrix[i][j];
			suma2 += m.matrix[i][j];
		}
	}
	return suma1 < suma2;
}

// Funkcja zwracajaca wielkosc macierzy w pliku

int getNumberOfLines(std::string filename) {
    std::fstream file;
    file.open(filename, std::ios::in);

    int n = 0;

    while (!file.eof())
    {
        std::string line;
        getline(file, line);
        n++;
    }

    file.close();

    return n;
}

// Wczytywanie macierzy z pliku tekstowego

Matrix& Matrix::wczytajZTxt(std::string nazwa_pliku) {
	std::ifstream plik(nazwa_pliku);
    if (plik.is_open()) {
	    n = getNumberOfLines(nazwa_pliku);
	    matrix = new int* [n];
        for (int i = 0; i < n; i++) {
		    matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
			    plik >> matrix[i][j];
		    }
	    }
	}
        else {
		std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
	}
	plik.close();
	return *this;
}