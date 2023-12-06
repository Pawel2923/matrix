#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    // Sprawdzenie wszystkich metod klasy Matrix
    // Sprawdzenie konstruktora domyślnego
    cout << "Konstruktor domyslny:" << endl;
    Matrix m0;
    cout << m0 << endl;

    // Sprawdzenie konstruktora z parametrem
    cout << "Konstruktor z parametrem:" << endl;
    Matrix m1(4);
    m1.szachownica();
    cout << m1 << endl;

    // Sprawdzenie alokacji
    cout << "Alokacja:" << endl;
    Matrix m2;
    m2.alokuj(4);
    m2.szachownica();
    cout << m2 << endl;

    // Sprawdzenie wstawiania
    cout << "Wstawianie:" << endl;
    Matrix m3(4);
    m3.wstaw(1, 1, 5);
    cout << m3 << endl;

    // Sprawdzenie pokazywania
    cout << "Pokazywanie:" << endl;
    cout << m3.pokaz(1, 1) << endl;

    // Sprawdzenie odwracania
    cout << "Odwracanie:" << endl;
    Matrix m4(4);
    m4.szachownica();
    cout << m4 << endl;
    cout << m4.dowroc() << endl;

    // Sprawdzenie losowania
    cout << "Losowanie:" << endl;
    Matrix m5(4);
    m5.losuj();
    cout << m5 << endl;
    m5.losuj(5);
    cout << m5 << endl;

    // Sprawdzenie tworzenia macierzy diagonalnej
    cout << "Macierz diagonalna:" << endl;
    Matrix m6(4);
    int t[4] = { 1, 2, 3, 4 };
    m6.diagonalna(t);
    cout << m6 << endl;

    // Sprawdzenie tworzenia macierzy diagonalnej k
    cout << "Macierz diagonalna k:" << endl;
    Matrix m7(4);
    int t2[4] = { 1, 2, 3, 4 };
    m7.diagonalna_k(2, t2);
    cout << m7 << endl;

    // Sprawdzenie tworzenia macierzy kolumny
    cout << "Macierz kolumna:" << endl;
    Matrix m8(4);
    int t3[4] = { 1, 2, 3, 4 };
    m8.kolumna(2, t3);
    cout << m8 << endl;

    // Sprawdzenie tworzenia macierzy wiersza
    cout << "Macierz wiersz:" << endl;
    Matrix m9(4);
    int t4[4] = { 1, 2, 3, 4 };
    m9.wiersz(2, t4);
    cout << m9 << endl;

    // Sprawdzenie tworzenia macierzy przekątnej
    cout << "Macierz przekatna:" << endl;
    Matrix m10(4);
    m10.przekatna();
    cout << m10 << endl;

    // Sprawdzenie tworzenia macierzy pod przekątną
    cout << "Macierz pod przekatna:" << endl;
    Matrix m11(4);
    m11.pod_przekatna();
    cout << m11 << endl;

    // Sprawdzenie tworzenia macierzy nad przekątną
    cout << "Macierz nad przekatna:" << endl;
    Matrix m12(4);
    m12.nad_przekatna();
    cout << m12 << endl;

    // Sprawdzenie tworzenia macierzy szachownicy
    Matrix m13(4);
    m13.szachownica();
    cout << m13 << endl;

    // Sprawdzenie dodawania
    cout << "Dodawanie:" << endl;
    Matrix m14(4);
    m14.szachownica();
    cout << m14 << endl;
    cout << m13 + m14 << endl;
    cout << m13 + 2 << endl;
    cout << 2 + m13 << endl;

    // Sprawdzanie odejmowania
    cout << "Odejmowanie:" << endl;
    cout << m13 - 2 << endl;
    cout << 2 - m13 << endl;

    // Sprawdzanie mnożenia
    cout << "Mnozenie:" << endl;
    cout << m13 * m14 << endl;
    cout << m13 * 2 << endl;
    cout << 2 * m13 << endl;

    // Sprawdzanie inkrementacji i dekrementacji
    cout << "Inkrementacja i dekrementacja:" << endl;
    cout << m13++ << endl;
    cout << m13-- << endl;

    // Sprawdzanie przypisania
    cout << "Przypisanie:" << endl;
    Matrix m15(4);
    m15.szachownica();
    cout << m15 << endl;
    m15 += 2;
    cout << m15 << endl;
    m15 -= 1;
    cout << m15 << endl;
    m15 *= 2;
    cout << m15 << endl;

    // Sprawdzenie operatora funkcyjnego
    Matrix m16(m13);
    cout << "Operator funkcyjny:" << endl;
    cout << m16(4.53) << endl;

    // Sprawdzanie porównań
    cout << "Porownania:" << endl;
    cout << (m13 == m14) << endl;
    cout << (m13 > m14) << endl;
    cout << (m13 < m14) << endl;

    return 0;
}