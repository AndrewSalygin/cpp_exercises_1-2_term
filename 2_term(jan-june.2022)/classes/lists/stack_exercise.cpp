#include <iostream>
#include <fstream>
#include "stack.cpp"
using namespace std;
int main()
{
	ifstream in ("input.txt");
	Stack<int> stack1;
	Stack<int> stack2;
	Stack<int> stack;
	int elem;
	// filling the first stack
	while (in >> elem)
	{
		stack1.push(elem);
	} in .close();
	// sorting elements
	while (!stack1.empty())
	{
		elem = stack1.pop();
		// first we push odd elements
		// in the main stack
		if (elem % 2 != 0)
		{
			stack.push(elem);
		}

		// even elements push in the
		// other stack
		else
		{
			stack2.push(elem);
		}
	}

	// push even elements in the
	// main stack
	while (!stack2.empty())
	{
		stack.push(stack2.pop());
	}

	ofstream out("output.txt");
	// writing in the output file
	while (!stack.empty())
	{
		out << stack.pop() << ' ';
	}

	return 0;
}