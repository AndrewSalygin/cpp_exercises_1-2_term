#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>
using namespace std;
struct Student
{
    int year;
    int count_of_subjects;
    string name, surname, midname;
    vector<int> marks;
};

bool comparator(const Student student2, const Student student1)
{
    if (student1.surname > student2.surname)
    {
        return true;
    }
    else if (student1.surname == student2.surname)
    {
        return student1.year < student2.year;
    }

    return false;
}

void write_to_file(string name_of_file, vector<Student> group, int id)
{
    ofstream out;
    out.open(name_of_file);
    out << id << '\n';
    for (int i = 0; i < group.size(); i++)
    {
        out << group[i].surname << ' ' << group[i].name <<
            ' ' << group[i].midname << ' ' << group[i].year;
        for (int j = 0; j < group[i].marks.size(); j++)
        {
            out << ' ' << group[i].marks[j];
        }

        out << '\n';
    }

    out.close();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream in ; in .open("input.txt");
    vector<Student> group;
    int id_group; in >> id_group;
    int year;
    string name, surname, midname;
    string mark = "";
    while (! in .eof())
    {
        vector<int> marks; in >> surname >> name >> midname >> year; in >> mark;
        // entering marks to vector
        while (in .peek() != '\n' && in .peek() != EOF)
        {
            marks.push_back(stoi(mark)); in >> mark;
        }

        marks.push_back(stoi(mark));
        // create new student
        Student student;
        student.name = name;
        student.surname = surname;
        student.midname = midname;
        student.year = year;
        student.marks = marks;
        // add him to general vector
        group.push_back(student);
    } in .close();
    //sort(group.begin(), group.end(), comparator);
    stable_sort(group.begin(), group.end(), comparator);
    string name_of_file_output = "output.txt";
    write_to_file(name_of_file_output, group, id_group);
    return 0;
}