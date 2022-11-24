#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <Windows.h>
using namespace std;
const double EPS = 10e-12;
class Sound
{
	double height_, duration_;
	void setSound(double height, double duration)
	{
		height_ = height;
		duration_ = duration;
	}

	public:
		Sound(double height, double duration)
		{
			setSound(height, duration);
		}

	double getHeight()
	{
		return height_;
	}

	double getDuration()
	{
		return duration_;
	}
};

class Melody
{
	public:
		vector<Sound> melody_;
	void addSoundInMelody(double height, double duration)
	{
		Sound temp(height, duration);
		melody_.push_back(temp);
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream in ("input.txt");
	ofstream out("output.txt");
	double height, duration;
	Melody melody;
	while (! in .eof())
	{
		in >> height >> duration;
		melody.addSoundInMelody(height, duration);
	}

	double enteredDuration;
	cout << "Задайте длительность: ";
	cin >> enteredDuration;
	int k = 0;
	vector<Sound> temp;
	vector<int> tempI;
	int tempInt;
	int vectorSize = melody.melody_.size();
	vector<Sound>::iterator iter = melody.melody_.begin();
	while (k < vectorSize)
	{
		iter = find_if(iter, melody.melody_.end(), [enteredDuration, &k](Sound melodyDuration)
		{
			k++;
			return melodyDuration.getDuration() < enteredDuration;
	});
		// пока не конец мелодии
		if (k < vectorSize)
		{
			// запоминаем звук
			temp.push_back(*iter);
			// запоминаем индекс звука
			tempI.push_back(k - 1);
			iter++;
		}
	}

	// Так как элементы в следующем цикле будут удалятся, то индексы будут смещаться
	for (int i = 1; i < temp.size(); i++)
	{
		tempI[i] -= i;
	}

	for (int i = 0; i < temp.size(); i++)
	{
		// перекидываем в мелодию
		melody.melody_.push_back(temp[i]);
		// чистим короткий звук в начале мелодии
		melody.melody_.erase(melody.melody_.begin() + tempI[i]);
	}

	for (auto i: melody.melody_)
	{
		out << i.getHeight() << ' ' << i.getDuration() << '\n';
	} in .close();
	out.close();
	return 0;
}