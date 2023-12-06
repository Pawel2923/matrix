#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix m1(3);
    m1.szachownica();
    cout << m1 << endl;

    // Sprawdzenie dodawania
    cout << "Dodawanie:" << endl;
    Matrix m2(3);
    m2.szachownica();
    cout << m2 << endl;
    cout << m1 + m2 << endl;
    cout << m1 + 2 << endl;
    cout << 2 + m1 << endl;

    // Sprawdzanie odejmowania
    cout << "Odejmowanie:" << endl;
    cout << m1 - 2 << endl;
    cout << 2 - m1 << endl;

    // Sprawdzanie mnożenia
    cout << "Mnozenie:" << endl;
    cout << m1 * m2 << endl;
    cout << m1 * 2 << endl;
    cout << 2 * m1 << endl;

    // Sprawdzanie inkrementacji i dekrementacji
    cout << "Inkrementacja i dekrementacja:" << endl;
    cout << m1++ << endl;
    cout << m1-- << endl;

    // Sprawdzanie przypisania
    cout << "Przypisanie:" << endl;
    Matrix m3(3);
    m3.szachownica();
    cout << m3 << endl;
    m3 += 2;
    cout << m3 << endl;
    m3 -= 1;
    cout << m3 << endl;
    m3 *= 2;
    cout << m3 << endl;

    // Sprawdzanie porównań
    cout << "Porownania:" << endl;
    cout << (m1 == m2) << endl;
    cout << (m1 > m2) << endl;
    cout << (m1 < m2) << endl;

    return 0;
}