#ifndef _QUEUE_H_
#define _QUEUE_H_

const int MAX = 100;

class Queue
{
private:
	int s[MAX], head, tail;

public:
	// еще один способ инициализации полей
	Queue() : head(0), tail(0) {}
	
	void push(int x);
	int pop();
	int read();
	bool empty();
};

#endif
