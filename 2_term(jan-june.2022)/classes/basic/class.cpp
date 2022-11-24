#include <iostream>
using namespace std;
#include "mytime.h"

int main()
{
    // Обработка исключения с отрицательным
    // временем
    try
    {
        Time time(24, -2, 0);
        time.printTime();
    }

    catch (TimeException & ex)
    {
        ex.what();
    }

    cout << "----------------\n";
    // Вычисление времени между числами
    // 10 - 11 = 23 часов
    // но не хватает минутам 10 - 11, поэтому + 60 |=> 22 часа
    // значит 59 минут
    // но не хватает секундам 48 - 49, поэтому + 60 |=> 58 минут
    // значит 59 секунд
    ////////////////////////////////////////////////////////////
    Time time(11, 11, 49);
    Time time2(10, 10, 48);
    cout << "Время между: \n";
    time.printTime();
    cout << " и ";
    time2.printTime();
    cout << '\n' << "Будет: ";
    time.timeBetweenPrint(time2);
    cout << '\n' << '\n';
    Time time3(10, 11, 49);
    Time time4(11, 10, 48);
    cout << "Время между: \n";
    time3.printTime();
    cout << " и ";
    time4.printTime();
    cout << '\n' << "Будет: ";
    time3.timeBetweenPrint(time4);
    cout << '\n';
    ////////////////////////////////////////////////////////////
    cout << "----------------\n";
    cout << "Сколько времени пройдет через" << '\n' << "3 часа и 120 минут (5 часов) от
    ";
    time.printTime();
    cout << " - ";
    time.timeBeforePrint(3, 120, 0);
    cout << "\n----------------\n";
    cout << "Текущее время: \n";
    Time::timeNowPrint();
    cout << "\n----------------\n";
    cout << "Время без переданных параметров: \n";
    Time time5;
    time5.printTime();
    return 0;
}