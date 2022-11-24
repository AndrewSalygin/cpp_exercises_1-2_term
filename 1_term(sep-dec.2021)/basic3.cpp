#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// если треугольник существует
void triangle_exists(int a, int b, int c)
{
    if ((a == b) and (a == c) and (b == c))
    {
        cout << "Треугольник равносторонний";
    }
    else
    {
        cout << "Треугольник не равносторонний";
    }
}

void triangle_not_exists()
{
    cout << "Треугольник не существует";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите длину первой стороны:" << endl;
    double a;
    cin >> a;
    cout << "Введите длину второй стороны:" << endl;
    double b;
    cin >> b;
    cout << "Введите длину третьей стороны:" << endl;
    double c;
    cin >> c;
    // условие существования треугольника
    ((a + b > c) and (a + c > b) and (c + b > a)) ? triangle_exists(a, b, c) : triangle_not_exists();
    return 0;
}
