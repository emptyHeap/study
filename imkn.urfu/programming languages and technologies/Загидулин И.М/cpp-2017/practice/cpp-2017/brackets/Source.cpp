#include "stack.h"
#include <iostream>
#include <string>

char pair(char closed)
{
	switch (closed)
	{
		case ')' : return '(';
		case ']' : return '[';
		case '}' : return '{';
		case '>' : return '<';
		default : return 0;
	}
}


void main()
{
	std::string input;

	std::getline(std::cin, input);

	Stack<char> st;

	Stack<std::string> stack_string;

	bool correct = true;

	for (int i = 0; i < input.length(); i++)
	{
		char c = input[i];

		if (c == '(' || c == '[' || c == '{' || c == '<')
				st.push(c);

		if (c != ')' && c != ']' && c != '}' && c != '>')
			continue;

		if (st.empty())
		{
			correct = false;
			break;
		}

		char t = st.pop();
		if (pair(c) != t)
		{
			correct = false;
			break;
		}
	} // for

	if (!st.empty())
		correct = false;

	std::cout << correct << std::endl;
}
