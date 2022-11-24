#include <iostream>
#include <iomanip>

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
        cout << "Введите размерность двумерной матрицы A (NxN):" << '\n';
        cin >> n;
    } while (n < 0);

    if (n > 0)
    {
        cout << "Введите элементы матрицы A:" << '\n';
        
        // создаём матрицу
        int** matrix = create_arr(n);
        // создаём вектор
        int* vec = new int[n];

        cout << "Введите координаты вектора X: " << '\n';
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        cout << "A * X =" << '\n';
        // результирующий вектор
        int* vec_new = new int[n];
        for (int i = 0; i < n; i++)
        {
            vec_new[i] = 0;
            for (int j = 0; j < n; j++)
            {
                // умножаем строку на столбец
                vec_new[i] += matrix[i][j] * vec[j];
            }
            cout << setw(15) << vec_new[i] << '\n' << '\n';
        }

        delete_arr(matrix, n);
        delete[] vec;
        delete[] vec_new;
    }

    return 0;
}

