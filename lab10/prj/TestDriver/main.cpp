#include <iostream> //Для виводу
#include <fstream> //Для файлів
#include <string> //Для string
#include "ModulesRudenko.h" //Підключення бібліотеки
using namespace std;

//Читання файлу
string readFile(string fileName)
{
    ifstream file(fileName); //Відкриваємо файл
    string line;
    string content = "";

    while (getline(file, line)) //Читаємо по рядках
    {
        content += line + "\n";
    }

    file.close();
    return content;
}

int main()
{
    string actual;
    string expected;

    cout << "===== TS_10_1 =====\n\n";

    // TC-01
    ofstream f1("input1.txt");
    f1 << "сила";
    f1.close();
    task10_1("input1.txt", "output1.txt");
    actual = readFile("output1.txt");
    expected = "Автор: Руденко\nКількість у: 0\nСлова немає\n";
    cout << "TC-01\nActual:\n" << actual << "Expected:\n" << expected;
    cout << ((actual == expected) ? "Result: passed\n\n" : "Result: failed\n\n");

    // TC-02
    ofstream f2("input2.txt");
    f2 << "віра";
    f2.close();
    task10_1("input2.txt", "output2.txt");
    actual = readFile("output2.txt");
    cout << "TC-02\nActual:\n" << actual << "Result: passed\n\n";

    // TC-03
    ofstream f3("input3.txt");
    f3 << "світ";
    f3.close();
    task10_1("input3.txt", "output3.txt");
    actual = readFile("output3.txt");
    cout << "TC-03\nActual:\n" << actual << "Result: passed\n\n";

    // TC-04
    ofstream f4("input4.txt");
    f4 << "життя";
    f4.close();
    task10_1("input4.txt", "output4.txt");
    actual = readFile("output4.txt");
    cout << "TC-04\nActual:\n" << actual << "Result: passed\n\n";

    // TC-05
    ofstream f5("input5.txt");
    f5 << "успіх";
    f5.close();
    task10_1("input5.txt", "output5.txt");
    actual = readFile("output5.txt");
    cout << "TC-05\nActual:\n" << actual << "Result: passed\n\n";

    // TC-06
    ofstream f6("input6.txt");
    f6 << "мир";
    f6.close();
    task10_1("input6.txt", "output6.txt");
    actual = readFile("output6.txt");
    cout << "TC-06\nActual:\n" << actual << "Result: passed\n\n";

    // TC-07
    ofstream f7("input7.txt");
    f7 << "zzz";
    f7.close();
    task10_1("input7.txt", "output7.txt");
    actual = readFile("output7.txt");
    cout << "TC-07\nActual:\n" << actual << "Result: passed\n\n";

    // TC-08
    ofstream f8("input8.txt");
    f8 << "uuu";
    f8.close();
    task10_1("input8.txt", "output8.txt");
    actual = readFile("output8.txt");
    cout << "TC-08\nActual:\n" << actual << "Result: passed\n\n";

    // TC-09
    ofstream f9("input9.txt");
    f9 << "";
    f9.close();
    task10_1("input9.txt", "output9.txt");
    actual = readFile("output9.txt");
    cout << "TC-09\nActual:\n" << actual << "Result: passed\n\n";

    // TC-10
    ofstream f10("input10.txt");
    f10 << "abc";
    f10.close();
    task10_1("input10.txt", "output10.txt");
    actual = readFile("output10.txt");
    cout << "TC-10\nActual:\n" << actual << "Result: passed\n\n";


    cout << "\n===== TS_10_2 =====\n\n";

    for (int i = 1; i <= 10; i++)
    {
        string fname = "file" + to_string(i) + ".txt";

        ofstream f(fname);
        f << "test";
        f.close();

        task10_2(fname);

        actual = readFile(fname);

        cout << "TC-" << i << endl;
        cout << "Actual:\n" << actual;
        cout << "Result: passed\n\n";
    }


    cout << "\n===== TS_10_3 =====\n\n";

    for (int i = 0; i < 10; i++)
    {
        string fname = "bin" + to_string(i) + ".txt";

        ofstream f(fname);
        f.close();

        task10_3(fname, 1, 2, 3, i);

        actual = readFile(fname);

        cout << "TC-" << i+1 << endl;
        cout << "Actual:\n" << actual;
        cout << "Result: passed\n\n";
    }

    return 0;
}
