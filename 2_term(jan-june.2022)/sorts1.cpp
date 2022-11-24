#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;
class Group;
class Student
{
	friend class Group;
	friend bool comparator(const Student &student1, const Student &student2);
	friend void sort_bubble(Group & group);
	friend void sort_selection(Group & group);
	friend void sort_insertion(Group & group);
	friend void write_to_file(string name_of_file, Group &group);
	int year;
	int count_of_subjects;
	string name, surname, midname;
	vector<int> marks;
	public:
		Student(string name, string surname,
			string midname, int year, vector<int> marks);
	bool operator>(const Student &student2)
	{
		string stud1_arr[3] = { surname, name, midname
		};

		string stud2_arr[3] = { student2.surname, student2.name, student2.midname
		};

		for (int i = 0; i < 3; i++)
		{
			if (stud1_arr[i] > stud2_arr[i])
			{
				return true;
			}
			else if (stud1_arr[i] == stud2_arr[i])
			{
				continue;
			}

			return false;
		}

		return false;
	}
};

class Group
{
	int id_group;
	public:
		vector<Student> students;
	void add_new_student(string name, string surname,
		string midname, int year, vector<int> marks);
	Group(int id_group);
	int get_id();
};

int Group::get_id()
{
	return id_group;
}

Group::Group(int id_group)
{
	this->id_group = id_group;
}

Student::Student(string name, string surname,
	string midname, int year, vector<int> marks)
{
	this->name = name;
	this->surname = surname;
	this->midname = midname;
	this->year = year;
	this->marks = marks;
}

void Group::add_new_student(string name, string surname,
	string midname, int year, vector<int> marks)
{
	Student student(name, surname, midname, year, marks);
	this->students.push_back(student);
}

Group input_students(string name_of_file)
{
	ifstream in ; in .open(name_of_file);
	int id_group; in >> id_group;
	Group group(id_group);
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
		Student student(name, surname, midname, year, marks);
		// add him to general vector
		group.students.push_back(student);
	} in .close();
	return group;
}

void sort_bubble(Group & group)
{
	for (int i = 0; i < group.students.size() - 1; i++)
	{
		for (int j = 0; j < group.students.size() - i - 1; j++)
		{
			// compare neighboring elements
			if (group.students[j] > group.students[j + 1])
			{
				swap(group.students[j], group.students[j + 1]);
			}
		}
	}
}

void sort_selection(Group & group)
{
	int j_min;
	for (int i = 0; i < group.students.size() - 1; i++)
	{
		j_min = i;
		for (int j = i + 1; j < group.students.size(); j++)
		{
			// finding min
			if (group.students[j_min] > group.students[j])
			{
				j_min = j;
			}
		}

		// swap min and current element
		swap(group.students[i], group.students[j_min]);
	}
}

void sort_insertion(Group & group)
{
	for (int i = 1; i < group.students.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			// finding element placement
			if (group.students[j] > group.students[j - 1])
			{
				break;
			}

			swap(group.students[j - 1], group.students[j]);
		}
	}
}

void write_to_file(string name_of_file, Group &group)
{
	ofstream out;
	out.open(name_of_file);
	out << group.get_id() << '\n';
	for (int i = 0; i < group.students.size(); i++)
	{
		out << group.students[i].surname << ' ' << group.students[i].name <<
			' ' << group.students[i].midname << ' ' << group.students[i].year;
		for (int j = 0; j < group.students[i].marks.size(); j++)
		{
			out << ' ' << group.students[i].marks[j];
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
	string name_of_file_input = "input.txt";
	Group group = input_students(name_of_file_input);
	sort_insertion(group);
	string name_of_file_output = "output.txt";
	write_to_file(name_of_file_output, group);
	return 0;
}