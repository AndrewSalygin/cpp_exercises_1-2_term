#include <iostream>
#include <fstream>
#include <set>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream in ; in .open("input.txt");
	int num1;
	int num2; in >> num1;
	ofstream out("output.txt");
	while (in >> num2)
	{
		set<int> digits1;
		set<int> digits2;
		set<int> temp;
		int temp1 = num1;
		int temp2 = num2;
		while (num1 > 0)
		{
			digits1.insert(num1 % 10);
			num1 /= 10;
		}

		while (num2 > 0)
		{
			digits2.insert(num2 % 10);
			num2 /= 10;
		}

		out << "Одинаковые цифры у " << temp1 << " и " << temp2 << ": ";
		for (int i = 0; i < 10; i++)
		{
			if (digits1.find(i) != digits1.end() && digits2.find(i) != digits2.end())
			{
				out << i << ' ';
			}

			if (digits1.find(i) == digits1.end() && digits2.find(i) == digits2.end())
			{
				temp.insert(i);
			}
		}

		out << "\nЦифры, которые не встречаются у " << temp1 << " и " << temp2 << ": ";
		for (auto i: temp)
		{
			out << i << ' ';
		}

		out << "\n\n";
		num1 = temp2;
	} in .close();
	out.close();
	return 0;
}