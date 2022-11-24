#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	// запись
	ofstream out("in.dat", ios::binary);
	cout << "Введите n (кол-во чисел для записи в файл):" << endl;
	int n;
	cin >> n;
	double b;
	for (int i = 0; i < n; i++)
	{
		// каждый член последовательности
		b = 1. / (i + 1);
		// запись
		out.write((char*) &b, sizeof(double));
	}

	out.close();
	// вывод
	ifstream in ("in.dat", ios::binary);
	for (int i = 0; i < n / 3; i++)
	{
		// передвигаем указатель чтения на 16 байт
		in .seekg(sizeof(double) *2, ios::cur);
		// читаем
		in .read((char*) &b, sizeof(double));
		cout << b << endl;
	} in .close();
	return 0;
}