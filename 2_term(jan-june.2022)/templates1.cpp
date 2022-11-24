#include <iostream>
#include <iomanip>
using namespace std;
const double EPS = 10e-18;
template < typename T>
    T **create_array(int n, int m)
    {
        T **arr = new T *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new T[m];
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        return arr;
    }

template < typename T>
    void print_array(T **arr, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << setprecision(10) << arr[i][j] << ' ';
            }

            cout << endl;
        }
    }

template < typename T>
    void delete_array(T **arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }

template < typename T>
    int comparison(T elem, int a, int b)
    {
        if ((elem > a + EPS) && (elem + EPS < b))
        {
            return 1;
        }

        return 0;
    }

int main()
{
    cout << "Введите размер массива (n, m):" << endl;
    int n, m;
    cin >> n >> m;
    cout << "Введите интервал (a, b):" << endl;
    int a, b;
    cin >> a >> b;
    cout << "Введите элементы массива:" << endl;
    int **arr = create_array<int> (n, m);
    // Количество элементов
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            k += comparison(arr[i][j], a, b);
        }
    }

    print_array(arr, n, m);
    cout << "Количество элементов входящих в (a, b): " << k;
    delete_array(arr, n);
    return 0;
}