#include <iostream>
#include <cmath>

using namespace std;

// создаём структуру point
struct point
{
    double x, y;
};

// фун-я вычисляющая расс-е между 2-мя точками
double dist(point &p1, point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите кол-во точек:" << '\n';
    int n;
    do
    {
        cin >> n;
    } while (n <= 0);

    // создаём указатель типа point
    point *points = new point[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Введите коор-ты для " << i + 1 << " точки (x, y):" << '\n';
        cin >> points[i].x >> points[i].y;
    }

    double s;
    double min_dist = 0;

    // ищем первичный минимум
    int i_min = 0;
    for (int j = 0; j < n; j++)
    {
        min_dist += dist(points[0], points[j]);
    }

    // ищем минимум
    for (int i = 0; i < n; i++)
    {
        s = 0;
        // считаем сумму расст-ний от i точки до остальных
        for (int j = 0; j < n; j++)
        {
            s += dist(points[i], points[j]);
        }
        if (s < min_dist)
        {
            min_dist = s;
            i_min = i;
        }
    }

    cout << "Точка, сумма расстояний от которой " <<
        "до остальных минимальна: " << i_min + 1 << "-я\n";
    return 0;
}
