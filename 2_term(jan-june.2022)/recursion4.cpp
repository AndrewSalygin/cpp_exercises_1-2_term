#include <iostream>
using namespace std;
float F(float x)
{
    // Условия функции
    if (x == 1)
    {
        return 1;
    }

    if (x == 2)
    {
        return 5;
    }

    return F(x - 1) + F(x - 2);
}

void F(float x, float &y)
{
    if (x == 1)
    {
        y = 1;
    }
    else if (x == 2)
    {
        y = 5;
    }
    else
    {
        y = F(x - 1) + F(x - 2);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << F(n) << endl;
    float y;
    F(n, y);
    cout << y;
    return 0;
}