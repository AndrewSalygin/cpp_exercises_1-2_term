#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    double k, koef, x;
    cin >> k >> x;

    // произведение всех членов посл-ти
    double p = 1;

    double stepenx = 1;
    double factn = 1;
    for (int n = 1; n <= k; n++)
    {
        if (n % 2 == 0)
        {
            koef = -1.0;
        }
        else
        {
            koef = 1.0;
        }
        stepenx *= x;
        factn *= n;
        p *= 1 + ((koef * stepenx) / factn);
    }
    cout << p << endl;
    return 0;
}
