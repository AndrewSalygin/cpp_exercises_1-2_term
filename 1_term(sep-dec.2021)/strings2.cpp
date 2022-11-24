#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Введите строку:" << '\n';
    getline(cin, s);

    // все разделительные знаки
    string razdel = ",.:;!? ";
    string::size_type sign, pos = 2;

    string word;

    // вставляем для поиска справа (*)
    s.insert(0, "  ");

    // находим первый разделительный знак
    sign = s.find_first_of(razdel, pos);

    // пока знак существует
    while (sign != string::npos)
    {
        // приводим к нижнему регистру
        s[pos] = tolower(s[pos]);

        // есть ли знаки препинания
        if (s.substr(sign, 1) == " ")
        {
            pos = sign + 1;
        }
        else
        {
            // стираем его
            s[sign] = ' ';
            pos = sign + 2;
        }

        // ищем следующий
        sign = s.find_first_of(razdel, pos);
    }

    // сбрасываем параметры
    pos = 2;
    sign = s.find_first_of(razdel, pos);

    while (sign != string::npos)
    {
        // выделяем слово
        word = s.substr(pos - 1, sign - pos + 2);

        
        // ищем справа и слева от слова
        string::size_type found_r = s.find(word, sign);
        string::size_type found_l = s.rfind(word, pos - 2); // (*)
        // если таких слов нет
        if (found_r == string::npos && found_l == string::npos)
        {
            // стираем по бокам слова пробелы
            word.erase(0, 1);
            word.erase(word.length() - 1, 1);

            cout << word << '\n';
        }

        pos = sign + 1;

        sign = s.find_first_of(razdel, pos);
    }

    return 0;
}
