#include <iostream>
#include "ModulesRudenko.h"
using namespace std;

void run(double x, double y, double z, double expected)
{
    double result = s_calculation(x, y, z);

    cout << "Input: x=" << x << " y=" << y << " z=" << z << endl;
    cout << "Result: " << result << endl;
    cout << "Expected: " << expected << endl;

    if (abs(result - expected) < 0.01) //0.01 тому що компютер може округлити число 96.595009 и 96.59501
        cout << "Status: passed" << endl;
    else
        cout << "Status: failed" << endl;
}

int main()
{

    run(1, 2, 3, 96.595);
    run(0, 1, 2, 3);
    run(2, -2, 5, 0);
    run(1, 0, 5, 0);
    run(1, 5, 0, 0);
    run(-1, 3, 2, 728.514);
    run(4, -1, 6, -3.53514);
    run(-3, 1, -2, 2.85888);
    run(0.5, 2, 4, 96.268);
    run(100, 50, 25, 937499999.82459);
    return 0;
}
