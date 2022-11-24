#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream in ("input.txt");
	ofstream out("output.txt");
	string s;
	// сохраняем цифры из строк файла
	vector<set < int>> digits;
	while (getline(in, s))
	{
		set<int> temp;
		for (int i = 0; i < s.size(); i++)
		{
			// если цифра
			if (isdigit(s[i]))
			{
			 	// переводим char в string для stoi
				string tmpCh(1, s[i]);
				// добавляем во временный сет число
				temp.insert(stoi(tmpCh));
			}
		}

		// заносим в вектор сетов
		digits.push_back(temp);
	}

	set<int> tempDifferenceSet;
	for (int i = 1; i < digits.size() - 1; i++)
	{
		// ищем разницу между нулевым и i-ым
		set_difference(digits[0].begin(), digits[0].end(), digits[i].begin(),
			digits[i].end(), inserter(tempDifferenceSet, tempDifferenceSet.end()));
		// удаляем из нулевого разницу
		for (auto i: tempDifferenceSet)
		{
			digits[0].erase(i);
		}
	}

	for (auto i: digits[0])
	{
		out << i << ' ';
	}

	out << '\n'; in .close();
	out.close();
	return 0;
}