#include <iostream>
#include <string>
#include "ModulesRudenko.h"

using namespace std;

void test9_1(string i, int b, string expected)
{
    string actual = task9_1(b);

    cout << i << endl;
    cout << "Вхідні дані: b = " << b << endl;
    cout << "Очікуваний результат: " << expected << endl;
    cout << "Фактичний результат: " << actual << endl;

    if (actual == expected)
        cout << "Статус: passed" << endl;
    else
        cout << "Статус: failed" << endl;

    cout << "------------------------------" << endl;
}

void test9_2(string i, int h, string expected)
{
    string actual = task9_2(h);

    cout << i << endl;
    cout << "Вхідні дані: h = " << h << endl;
    cout << "Очікуваний результат: " << expected << endl;
    cout << "Фактичний результат: " << actual << endl;

    if (actual == expected)
        cout << "Статус: passed" << endl;
    else
        cout << "Статус: failed" << endl;

    cout << "------------------------------" << endl;
}

void test9_3(string i, int n, int expected)
{
    int actual = task9_3(n);

    cout << i << endl;
    cout << "Вхідні дані: n = " << n << endl;
    cout << "Очікуваний результат: " << expected << endl;
    cout << "Фактичний результат: " << actual << endl;

    if (actual == expected)
        cout << "Статус: passed" << endl;
    else
        cout << "Статус: failed" << endl;

    cout << "------------------------------" << endl;
}

int main()
{
    cout << "Модульне тестування функцій 9.1 - 9.3" << endl;

    cout << endl << "TS_9_1" << endl;
    test9_1("ТС-01", 0, "< 0.3 м/с");
    test9_1("ТС-02", 1, "0.3 - 1.5 м/с");
    test9_1("ТС-03", 5, "8.0 - 10.7 м/с");
    test9_1("ТС-04", 8, "17.2 - 20.7 м/с");
    test9_1("ТС-05", 12, ">= 32.7 м/с");
    test9_1("ТС-06", -1, "Помилка: некоректне значення");
    test9_1("ТС-07", 13, "Помилка: некоректне значення");
    test9_1("ТС-08", 10, "24.5 - 28.4 м/с");
    test9_1("ТС-09", 4, "5.5 - 7.9 м/с");
    test9_1("ТС-10", 3, "3.4 - 5.4 м/с");

    cout << endl << "TS_9_2" << endl;
    test9_2("ТС-01", 530, "XS");
    test9_2("ТС-02", 540, "XS");
    test9_2("ТС-03", 550, "S");
    test9_2("ТС-04", 560, "S");
    test9_2("ТС-05", 570, "M");
    test9_2("ТС-06", 580, "M");
    test9_2("ТС-07", 590, "L");
    test9_2("ТС-08", 600, "L");
    test9_2("ТС-09", 490, "S");
    test9_2("ТС-10", 470, "Помилка: розмір не визначено");

    cout << endl << "TS_9_3" << endl;
    test9_3("ТС-01", 0, 1);
    test9_3("ТС-02", 1, 0);
    test9_3("ТС-03", 2, 1);
    test9_3("ТС-04", 5, 1);
    test9_3("ТС-05", 10, 2);
    test9_3("ТС-06", 1023, 0);
    test9_3("ТС-07", 4096, 12);
    test9_3("ТС-08", 8191, 13);
    test9_3("ТС-09", 8999, 7);
    test9_3("ТС-10", -1, -1);

    return 0;
}
