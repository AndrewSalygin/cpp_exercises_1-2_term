#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// функция из условия
double f(double& x, int& k, double& eps, 
         double& fact, double& x_elem, int& sign)
{
    double s = 0;
    while (abs(x_elem) > eps)
    {
        s += x_elem;
        sign *= -1;
        fact *= (k + 1) * (k + 2);
        k += 2;
        x_elem = sign * (pow(x, k) / fact);
    }
    return s;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double eps, h = 0.1, a = 1, b = 2;
    cout << "Введите eps:" << '\n';
    cin >> eps;

    // знаменатель и степень
    int k;
    // чётный - отриц, нечётный - полож
    int sign;
    // слагаемое в ряду
    double x_elem;
    // факториал
    double fact;
    // счётчик
    int count = 1;
    cout << setw(4) << '№' << setw(11) << "Знач x" << setw(13) << "Знач F(x)" << setw(6) <<
        "n" << '\n';
    for (; a < b + 10e-6; a += h)
    {
        k = 0;
        sign = 1;
        x_elem = 1;
        fact = 1;
        double f_x = f(a, k, eps, fact, x_elem, sign);
        cout << setw(4) << count++ << setw(10) << a << setw(14) << f_x << setw(6) << k / 2 << '\n';
    }

    return 0;
}

