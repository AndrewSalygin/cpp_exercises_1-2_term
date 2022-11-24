#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите координаты точки (x, y):" << '\n';
    double x, y;
    cin >> x >> y;

    // если входит в область
    if ((pow(x, 2) + pow(y, 2) > 9) and (pow(x, 2) + pow(y, 2) < 49))
    {
        cout << "Да";
    }
    // если точка находится на границе
    else if ((pow(x, 2) + pow(y, 2) == 9) or (pow(x, 2) + pow(y, 2) == 49))
    {
        cout << "На границе";
    }
    // если точка не лежит в области
    else
    {
        cout << "Нет";
    }

    return 0;
}
