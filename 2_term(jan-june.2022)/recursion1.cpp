#include <iostream>
using namespace std;
// алгоритм Евклида
int f(int n, int m)
{
    if (n == m)
    {
        return n;
    }
    else
    {
        if (n > m)
        {
            f(n - m, m);
        }
        else
        {
            f(n, m - n);
        }
    }
}

int main()
{
    cout << "Введите a: ";
    int a;
    cin >> a;
    cout << "Введите b: ";
    int b;
    cin >> b;
    // ищем НОД
    int del = f(a, b);
    // сокращаем дробь
    a /= del;
    b /= del;
    cout << "Полученная дробь: " << a << '/' << b;
    return 0;
}