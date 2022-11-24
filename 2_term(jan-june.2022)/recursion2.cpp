#include <iostream>
#include <cmath>
using namespace std;
double f(string s, int k)
{
  if (s.length() > 0)
  {
    // Запоминаем последнюю цифру числа
    char n = s[s.length() - 1];
    // Удаляем её из исходной строки
    s.erase(s.length() - 1);
    // Заходим вглубь, а потом производим с выбранным
    // числом операцию по переводу из 10 СС в 2, т. е
    // умножаем на степень двойки и складываем с другими
    // степенями
    // В ASCII: '1' - 49 номер
    return f(s, k + 1) + ((int) n - 48) *pow(2, k);
  }
  else
  {
    return 0;
  }
}

int main()
{
  cout << "Введите n: ";
  string s;
  cin >> s;
  int i = 1;
  // проверка на некорректные входные данные
  for (i; i < s.length(); i++)
  {
    if (s[i] != 48 && s[i] != 49)
    {
      cout << "Не является двоичным числом" << endl;
      return 0;
    }
  }

  // проверка на знак
  if (s[0] == '-')
  {
    cout << s[0];
    // стираем знак из строки
    s.erase(0, 1);
    // запускаем
    cout << f(s, 0);
  }
  else if (s[0] == 48 || s[0] == 49)
  {
    // запускаем, если всё ОК
    cout << f(s, 0);
  }

  return 0;
}