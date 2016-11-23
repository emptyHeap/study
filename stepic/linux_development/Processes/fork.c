#include <unistd.h>
#include <stdio.h>


int main (void) {

		pid_t p;
		p = fork();
		printf("fofrk returned %d\n", p);
}
