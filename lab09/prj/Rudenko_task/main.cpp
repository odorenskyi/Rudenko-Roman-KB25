#include <iostream>
#include "ModulesRudenko.h"
using namespace std;

int main()
{
    char choice;
    char exit;

    do
    {
        cout << "Введіть символ (*, 5, 4, 3): ";
        cin >> choice;

        if (choice == '*')
        {
            double x, y, z;
            cout << "Введіть x, y, z: ";
            cin >> x >> y >> z;

            double result = s_calculation(x, y, z);
            cout << "Результат: " << result << endl;
        }
        else if (choice == '5')
        {
            int b;
            cout << "Введіть бал Бофорта: ";
            cin >> b;

            cout << "Результат: " << task9_1(b) << endl;
        }
        else if (choice == '4')
        {
            int h;
            cout << "Введіть обхват голови (мм): ";
            cin >> h;

            cout << "Результат: " << task9_2(h) << endl;
        }
        else if (choice == '3')
        {
            int n;
            cout << "Введіть число: ";
            cin >> n;

            cout << "Результат: " << task9_3(n) << endl;
        }
        else
        {
            cout << "Помилка: невірний символ!" << endl;
        }

        cout << "Вийти? (t/T/с): ";
        cin >> exit;

    } while (exit != 't' && exit != 'T' && exit != 'с');

    return 0;
}
