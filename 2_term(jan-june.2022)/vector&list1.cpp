#include <iostream>
#include <vector>
#include <list>
using namespace std;
// А) Заменить средний элемент на сумму первого и последнего
// Б) Вставить элемент x перед первым и последним элементами
int main()
{
	setlocale(LC_ALL, "Russian");
	// VECTOR
	cout << "Количество элементов: " << endl;
	int n;
	cin >> n;
	vector<int> a;
	cout << "Введите элементы: " << endl;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		a.push_back(num);
	}

	cout << '\n';
	// Если есть как минимум два элемента
	if (a.size() > 1)
	{
		a[a.size() / 2] = a[0] + a[a.size() - 1];
	}

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}

	// LIST
	list<int> l;
	cout << '\n';
	cout << "Введите элементы: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		l.push_back(num);
	}

	cout << "Введите элементы, которые нужно вставить (в начало, в конец): " << endl;
	int num_left;
	int num_right;
	cin >> num_left >> num_right;
	l.push_front(num_left);
	l.push_back(num_right);
	// Выводим элементы списка
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << ' ';
	return 0;
}