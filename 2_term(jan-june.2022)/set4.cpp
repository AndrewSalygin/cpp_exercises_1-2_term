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
	setlocale(LC_ALL, "Russian");
	ifstream in ("input.txt");
	ofstream out("output.txt");
	int k; in >> k;
	int num;
	vector<set < int>> vectorOfSets; in >> num;
	while (in .peek() != EOF)
	{
		set<int> temp;
		while (in .peek() != '\n')
		{
			temp.insert(num); in >> num;
		}

		temp.insert(num);
		vectorOfSets.push_back(temp); in >> num;
	}

	set<int> setLessK;
	set<int> setMoreK;
	for (int i = 0; i < vectorOfSets.size(); i++)
	{
		if (vectorOfSets[i].size() < k)
		{
			merge(setLessK.begin(), setLessK.end(),
				vectorOfSets[i].begin(), vectorOfSets[i].end(),
				inserter(setLessK, setLessK.begin()));
		}
		else
		{
			merge(setMoreK.begin(), setMoreK.end(),
				vectorOfSets[i].begin(), vectorOfSets[i].end(),
				inserter(setMoreK, setMoreK.begin()));
		}
	}

	set<int> FinalSet;
	set_difference(setMoreK.begin(), setMoreK.end(),
		setLessK.begin(), setLessK.end(),
		inserter(FinalSet, FinalSet.begin()));
	for (int i: FinalSet)
	{
		out << i << ' ';
	} in .close();
	out.close();
	return 0;
}