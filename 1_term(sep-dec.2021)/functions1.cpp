#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// возвращает большее число
double d(double a, double b)
{
    double ans;
    ans = (a > b) ? 1 : 2;
    return ans;
}

// возвращает расстояние между двумя точками
double f(double x1, double y1, double x2, double y2)
{
    return sqrt((pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double x1, y1, x2, y2, x3, y3;
    cout << "Введите 1-й точки коор-ты (x, y):" << '\n';
    cin >> x1 >> y1;
    cout << "Введите 2-й точки коор-ты (x, y):" << '\n';
    cin >> x2 >> y2;
    cout << "Введите 3-й точки коор-ты (x, y):" << '\n';
    cin >> x3 >> y3;

    // вычисляем расстояние точек от начала координат
    double dist1 = func(0, 0, x1, y1);
    double dist2 = func(0, 0, x2, y2);
    double dist3 = func(0, 0, x3, y3);

    // если расстояния одинаковые
    if (dist1 == dist2 && dist2 == dist3)
    {
        cout << "Все точки равноудалены";
        return 0;
    }

    // ищем наибольшее расстояние
    string ans = (max(dist1, dist2) == 1) ? "Первая" : "Вторая";
    double max1 = (max(dist1, dist2) == 1) ? dist1 : dist2;
    ans = (max(max1, dist3) == 1) ? ans : "Третья";

    cout << ans;
    return 0;
}
