#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    do
    {
        cout << "Введите кол-во элементов:" << '\n';
        cin >> n;
    } while (n < 0);

    if (n > 0)
    {
        int* arr = new int[n];

        cout << "Введите элементы:" << '\n';
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int temp;

        // сортируем
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[i])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        // убираем повторяющиеся элементы
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != arr[i + 1])
            {
                arr[k] = arr[i];
                k++;
            }
        }

        // проверяем последний элемент
        if (arr[n - 1] != arr[n - 2])
        {
            arr[k] = arr[n - 1];
        }

        // Вывод
        for (int i = 0; i < k; i++)
        {
            cout << arr[i] << ' ';
        }
        delete[] arr;
    }

    return 0;
}
