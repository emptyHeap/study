#include <iostream>

const int MAX = 100;

int s[MAX];

int top = -1;

void push(int x)
{
	top++;
	s[top] = x;
}

int pop()
{
	int x = s[top];
	top--;
	return x;
}

int read()
{
	return s[top];
}

bool empty()
{
	return top == -1;
}

int size()
{
	return top + 1;
}

void main()
{
	for (int i = 1; i <= 200; i++)
		push(i + 1);

	for (int i = 1; i <= 30; i++)
		std::cout << pop() << std::endl;
}