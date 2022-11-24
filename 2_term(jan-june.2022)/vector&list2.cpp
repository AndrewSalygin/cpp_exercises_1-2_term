#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <Windows.h>
using namespace std;
class Candy
{
	string tasty_;
	string factory_;
	public:
		void setTasty(string tasty)
		{
			tasty_ = tasty;
		}

	void setFactory(string factory)
	{
		factory_ = factory;
	}

	string getFactory()
	{
		return factory_;
	}

	string getTasty()
	{
		return tasty_;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream in ; in .open("input.txt");
	vector<Candy> candiesVector;
	list<Candy> candiesList;
	string s;
	Candy temp;
	while (in >> s)
	{
		temp.setTasty(s); in >> s;
		temp.setFactory(s);
		candiesList.push_back(temp);
		candiesVector.push_back(temp);
	} in .close();
	// Vector
	string replaceTasty;
	string replaceFactory;
	// TERMINAL INPUT
	cout << "Введите вкус конфеты, которой нужно заменить: ";
	cin >> replaceTasty;
	cout << "Введите фабрику:";
	cin >> replaceFactory;
	temp.setTasty(replaceTasty);
	temp.setFactory(replaceFactory);

	for (int i = 0; i < candiesVector.size(); i++)
	{
		if (candiesVector[i].getTasty() == temp.getTasty())
		{
			candiesVector[i] = temp;
		}
	}

	if (candiesVector.back().getTasty() != "CHOCOLATE")
	{
		candiesVector.erase(--candiesVector.end());
	}

	ofstream out;
	out.open("output.txt");
	out << "Vector\n";
	for (auto i: candiesVector)
	{
		out << i.getTasty() << ' ' << i.getFactory() << '\n';
	}

	out << "-----------------\n";
	out << "LIST\n";
	// LIST
	string findTasty;
	string findFactory;
	cout << "Введите вкус конфеты, перед которой нужно вставить: ";
	cin >> findTasty;
	cout << "Введите фабрику:";
	cin >> findFactory;
	cout << "Введите вкус конфеты, которую нужно вставить: ";
	cin >> replaceTasty;
	cout << "Введите фабрику:";
	cin >> replaceFactory;
	temp.setTasty(replaceTasty);
	temp.setFactory(replaceFactory);
	for (auto it = candiesList.begin(); it != candiesList.end(); it++)
	{
		if (it->getTasty() == findTasty && it->getFactory() == findFactory)
		{
			auto tempIt = it;
			candiesList.insert(++tempIt, temp);
		}
	}

	temp.setTasty(candiesList.begin()->getTasty());
	temp.setFactory(candiesList.begin()->getFactory());
	candiesList.push_back(temp);
	candiesList.erase(candiesList.begin());
	for (auto i: candiesList)
	{
		out << i.getTasty() << ' ' << i.getFactory() << '\n';
	}

	out.close();
	return 0;
}