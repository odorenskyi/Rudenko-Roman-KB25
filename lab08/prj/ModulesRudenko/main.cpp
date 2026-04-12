#include <iostream>
#include <math.h>
#include "ModulesRudenko.h"
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

//ЗАДАЧА 9.1
string task9_1(int b)
{
    switch (b) //b - бал Бофорта
    {
        case 0:  return "< 0.3 м/с";
        case 1:  return "0.3 - 1.5 м/с";
        case 2:  return "1.6 - 3.3 м/с";
        case 3:  return "3.4 - 5.4 м/с";
        case 4:  return "5.5 - 7.9 м/с";
        case 5:  return "8.0 - 10.7 м/с";
        case 6:  return "10.8 - 13.8 м/с";
        case 7:  return "13.9 - 17.1 м/с";
        case 8:  return "17.2 - 20.7 м/с";
        case 9:  return "20.8 - 24.4 м/с";
        case 10: return "24.5 - 28.4 м/с";
        case 11: return "28.5 - 32.6 м/с";
        case 12: return ">= 32.7 м/с";

        default: return "Помилка: некоректне значення"; //Якщо значення не входить у діапазон 0-12
    }
}


//ЗАДАЧА 9.2
std::string task9_2(int h)
{
    if (h < 480 || h > 620) //h - обхват голови в мм, перевірка на допустимий діапазон
    {
        return "Помилка: розмір не визначено";
    }

    if (h >= 530 && h <= 540) //Перевірка розмірів для дорослих і дітей
    {
        return "XS";
    }
    else if ((h >= 550 && h <= 560) || (h >= 480 && h <= 490))
    {
        return "S";
    }
    else if ((h >= 570 && h <= 580) || (h >= 500 && h <= 510))
    {
        return "M";
    }
    else if ((h >= 590 && h <= 600) || (h >= 520 && h <= 530))
    {
        return "L";
    }
    else if (h >= 610 && h <= 620)
    {
        return "XL";
    }

    return "Помилка: розмір не визначено";
}


//ЗАДАЧА 9.3
int task9_3(int n)
{
    if (n < 0 || n > 8999)//n - число від 0 до 8999, перевірка діапазону
    {
        return -1; //Помилка
    }

    //Окремий випадок для 0
    if (n == 0)
    {
        return 1; //Двійковий запис "0" - один нуль
    }

    //Визначаємо біт D10 (11-й біт)
    int d10 = (n >> 10) & 1;

    int count = 0; //Лічильник
    int temp = n;  //Копія числа

    while (temp > 0)//Цикл перебору всіх бітів числа
    {
        int bit = temp & 1; //Беремо останній біт (0 або 1)

        //Якщо D10 = 0 - рахуємо нулі
        if (d10 == 0)
        {
            if (bit == 0)
            {
                count++;
            }
        }
        //Якщо D10 = 1 - рахуємо одиниці
        else
        {
            if (bit == 1)
            {
                count++;
            }
        }
        temp >>= 1; //Зсуваємо число вправо (ділимо на 2)
    }
    return count; //Повертаємо результат
}

double s_calculation(double x, double y, double z)
{
    double s;
    if (x + y == 0){
        cout << "Помилка: ділення на нуль!" << endl;
        return 0;
    }
    if (abs((y*z)/(x+y)) == 0){
        cout << "Помилка: ділення на нуль!" << endl;
        return 0;
    }
    s = (sin(x)/sqrt(abs((y*z)/(x+y)))) + 3*pow(y,5);
    return s;
}

//ЗАДАЧА 10.1
void task10_1(string inputFileName, string outputFileName) //функція приймає ім'я вхідного і вихідного файлу
{
    ifstream in(inputFileName); //Відкриваємо вхідний файл для читання
    ofstream out(outputFileName); //Відкриваємо (або створюємо) вихідний файл для запису

    if (!in.is_open()) //Якщо файл не відкрився
    {
        cout << "Помилка відкриття файлу" << endl;
        return;
    }

    string word; //Змінна для слова
    in >> word; //Зчитуємо слово з файлу

    int count = 0; //Лічильник літер "у"

    for (int i = 0; i < word.length(); i++) //Проходимо по кожній букві слова
    {
        if (word[i] == 'у' || word[i] == 'У') //Якщо літера "у"
        {
            count++; //Збільшуємо лічильник
        }
    }

    string text = "Про себе не кажи недобрих слів Бо має сказане таємну силу Кажи Я сильний впевнений щасливий І буде саме так як ти хотів";

    bool found = false; //Змінна для перевірки

    if (text.find(word) != string::npos) //Шукаємо слово в тексті
    {
        found = true; //Якщо знайшли
    }

    out << "Автор: Руденко" << endl; //Записуємо автора
    out << "Кількість у: " << count << endl; //Записуємо кількість

    if (found) //Якщо слово знайдено
    {
        out << "Слово є у тексті" << endl;
    }
    else
    {
        out << "Слова немає" << endl;
    }

    in.close(); //Закриваємо вхідний файл
    out.close(); //Закриваємо вихідний файл
}

//ЗАДАЧА 10.2
void task10_2(string fileName) //Функція приймає ім'я файлу
{
    ifstream in(fileName); //Відкриваємо файл для читання

    if (!in.is_open()) //Якщо не відкрився
    {
        cout << "Помилка відкриття файлу" << endl;
        return;
    }

    string word; //Змінна для слова
    in >> word; //Зчитуємо слово

    in.close(); //Закриваємо файл

    ofstream out(fileName, ios::app); //Відкриваємо файл для дописування

    if (word.length() > 0) //Якщо слово не пусте
    {
        out << "Перша літера: " << word[0] << endl;
        out << "Остання літера: " << word[word.length() - 1] << endl;
    }

    time_t now = time(0); //Беремо поточний час

    out << "Дата і час: " << ctime(&now) << endl; //Записуємо дату і час

    out.close(); //Закриваємо файл
}

// ЗАДАЧА 10.3
void task10_3(string fileName, double x, double y, double z, int b) //Функція приймає файл і числа
{
    ofstream out(fileName, ios::app); //Відкриваємо файл для дописування

    double result = s_calculation(x, y, z); //Викликаємо функцію з 8 лабораторної

    out << "Результат: " << result << endl; //Записуємо результат

    string binary = ""; //Рядок для двійкового числа

    if (b == 0) //Якщо число 0
    {
        binary = "0"; //Двійковий код 0
    }

    while (b > 0)
    {
        binary = char('0' + (b % 2)) + binary; //Додаємо 0 або 1
        b = b / 2; //Ділимо число на 2
    }

    out << "Двійкове: " << binary << endl; //Записуємо результат

    out.close(); //Закриваємо файл
}

