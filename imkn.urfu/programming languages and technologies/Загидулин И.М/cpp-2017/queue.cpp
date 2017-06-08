#include "queue.h"

void Queue::push(int x)
{
	s[tail] = x;
	tail = (tail + 1) % MAX;
}

int Queue::pop()
{
	int x = s[head];
	head = (head + 1) % MAX;
	return x;
}

int Queue::read()
{
	return s[head];
}

bool Queue::empty()
{
	return tail == head;
}
