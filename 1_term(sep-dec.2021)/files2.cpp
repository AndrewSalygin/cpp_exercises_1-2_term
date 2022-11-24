#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream in1("input1.txt");
    ifstream in2("input2.txt");
    ofstream out("output.txt");

    if (!in1 || !in2)
    {
        cout << "error";
        return 0;
    }

    double n1;
    double n2;
    // пока числа есть
    while (in1 >> n1)
    {
        in2 >> n2;
        // записываем в файл
        out << (n1 + n2) / 2 << '\n';
    }

    in1.close();
    in2.close();
    out.close();

    return 0;
}