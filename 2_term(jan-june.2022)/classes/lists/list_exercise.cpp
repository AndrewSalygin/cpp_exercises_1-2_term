#include <iostream>
#include <fstream>
#include "list.cpp"
using namespace std;
int main()
{
    ifstream in ("input.txt");
    List<int> list;
    List<int> temp_list;
    int elem;
    // filling the temp_list
    while (in >> elem)
    {
        temp_list.push_front(elem);
    } in .close();
    // filling the list
    for (List<int>::Iterator i = temp_list.begin(); i != temp_list.end(); i++)
    {
        if (*i % 2 != 0)
        {
            list.push_front(*i);
        }
    }

    for (List<int>::Iterator i = temp_list.begin(); i != temp_list.end(); i++)
    {
        if (*i % 2 == 0)
        {
            list.push_front(*i);
        }
    }

    ofstream out("output.txt");
    // writing in the output file
    while (!list.empty())
    {
        out << list.pop_front() << ' ';
    }

    return 0;
}