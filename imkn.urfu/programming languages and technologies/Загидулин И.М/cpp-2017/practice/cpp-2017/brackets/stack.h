#pragma once

const int MAX = 100;

template <class Type>
class Stack
{
private:
	Type s[MAX];
	int top;

public:
	// конструктор
	Stack() { top = -1; }

	void push(Type x)
	{
		top++;
		s[top] = x;
	}

	Type pop()
	{
		Type x = s[top];
		top--;
		return x;
	}

	Type read()
	{
		return s[top];
	}

	bool empty()
	{
		return top == -1;
	}

	void clear()
	{
		top = -1;
	}
};