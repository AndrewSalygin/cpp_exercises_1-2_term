#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    double sum = 0;
    double k; // (-1)^(n + 1)
    for (int i = 1; i <= n; i++)
    {
        // на чётных коэф-ент = -1
        if (i % 2 == 0)
        {
            k = -1.0;
        }
        // на нечётных = 1
        else
        {
            k = 1.0;
        }
        sum += k / ((2 * i + 1)*(2 * i + 1));
    }
    cout << sum << endl;
    return 0;
}
