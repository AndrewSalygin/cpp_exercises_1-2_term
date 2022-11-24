#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите координаты первой точки (сначала x потом y): \n" << endl;
	double x1, y1;
	cin >> x1 >> y1;
	cout << "Введите координаты второй точки (сначала x потом y): \n" << endl;
	double x2, y2;
	cin >> x2 >> y2;
	cout << "Введите координаты третьей точки (сначала x потом y): \n" << endl;
	double x3, y3;

	cin >> x3 >> y3;
	double A, B, C, p;
	// вычисляем точки треугольника
	A = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
	B = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
	C = pow(pow(x1 - x3, 2) + pow(y1 - y3, 2), 0.5);
	// вычисляем полупериметр
	p = (A + B + C) / 2.0;

	cout << "Площадь треугольника ABC:" << '\n';
	// считаем площадь по Герону
	cout << setprecision(6) << pow(p * (p - A) * (p - B) * (p - C), 0.5);
	return 0;
}