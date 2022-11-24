#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    // первые члены последовательности
    double bn_2 = 2; // b1
    double bn_1 = 1; // b2

    if (n > 2)
    {
        double bn;
        cout << bn_2 << endl;
        cout << bn_1 << endl;
        for (int i = 3; i <= n; i++)
        {
            bn = (2. / 3) * bn_2 - (1. / 3) * pow(bn_1, 2);
            // переобозначаем для следующего bn
            bn_2 = bn_1;
            bn_1 = bn;
            cout << bn << endl;
        }
    }
    else if (n == 2)
    {
        cout << bn_2 << endl;
        cout << bn_1 << endl;
    }
    else if (n == 1)
    {
        cout << bn_2 << endl;
    }
    
    return 0;
}
