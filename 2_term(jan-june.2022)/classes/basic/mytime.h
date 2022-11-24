#ifndef MYTIME_H
#define MYTIME_H
#include <ctime>
	// Класс исключений
class TimeException
{
	// Сообщение ошибки
	string error;
	public:
		// Вывод ошибки
		void what()
		{
			cout << error;
		}

	// Конструктор
	TimeException(string error)
	{
		this->error = error;
	}
};

class Time
{
	// Получаем текущее время с помощью ctime
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int hours;
	int minutes;
	int seconds;
	public:
		// Вывод времени
		void printTime()
		{
			cout << this->hours << ':' << this->minutes <<
				':' << this->seconds;
		}

	// Вывод текущего времени
	static void timeNowPrint()
	{
		Time temp;
		temp.printTime();
	}

	// Конструктор, который задаёт значения полям объекта
	// текущим временем, если параметры не были заданы
	Time()
	{
		this->hours = ltm->tm_hour;
		this->minutes = ltm->tm_min;
		this->seconds = ltm->tm_sec;
	}

	// Сеттер времени
	void setTime(int hours, int minutes, int seconds)
	{
		// Если отрицательное время, то выкидывается
		// исключение
		if (hours < 0)
		{
			throw TimeException("negative hours\n");
		}
		else if (minutes < 0)
		{
			throw TimeException("negative minutes\n");
		}
		else if (seconds < 0)
		{
			throw TimeException("negative seconds\n");
		}

		// Если время положительно
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
		// Если значения превышают допустимые, то
		// увеличиваем значения других полей
		// и уменьшаем превышающие
		while (this->seconds >= 60)
		{
			this->minutes++;
			this->seconds -= 60;
		}

		while (this->minutes >= 60)
		{
			this->hours++;
			this->minutes -= 60;
		}

		this->hours %= 24;
	}

	// Конструктор с указанными значениями
	Time(int hours, int minutes, int seconds)
	{
		setTime(hours, minutes, seconds);
	}

	// Посчитать время, которое будет через n-ое кол-во ч, м, сек
	Time timeBefore(int hours, int minutes, int seconds)
	{
		Time temp((this->hours + hours), (this->minutes + minutes),
			(this->seconds + seconds));
		return temp;
	}

	// Конструктор копирования
	Time(const Time &other)
	{
		hours = other.hours;
		minutes = other.minutes;
		seconds = other.seconds;
	}

	// Посчитать + ВЫВЕСТИ время, которое будет через n-ое кол-во ч, м, сек
	void timeBeforePrint(int hours, int minutes, int seconds)
	{
		// Вызывается конструктор копирования
		Time temp = timeBefore(hours, minutes, seconds);
		temp.printTime();
	}

	// Посчитать время между двумя значениями времени
	Time timeBetween(Time other)
	{
		Time temp;
		// Считаем часы
		temp.hours = (other.hours - hours + 24) % 24;
		// Если не хватает минут в уменьшаемом числе
		if (other.minutes < minutes)
		{
			// Заимствуем 60 минут у часа
			if (temp.hours == 0)
			{
				temp.hours = 23;
			}
			else
			{
				temp.hours--;
			}

			other.minutes += 60;
		}

		// Вычисляем
		temp.minutes = other.minutes - minutes;
		// Если не хватает секунд в уменьшаемом числе
		if (other.seconds < seconds)
		{
			// Если не хватает минут в уменьшаемом числе
			if (temp.minutes == 0)
			{
			 	// Заимствуем 60 минут у часа
				if (temp.hours == 0)
				{
					temp.hours = 23;
				}
				else
				{
					temp.hours--;
				}

				temp.minutes = 59;
			}
			else
			{
				temp.minutes--;
			}

			// Заимствуем 60 секунд у минуты
			other.seconds += 60;
		}

		// Вычисляем
		temp.seconds = other.seconds - seconds;
		return temp;
	}

	// Посчитать + ВЫВЕСТИ время между двумя значениями времени
	void timeBetweenPrint(const Time &other)
	{
		Time temp = timeBetween(other);
		temp.printTime();
	}
};

#endif