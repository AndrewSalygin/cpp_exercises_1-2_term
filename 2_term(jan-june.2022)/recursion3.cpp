#include <iostream>
using namespace std;
void g(int n, int k)
{
  for (int i = 0; i < k; i++)
  {
    cout << '*';
  }

  for (int i = 0; i < n; i++)
  {
    cout << ' ';
  }

  for (int i = 0; i < k; i++)
  {
    cout << '*';
  }

  cout << endl;
}

void f(int n, int k)
{
  if (n > 0)
  {
    // Отрисовываем первую часть
    g(n, k);
    // n - 2, так как кол-во звезд
    // увеличивается, и они занимают
    // место под пробелы
    // Заходим вглубь
    f(n - 2, k + 1);
    // Отрисовываем последнюю часть
    g(n, k);
  }
  else
  {
    g(n, k);
  }
}

int main()
{
  // Пробелы между звездочками
  int n;
  cin >> n;
  // Звездочки (с каждой стороны)
  int k = 1;
  f(n, k);
  return 0;
}