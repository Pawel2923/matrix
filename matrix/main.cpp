﻿#include <iostream>
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
    cout << m1 << endl;

    // Sprawdzenie konstruktora z dwoma parametrami
    cout << "Konstruktor z tablica:" << endl;
    int t[4] = { 1, 2, 3, 4 };
    Matrix m2(4, t);
    cout << m2 << endl;

    // Sprawdzenie konstruktora kopiującego
    cout << "Konstruktor kopiujacy:" << endl;
    Matrix copy(m1);
    cout << copy << endl;

    // Sprawdzenie alokacji
    cout << "Alokacja:" << endl;
    Matrix alo;
    alo.alokuj(4);
    alo.szachownica();
    cout << alo << endl;

    // Sprawdzenie wstawiania
    cout << "Wstawianie:" << endl;
    Matrix m3(4);
    m3.wstaw(1, 1, 5);
    cout << m3 << endl;

    // Sprawdzenie pokazywania
    cout << "Pokazywanie elementu po wspolrzednych:" << endl;
    cout << m3.pokaz(1, 1) << endl;

    cout << endl;

    // Sprawdzenie odwracania
    cout << "Odwracanie:" << endl;
    Matrix m4("a.txt");
    cout << "Oryginalna macierz:" << endl;
    cout << m4 << endl;
    cout << "Odwrocona macierz:" << endl;
    cout << m4.dowroc() << endl;

    // Sprawdzenie losowania
    cout << "Losowanie:" << endl;
    Matrix m5(4);
    m5.losuj();
    cout << m5 << endl;
    cout << "Losowanie z zakresu:" << endl;
    m5.losuj(5);
    cout << m5 << endl;

    // Sprawdzenie tworzenia macierzy diagonalnej
    cout << "Macierz diagonalna:" << endl;
    Matrix m6(4);
    int t1[4] = { 1, 2, 3, 4 };
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
    cout << "Macierz szachownica:" << endl;
    Matrix m13(4);
    m13.szachownica();
    cout << m13 << endl;

    // Sprawdzenie dodawania
    cout << "Dodawanie:" << endl;
    cout << "Matrix + Matrix:" << endl;
    Matrix macierzA("a.txt");
    cout << "A: " << endl << macierzA << endl;
    Matrix macierzB("b.txt");
    cout << "B: " << endl << macierzB << endl;
    cout << "A + B: " << endl << macierzA + macierzB << endl;
    cout << "A + int:" << endl;
    cout << macierzA + 2 << endl;
    cout << "int + A:" << endl;
    cout << 2 + macierzB << endl;

    // Sprawdzanie odejmowania
    cout << "Odejmowanie:" << endl;
    cout << "A:" << endl << macierzA << endl;
    cout << "A - int:" << endl;
    cout << macierzA - 2 << endl;
    cout << "int - A:" << endl;
    cout << 2 - macierzA << endl;

    // Sprawdzanie mnożenia
    Matrix m14("a.txt");
    cout << "Mnozenie:" << endl;
    cout << "A:" << endl << macierzA << endl;
    cout << "A * A:" << endl;
    cout << macierzA * macierzA << endl;
    cout << "A * int:" << endl;
    cout << macierzA * 2 << endl;
    cout << "int * A:" << endl;
    cout << 2 * macierzA << endl;

    // Sprawdzanie inkrementacji i dekrementacji
    cout << "Inkrementacja i dekrementacja:" << endl;
    cout << "A:" << endl << m13 << endl;
    cout << "A++:" << endl;
    cout << m13++ << endl;
    cout << "A--:" << endl;
    cout << m13-- << endl;

    // Sprawdzanie przypisania
    cout << "Przypisanie:" << endl;
    Matrix m15(4);
    m15.szachownica();
    cout << "A:" << endl << m15 << endl;
    cout << "A += 2:" << endl;
    m15 += 2;
    cout << m15 << endl;
    cout << "A -= 1:" << endl;
    m15 -= 1;
    cout << m15 << endl;
    cout << "A *= 2:" << endl;
    m15 *= 2;
    cout << m15 << endl;

    // Sprawdzenie operatora funkcyjnego
    Matrix m16(m13);
    cout << "Operator funkcyjny:" << endl;
    cout << "A:" << endl << m16 << endl;
    cout << "A(4.53):" << endl;
    cout << m16(4.53) << endl;

    // Sprawdzanie porównań
    cout << "Porownania:" << endl;
    cout << "A:" << endl << m13 << endl;
    cout << "B:" << endl << m14 << endl;
    cout << "A == B:" << endl;
    cout << (m13 == m14) << endl;
    cout << "A > B:" << endl;
    cout << (m13 > m14) << endl;
    cout << "A < B:" << endl;
    cout << (m13 < m14) << endl;

    cout << endl;
    // Sprawdzenie wczytywania z pliku
    Matrix m17;
    m17.wczytajZTxt("matrix.txt");
    cout << "Wczytywanie z pliku matrix.txt:" << endl;
    cout << m17 << endl;
    cout << "Wczytywanie z nieistniejacego pliku:" << endl;
    Matrix m18;
    m18.wczytajZTxt("matrix1.txt");
    cout << m18 << endl;

    return 0;
}