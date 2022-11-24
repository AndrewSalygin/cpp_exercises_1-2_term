#include <iostream>

using namespace std;

int** create_arr(int& n)
{
    int** mas = new int* [n];

    for (int i = 0; i < n; i++)
    {
        mas[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mas[i][j];
        }
    }
    return mas;
}

void delete_arr(int** arr, int& n)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    do
    {
        cout << "Введите размерность массива (NxN): " << '\n';
        cin >> n;
    } while (n < 0);

    if (n > 0)
    {
        cout << "Введите его элементы:" << '\n';
        int** arr = create_arr(n);

        bool flag;
        // столбцы
        for (int j = 0; j < n; j++)
        {
            flag = true;
            // строки
            for (int i = 0; i < n; i++)
            {
                // если есть хотя бы один полож элем
                if (arr[i][j] > 0)
                {
                    flag = false;
                    // дальше можно не проверять
                    break;
                }
            }
            // если флаг не сработал
            if (flag)
            {
                cout << "Есть столбец из отрицательных элементов" << '\n';
                delete_arr(arr, n);
                return 0;
            }
        }
        delete_arr(arr, n);
    }

    cout << "Нет столбца из отрицательных элементов" << '\n';

    return 0;
}
