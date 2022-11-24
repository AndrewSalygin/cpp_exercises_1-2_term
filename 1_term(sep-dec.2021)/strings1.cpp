#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string s, s_result;
    cout << "Введите строку, которую необходимо зашифровать:" << '\n';
    // используем getline, т.к он считывает всю строку
    // а не до пробельного символа
    getline(cin, s);
    s_result = s;

    int k = 0;
    // расставляем чётные элементы
    // так как строка начинается с 0, то
    // к (i * 2) прибавляем 1
    for (int i = 0; (i * 2) + 1 < s.length(); i++, k++)
    {
        s_result[i] = s[(i * 2) + 1];
    }

    int l;
    // чётность длины строки
    // т.к s нач с 0
    if (s.length() % 2 == 0)
    {
        // нечётный элем
        l = s.length() - 2;
    }
    else
    {
        // нечётный элем
        l = s.length() - 1;
    }
    // нечётные элементы (начинаем с k элемента)
    for (; k < s.length(); l -= 2, k++)
    {
        s_result[k] = s[l];
    }
    cout << s_result << '\n';
    return 0;
}
