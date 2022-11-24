#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double x;
	cout << "Введите x:" << '\n';
	cin >> x;
	cout << "Значение выражения:" << '\n';
	cout << setprecision(6) << pow(pow(x, 4) + pow(abs(x + 1), 0.5), 0.5) << '\n';
	return 0;
}