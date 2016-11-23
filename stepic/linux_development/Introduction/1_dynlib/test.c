#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

int (*stringStat)(const char*, int, int*);

bool initLib() {
	void *hdl = dlopen("/home/konstantin/study/stepic/linux_development/Introduction/1_dynlib/libsolution.so", RTLD_LAZY);
	if ( NULL == hdl )
		return false;
	stringStat = (int (*) (const char*, int, int*)) dlsym(hdl, "stringStat");
	if ( NULL == hdl )
		return false;
	int i = 2;
	stringStat("hi dude", 2, &i);
	printf("%d", i);
	return true;
}

int main() {
	initLib();
}
