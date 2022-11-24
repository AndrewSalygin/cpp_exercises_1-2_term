#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите кол-во элементов:" << '\n';
    int n;
    do
    {
        cin >> n;
    } while (n < 0);

    // массив для хранения посл-ти
    double* a = new double[n];

    double eps = 10e-6;

    double min_elem;
    int min_elem_i;
    if (n > 0)
    {
        cout << "Введите последовательность:" << '\n';
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // обозначаем нач-ый минимум
        min_elem = a[0];
        min_elem_i = 0;
        for (int i = 1; i < n; i++)
        {
            // ищем минимум
            if (a[i] + eps < min_elem)
            {
                min_elem = a[i];
                min_elem_i = i;
            }
        }
        cout << "Номер первого минимального элемента: " << min_elem_i + 1 << '\n';
    }

    delete[] a;
    return 0;
}
