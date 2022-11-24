#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct student
{
    string name, surname, mid_name;
    int course, group;
    double result;
    bool norma(double &result, double&);
    // конструктор
    student(string nm, string srnm, string md_nm,
        int crs, int grp, double rslt);
};


// конструктор
student::student(string nm, string srnm, string md_nm,
    int crs, int grp, double rslt)
{
    name = nm;
    surname = srnm;
    mid_name = md_nm;
    course = crs;
    group = grp;
    result = rslt;
}

// выполнил ли студент норматив
bool student::norma(double& result, double& norm)
{
    double eps = 10e-6;
    return result + eps < norm;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    if (!in)
    {
        cout << "error";
        return 0;
    }

    string s;
    getline(in, s);

    // норматив
    double norm = stod(s);

    student *stud = new student("", "", "", 0, 0, 0);

    int k;

    // переменные для работы со строками
    string::size_type pos;
    string::size_type sign;
    string word;
    string symbols = "; ";

    while (in.peek() != EOF)
    {
        getline(in, s);

        pos = 0;
        sign = s.find_first_of(symbols, pos);
        // номер элемента (ФИО, группа и т.п)
        k = 0;
        while (sign != string::npos)
        {
            word = s.substr(pos, sign - pos);
            switch (k)
            {
                // обращаемся к полю через оператор выбора
                case 0: stud->surname = word;      break;
                case 1: stud->name = word;         break;
                case 2: stud->mid_name = word;     break;
                case 3: stud->course = stoi(word); break;
                case 4: stud->group = stoi(word);  break;
                case 5: stud->result = stod(word); break;
            }
            k++;
            pos = sign + 1;
            sign = s.find_first_of(symbols, pos);
        }

        // запись в файл
        if (stud->student::norma(stud->result, norm))
        {
            out << stud->surname << ' ' << stud->name << ' ' <<
                stud->mid_name << ' ' << stud->course << ' ' <<
                stud->group << ' ' << stud->result << '\n';
        }
    }

    in.close();
    out.close();
    return 0;
}

