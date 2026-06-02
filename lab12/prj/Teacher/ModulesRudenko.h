#ifndef MODULESRUDENKO_H_INCLUDED
#define MODULESRUDENKO_H_INCLUDED

#include <string>
using namespace std;

// Лаба 8-10
double s_calculation(double x, double y, double z);
std::string task9_1(int b);
std::string task9_2(int h);
int task9_3(int n);
void task10_1(string inputFileName, string outputFileName);
void task10_2(string fileName);
void task10_3(string fileName, double x, double y, double z, int b);

// Лаба 12
class ClassLab12_Rudenko
{
private:

    double length;       // довжина планшета
    double width;        // ширина планшета
    double height;       // товщина планшета

public:

    ClassLab12_Rudenko(double l = 1,
                       double w = 1,
                       double h = 1);      // конструктор

    void setDimensions(double l = 1,
                       double w = 1,
                       double h = 1);      // зміна параметрів

    double getLength() const;              // отримати довжину

    double getWidth() const;               // отримати ширину

    double getHeight() const;              // отримати товщину

    double getSurfaceArea() const;         // обчислити площу поверхні
};

// ===== Реалізація =====

ClassLab12_Rudenko::ClassLab12_Rudenko(
        double l,
        double w,
        double h)
{
    length = l;
    width = w;
    height = h;
}

void ClassLab12_Rudenko::setDimensions(
        double l,
        double w,
        double h)
{
    length = l;
    width = w;
    height = h;
}

double ClassLab12_Rudenko::getLength() const
{
    return length;
}

double ClassLab12_Rudenko::getWidth() const
{
    return width;
}

double ClassLab12_Rudenko::getHeight() const
{
    return height;
}

double ClassLab12_Rudenko::getSurfaceArea() const
{
    return 2 * (length * width +
                length * height +
                width * height);
}

#endif // MODULESRUDENKO_H_INCLUDED
