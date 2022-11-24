#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f1(double x, double a, double b)
{
    return a + b * x;
}
double f2(double x, double a, double b)
{
    return b - a * x;
}
double f3(double x, double a, double b)
{
    return a * b * x;
}

int main()
{
    double a, b, h, e = 1e-6;
    cin >> a >> b >> h;
    for (double x = a; x < (b + e); x += h)
    {
        if (x + e < 93)
        {
            cout << fixed << setprecision(6) << x << " " << f1(x, a, b) << endl;
        }
        else if (x > 120 + e)
        {
            cout << fixed << setprecision(6) << x << " " << f3(x, a, b) << endl;
        }
        // 93 <= x <= 120
        else
        {
            cout << fixed << setprecision(6) << x << " " << f2(x, a, b) << endl;
        }
    }
    return 0;
}
