#include "stack.h"

void Stack::push(int x)
{
	top++;
	s[top] = x;
}

int Stack::pop()
{
	int x = s[top];
	top--;
	return x;
}

int Stack::read()
{
	return s[top];
}

bool Stack::empty()
{
	return top == -1;
}

void Stack::clear()
{
	top = -1;
}