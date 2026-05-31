#include <iostream>
#include <cstring>
#include <windows.h>
#include <locale.h>

#include "struct_type_project_4.h"
#include "Modules_Bureiko.h"
#include "Modules_Rudenko.h"
#include "Modules_Primak.h"

using namespace std;

int main() {
    // Налаштування української локалі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukrainian");

    RouteNode* head = NULL;

    // автоматичне завантаження даних
    load_from_binary(head, "routes.dat");

    int choice;

    do {
        cout << "\n========== АС КРОПИВНИЦЬКИЙ ==========\n";
        cout << "1. Показати розклад\n";
        cout << "2. Пошук рейсу\n";
        cout << "3. Додати рейс\n";
        cout << "4. Видалити рейс\n";
        cout << "5. Вихід\n";
        cout << "Ваш вибір: ";

        cin >> choice;

        switch (choice) {
            case 1:
                print_schedule(head);
                break;

            case 2: {
                char station[100];

                cout << "Введіть назву станції або частину маршруту: ";
                cin.ignore();
                cin.getline(station, 100);

                search_route(head, station);
                break;
            }

            case 3:
                add_route(head);
                break;

            case 4: {
                char routeNum[15];

                cout << "Введіть номер рейсу для видалення: ";
                cin.ignore();
                cin.getline(routeNum, 15);

                delete_route(head, routeNum);
                break;
            }

            case 5:
                save_to_binary(head, "routes.dat");
                cout << "\nДані успішно збережено.\n";
                cout << "Завершення роботи програми...\n";
                break;

            default:
                cout << "Невірний вибір! Спробуйте ще раз.\n";
        }

    } while (choice != 5);

    return 0;
}
