#include <iostream>
#include <fstream>
#include "queue.cpp"
using namespace std;
int main()
{
    ifstream in ("input.txt");
    Queue<int> queue1;
    Queue<int> queue2;
    Queue<int> queue;
    int elem;
    // filling the first queue
    while (in >> elem)
    {
        queue1.push(elem);
    } in .close();
    // sorting elements
    while (!queue1.empty())
    {
        elem = queue1.pop();
        // first we push even elements
        // in the main stack
        if (elem % 2 == 0)
        {
            queue.push(elem);
        }

        // odd elements push in the
        // other stack
        else
        {
            queue2.push(elem);
        }
    }

    // push even elements in the
    // main stack
    while (!queue2.empty())
    {
        queue.push(queue2.pop());
    }

    ofstream out("output.txt");
    // writing in the output file
    while (!queue.empty())
    {
        out << queue.pop() << ' ';
    }

    return 0;
}