#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    // ifstream используется для чтения содер-ого файла
    // пытаемся прочитать сод-мое файла input.txt
    ifstream in("input.txt");
    // ofstream используется для записи данных в файл
    // создаём файл output.txt
    ofstream out("output.txt");

    // ошибка открытия файла
    if (!in)
    {
        cout << "error";
        return 0;
    }

    // заданное число
    int n;
    in >> n;
    string s;
    // пока не маркер конца файла
    while (in.peek() != EOF)
    {
        // считываем строчку
        getline(in, s);
        // если длина больше заданного числа
        if (s.length() > n)
        {
            out << s << '\n';
        }
    }

    // закрываем файлы
    in.close();
    out.close();

    return 0;
}
