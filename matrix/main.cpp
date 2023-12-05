#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix m1(3);
    m1.szachownica();
    cout << m1 << endl;

    // Sprawdzenie dodawania
    Matrix m2(3);
    m2.szachownica();
    cout << m2 << endl;
    cout << m1 + m2 << endl;
    cout << m1 + 2 << endl;
    cout << 2 + m1 << endl;

    return 0;
}