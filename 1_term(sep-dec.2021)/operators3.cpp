#include <iostream>

using namespace std;

int main()
{
    // единицы
    int mem_i_one;

    // десятки
    int mem_i_dec;

    int mem_i;
    for (int i = 10; i < 100; i++)
    {
        mem_i = i;

        // единица числа
        mem_i_one = mem_i % 10;

        // десяток числа
        mem_i /= 10;
        mem_i_dec = mem_i % 10;

        // если цифры не одинаковые
        if (mem_i_dec != mem_i_one)
        {
            cout << i << " ";
        }
    }
    cout << "\n";

    int i = 10;
    do
    {
        mem_i = i;
        mem_i_one = mem_i % 10;
        mem_i /= 10;
        mem_i_dec = mem_i % 10;

        if (mem_i_dec != mem_i_one)
        {
            cout << i << " ";
        }
        i++;
    } while (i < 100);

    cout << "\n";

    i = 10;
    while (i < 100)
    {
        mem_i = i;
        mem_i_one = mem_i % 10;
        mem_i /= 10;
        mem_i_dec = mem_i % 10;

        if (mem_i_dec != mem_i_one)
        {
            cout << i << " ";
        }
        i++;
    }
    return 0;
}
