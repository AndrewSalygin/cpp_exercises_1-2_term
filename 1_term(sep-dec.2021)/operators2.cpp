#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int scores;
    cin >> scores;

    string s;

    if (scores < 0 || scores > 100)
    {
        s = "некорректное значение";
    }
    else if (scores >= 50)
    {
        // если вторая цифра удовл-ет условиям
        switch ((scores / 10) % 10)
        {
            case 5: case 6: s = "удовлетворительно";     break;
            case 7: case 8: s = "хорошо";                break;
            case 9: case 0: s = "отлично";               break;
            default:        s = "некорректное значение";
        }
    }
    else
    {
        s = "неудовлетворительно";
    }

    cout << s;

    return 0;
}
