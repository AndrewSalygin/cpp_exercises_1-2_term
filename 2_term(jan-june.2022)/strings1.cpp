#include <iostream>
using namespace std;

int main()
{
  // вводим исходную строку string s;
  cin >> s;

  string message_error = "Не является правильной десятичной записью целого числа";
  string right_message = "Является правильной десятичной записью целого числа";

  // слева от числа не может находиться нуль if (s[0] == '0' && s.length() != 1)
  {
    cout << message_error;
    return 0;
  }

  int value = 0;

  // если число отрицательное if (s[0] == '-')
  {
    value++;
  }

  // Начинаем цикл с value
  for (int i = value; i < s.length(); i++)
  {
    // проверяем каждую цифру числа if (!isdigit(s[i]))
    {
      cout << message_error;
      return 0;
    }
  }

  // если это целое десят-ое число cout << right_message;
  return 0;
}