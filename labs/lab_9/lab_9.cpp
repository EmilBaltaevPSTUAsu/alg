#include <iostream>
#include "Set.h"

int main()
{
    system("chcp 1251");

    cout << "\nСоздание двух множеств\n";
    int n1, n2;
    cout << "n1? "; cin >> n1;
    Set s1(n1);
    cin >> s1;
    cout << "n2 "; cin >> n2;
    Set s2(n2);
    cin >> s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cout << "\nГенерация исключений с помощью стандартных типов\n";
    try {
        cout << "s1[2] = " << s1[2] << endl;
        cout << "s1[6] = " << s1[6] << endl;
        cout << "s1[10] = " << s1[10] << endl;
    }
    catch (int) {
        cout << "Ошибка: не верный индекс" << endl;
    }

    cout << "\nГенарция исключений с помощью собственного типа\n";
    try {
        cout << "before s2--: " << s2 << endl;
        s2--;
        cout << "after s2--: " << s2 << endl;
        s2--;
        cout << "after s2--: " << s2 << endl;
    }
    catch (error& err) {
        err.what();
    }
}