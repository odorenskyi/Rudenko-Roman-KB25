#include <iostream>
#include <iomanip>
#include "ModulesRudenko.h"

using namespace std;

void info()
{
    cout << "Rudenko Roman \u00A9" << endl;
}

int result(char a, char b)
{
    return (a + 1 < b + 3);
}


void print_numbers(double x, double y, double z)
{
    //виведення значення змінної x у десятковій системі числення
    cout << "x (dec) = " << x << endl;
    //виведення значення x у шістнадцятковій системі числення, оскільки виведення у hex працює тільки для цілих чисел, dec повертає потік виведення назад у десяткову систему
    cout << "x (hex) = " << hex << (int)x << dec << endl;
    //виведення значення змінної y у десятковій системі числення
    cout << "y (dec) = " << y << endl;
    //виведення значення y у шістнадцятковій системі числення
    cout << "y (hex) = " << hex << (int)y << dec << endl;
    //виведення значення змінної z у десятковій системі числення
    cout << "z (dec) = " << z << endl;
    //виведення значення z у шістнадцятковій системі числення
    cout << "z (hex) = " << hex << (int)z << dec << endl;
}

int main()
{
    double x, y, z, S;
    char a, b;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;

    cout << "Enter z: ";
    cin >> z;

    cout << "Enter symbol a: ";
    cin >> a;

    cout << "Enter symbol b: ";
    cin >> b;

    cout << endl;

    info();

    cout << "Result a + 1 < b + 3: "
         << result(a, b) << endl;

    print_numbers(x, y, z);

    S = s_calculation(x, y, z);
    cout << "S = " << S << endl;
    system("pause");
    return 0;
}
