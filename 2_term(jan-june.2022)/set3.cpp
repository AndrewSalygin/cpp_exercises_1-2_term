#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <Windows.h>
using namespace std;
void cycleInsertToSet(set<string> &Set, const vector<string> &VecStr,
		int i, size_t &foundFirst, size_t &foundLast)
{
	Set.insert(VecStr[i].substr(foundFirst, foundLast - foundFirst));
	foundFirst = foundLast + 1;
	foundLast = VecStr[i].find_first_of(" .!?", foundFirst);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	ifstream in ("input.txt");
	ofstream out("output.txt");
	string s;
	getline(in, s);
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}

	vector<string> VecStr;
	size_t foundFirst = 0;
	size_t foundLast = s.find_first_of(".!?");
	while (foundLast != string::npos)
	{
		VecStr.push_back(s.substr(foundFirst, foundLast - foundFirst + 1));
		foundFirst = foundLast + 2;
		foundLast = s.find_first_of(".!?", foundFirst);
	}

	set<string> FirstSet;
	set<string> SecondSet;
	set<string> ThirdSet;
	string elementsStr[3] = { ".", "?", "!" };

	for (int i = 0; i < VecStr.size(); i++)
	{
		size_t foundFirst = 0;
		for (int j = 0; j < 3; j++)
		{
			size_t foundLast = VecStr[i].find_first_of(elementsStr[j]);
			if (foundLast != string::npos)
			{
				foundLast = VecStr[i].find_first_of(" " + elementsStr[j]);
				while (foundLast != string::npos)
				{
					switch (j)
					{
						case 0:
							cycleInsertToSet(FirstSet, VecStr, i, foundFirst, foundLast);
							break;
						case 1:
							cycleInsertToSet(SecondSet, VecStr, i, foundFirst,
								foundLast);
							break;
						case 2:
							cycleInsertToSet(ThirdSet, VecStr, i, foundFirst, foundLast);
							break;
					}
				}

				break;
			}
		}
	}

	set<string> InterSectionSet;
	set_intersection(FirstSet.begin(), FirstSet.end(),
		SecondSet.begin(), SecondSet.end(),
		inserter(InterSectionSet, InterSectionSet.end()));
	set<string> DiffSet;
	set_difference(InterSectionSet.begin(), InterSectionSet.end(),
		ThirdSet.begin(), ThirdSet.end(),
		inserter(DiffSet, DiffSet.end()));
	for (string i: DiffSet)
	{
		out << i << ' ';
	}

	out << '\n' << DiffSet.size(); in .close();
	out.close();
	return 0;
}