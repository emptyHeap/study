#ifndef _STACK_H_
#define _STACK_H_

const int MAX = 100;

class Stack
{
private:
    int s[MAX], top;

public:
    // конструктор
    Stack() { top = -1; }

    void push(int x);
    int pop();
    bool empty();

    // чтение без удаления
    int read();

	// полная очистка стека
	void clear();
};

#endif // _STACK_H_