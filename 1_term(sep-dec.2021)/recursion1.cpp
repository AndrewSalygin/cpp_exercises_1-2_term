#include <iostream>

using namespace std;

int sum_del(int &n)
{
    int sum = 0;
    int d = 1;
    // идём до корня числа
    while (d * d < n)
    {
        // если число делитель, то добавляем
        // сразу его парный делитель
        if (n % d == 0)
        {
            sum += d + (n / d);
        }
        d++;
    }

    // чтобы два раза не сложить один и тот же
    // делитель, проверяем отдельно
    if (d * d == n)
    {
        sum += d;
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    do
    {
        cout << "Введите два натуральных числа отрезка [a, b]: " << '\n';
        cin >> a >> b;
    } while ((a <= 0 || b <= 0) || (a > b));

    int max_sum = 0;
    int sum = 0;
    int* arr = new int[b - a + 1];
    // кол-во макс сумм
    int k = 0;

    for (; a <= b; a++)
    {
        sum = sum_del(a);
        if (sum > max_sum)
        {
            k = 0;
            arr[k] = a;
            max_sum = sum;
        }
        // если есть несколько максимальных сумм
        else if (sum == max_sum)
        {
            k++;
            arr[k] = a;
        }
    }

    for (int i = 0; i <= k; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n'; 

    delete[] arr;
    return 0;
}
