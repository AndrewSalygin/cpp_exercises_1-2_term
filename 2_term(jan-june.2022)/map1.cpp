#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main()
{
	ifstream in ("input.txt");
	ofstream out("output.txt");
	int num;
	// map из числа и пары индексов (его первое вхождение
	// и первое вхождение противоположного)
	map<int, pair<int, int>> mapOfNumbers;
	int k = 0;
	while (in .peek() != EOF)
	{
		if (in >> num)
		{
			// Если число не нашлось в map
			if (mapOfNumbers.find(num) == end(mapOfNumbers))
			{
				mapOfNumbers.insert(make_pair(num, make_pair(k, -1)));
				k++;
			}
		}

		// Если это не число
		else
		{
			// Очищаем лог исключений
			in .clear();
			// Игнорируем по одному символу вплоть до пробела
			in .ignore(1, ' ');
		}
	}

	for (auto it = begin(mapOfNumbers); it != end(mapOfNumbers); it++)
	{
		auto findNum = mapOfNumbers.find(-it->first);
		if (findNum != end(mapOfNumbers))
		{
			it->second.second = findNum->second.first;
		}

		out << "Num: " << it->first << ", first in: " <<
			it->second.first << ", first in negative: " << it->second.second << '\n';
	} in .close();
	out.close();
}