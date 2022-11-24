#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double eps;
    cout << "Введите точность e (e > 0):" << endl;
    cin >> eps;
    if (eps > 0)
    {
        double sum = 0;
        double a = 1;
        int i = 1;
	 // пока очередной член больше eps
        while (abs(a) > eps)
        {
            a = 1. / (i * (i + 1));
            sum += a;
            i++;
        }
        cout << sum << endl;
    }
    return 0;
}
