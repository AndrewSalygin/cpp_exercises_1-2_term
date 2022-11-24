#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <Windows.h>
using namespace std;
bool comparator(pair<int, int> a, pair<int, int> b)
{
	return a.first + a.second > b.first + b.second;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<pair<int, int>> points;
	ifstream in ; in .open("input.txt");
	pair<int, int> temp;
	while (! in .eof())
	{
		in >> temp.first >> temp.second;
		points.push_back(temp);
	} in .close();
	vector<pair<int, int>> copyPoints = points;
	ofstream out;
	out.open("output.txt");
	// А
	out << 'A' << '\n';
	vector<pair<int, int>>::iterator iter = remove_if(points.begin(), points.end(),
	[](pair<int, int> temp)
		{
			return temp.second > 0;
	});
	points.erase(iter, points.end());
	for (auto i: points)
	{
		out << i.first << ' ' << i.second << '\n';
	}

	// Б
	out << 'B' << '\n';
	points = copyPoints;
	cout << "Введите точку (считаем выше и правее неё): ";
	cin >> temp.first >> temp.second;
	int count = count_if(points.begin(), points.end(), [temp](		pair<int, int> point) mutable
	{
		return point.first > temp.first && point.second >
			temp.second;
	});
	out << "Количество точек, лежащих правее и выше (" << temp.first << ';' <<
		' ' << temp.second << "): " << count;
	// В
	out << 'B' << '\n';
	cout << "Введите R: ";
	double r;
	cin >> r;
	iter = find_if(points.begin(), points.end(), [r](pair<int, int> point)
	{
		return sqrt(point.first *point.first + point.second *point.second) < r;
	});
	out << "Точка лежащая внутри R: ";
	if (iter != points.end())
	{
		out << (*iter).first << ' ' << (*iter).second;
	}
	else
	{
		out << "не найдена\n";
	}

	// Г
	stable_sort(points.begin(), points.end(), comparator);
	for (auto i: points)
	{
		out << i.first << ' ' << i.second << '\n';
	}

	out.close();
	return 0;
}