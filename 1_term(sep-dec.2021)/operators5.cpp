#include <iostream>

using namespace std;

int main()
{
    int num = 8;
    for (int i = 5; i > 0; i--)
    {
        // т. к i -> 0, то кол-во столбцов будет
        // постепенно уменьшаться
        for (int j = i; j > 0; j--)
        {
            cout << num << " ";
        }
        // как только вывели все числа из столбца
        cout << "\n";

        // меняем цифру
        --num;
    }
    return 0;
}
