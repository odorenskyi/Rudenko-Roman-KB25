#include <iostream>
#include <math.h>
#include "ModulesRudenko.h"
using namespace std;

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

