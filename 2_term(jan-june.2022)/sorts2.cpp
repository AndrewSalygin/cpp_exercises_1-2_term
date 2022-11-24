#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int **create_array(int n, ifstream &in)
{
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        int *arr_m = new int[n];
        for (int j = 0; j < n; j++)
        {
            in >> arr_m[j];
        }

        arr[i] = arr_m;
    }

    return arr;
}

void delete_array(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}

bool comparator(int num1, int num2)
{
    return num1 < num2;
}

// QUICK SORT   //
////////////////////////////////////////////////
vector<int> partition(int **arr, vector<int> begin, vector<int> end, int n, int iter)
{
    int pivot = arr[begin[0]][begin[1]];
    int count = 0;
    // ищем место для pivot
    for (int i = begin[0] + 1, j = begin[1] - 1; i <= end[0] && j >= end[1]; i++, j--)
    {
        if (arr[i][j] <= pivot)
        {
            count++;
        }
    }

    // перемещаем pivot на его место
    vector<int> pivotIndex;
    pivotIndex.push_back(begin[0] + count);
    pivotIndex.push_back(begin[1] - count);
    swap(arr[pivotIndex[0]][pivotIndex[1]], arr[begin[0]][begin[1]]);
    // Сортируем левую и правую части
    vector<int> l;
    l.push_back(begin[0]);
    l.push_back(begin[1]);
    vector<int> r;
    r.push_back(end[0]);
    r.push_back(end[1]);
    while (l[0] < pivotIndex[0] && l[1] > pivotIndex[1] &&
        r[0] > pivotIndex[0] && r[1] < pivotIndex[1])
    {
        while (arr[l[0]][l[1]] <= pivot)
        {
            l[0]++;
            l[1]--;
        }

        while (arr[r[0]][r[1]] > pivot)
        {
            r[0]--;
            r[1]++;
        }

        if (l[0] < pivotIndex[0] && l[1] > pivotIndex[1] &&
            r[0] > pivotIndex[0] && r[1] < pivotIndex[1])
        {
            swap(arr[l[0]++][l[1]--], arr[r[0]--][r[1]++]);
        }
    }

    return pivotIndex;
}

void quickSort(int **arr, vector<int> begin, vector<int> end, int n, int iter)
{
    if (begin[0] < end[0] && begin[1] > end[1])
    {
        vector<int> partionIndex;
        partionIndex = partition(arr, begin, end, n, iter);
        // сортируем левую часть
        vector<int> temp;
        temp.push_back(partionIndex[0] - 1);
        temp.push_back(partionIndex[1] + 1);
        quickSort(arr, begin, temp, n, iter);
        partionIndex[0]++;
        partionIndex[1]--;
        // сортируем правую часть
        quickSort(arr, partionIndex, end, n, iter);
    }
}

void quickSortMatrix(int **arr, int n)
{
    for (int iter = n - 1; iter >= 2; iter--)
    {
        vector<int> begin;
        begin.push_back(0);
        begin.push_back(iter - 1);
        vector<int> end;
        end.push_back(iter - 1);
        end.push_back(0);
        quickSort(arr, begin, end, n, iter);
        quickSort(arr, end, begin, n, iter);
        begin[0] = n - iter;
        begin[1] = n - 1;
        end[0] = n - 1;
        end[1] = n - iter;
        quickSort(arr, begin, end, n, iter);
        quickSort(arr, end, begin, n, iter);
    }
}

// HEAP SORT    //
////////////////////////////////////////////////
void pushdown(int *a, int first, int last)
/*элементы a[first]…a[last] составляют частично упорядоченное дерево за исключением,
возможно a[first] и сыновей.
 pushdown восстанавливает частично упорядоченное дерево */
{
    int r = first;
    while (r < (last + 1) / 2)
    {
        //Если один сын
        if (last == 2 *r + 1)
        {
            //проверяем, не нарушена ли упорядоченность по отношению к нему
            //если нарушена, меняем местами
            if (a[r] <= a[2 *r + 1]) std::swap(a[r], a[2 *r + 1]);
            r = last;
        }

        //если два сына, проверяем, если кто-то из них больше родителя, меняем его с
        //родителем местами и переходим к этому сыну
        else if (a[r] < a[2 *r + 1] && a[2 *r + 1] >= a[2 *r + 2])
        {
            std::swap(a[r], a[2 *r + 1]);
            r = 2 *r + 1;
        }
        else if (a[r] < a[2 *r + 2] && a[2 *r + 2] > a[2 *r + 1])
        {
            std::swap(a[r], a[2 *r + 2]);
            r = 2 *r + 2;
        }
        else
            r = last;
    }
}

void heapSort(int *a, int n)
//сортирует элементы массива в возрастающем порядке
{
    //создание частично упорядоченного дерева
    for (int i = n / 2 - 1; i >= 0; i--)    //1
        pushdown(a, i, n - 1);  //2
    for (int i = n - 1; i >= 1; i--)    //3
    {
        //меняем местами первый – максимальный и последний текущий
        std::swap(a[0], a[i]);  //4
        //исключаем из рассмотрения последний текущий и восстанавливаем частично
        //упорядоченное дерево
        pushdown(a, 0, i - 1);  //5
    }
}

void heapSortMatrix(int **a, int n)
//сортирует элементы массива в возрастающем порядке
{
    for (int iter = n - 1; iter >= 2; iter--)
    {
        int *temp = new int[iter];
        // write to temp
        for (int i = 0, j = iter - 1, k = 0; i <= iter - 1, j>= 0; i++, j--, k++)
        {
            temp[k] = a[i][j];
        }

        heapSort(temp, iter);
        // write to matrix
        for (int i = 0, j = iter - 1, k = 0; i <= iter - 1, j>= 0; i++, j--, k++)
        {
            a[i][j] = temp[k];
        }

        // write to temp
        for (int i = n - iter, j = n - 1, k = 0; i <= iter, j>= n - iter; i++, j--, k++)
        {
            temp[k] = a[i][j];
        }

        heapSort(temp, iter);
        // write to matrix
        for (int i = n - iter, j = n - 1, k = 0; i <= iter, j>= n - iter; i++, j--, k++)
        {
            a[i][j] = temp[k];
        }

        delete[] temp;
    }
}

int main()
{
    ifstream in ("input.txt");
    int n; in >> n;
    int **a = create_array(n, in);
    //int**b = create_array(n, in);
    in .close();
    quickSortMatrix(a, n);
    //heapSortMatrix(b, n);
    ofstream out("output.txt");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            out << a[i][j] << ' ';
        }

        out << '\n';
    }

    /*
    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n; j++)
    {
    out << b[i][j] << ' ';
    }

    out << '\n';
    }

    */
    out.close();
    delete_array(a, n);
    //delete_array(b, n);
    return 0;
}