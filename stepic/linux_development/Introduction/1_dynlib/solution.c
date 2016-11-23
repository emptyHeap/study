#include <string.h>
#include <stdio.h>


int stringStat(const char *string, int multiplier, int *count) {
	*count += 1;
	return ((int) strlen(string)) * multiplier;
}

int main () {
	int i = 1;
	stringStat("lel", 2, &i);
}
