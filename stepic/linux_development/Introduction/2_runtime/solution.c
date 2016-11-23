#include <dlfcn.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int (*some_function)(int);

bool load_library(char* library_path, char* function_name) 
{
	char *path = malloc(strlen(library_path) + 3);
	strcpy(path, "./");
	strcat(path, library_path);
	void *hdl = dlopen(path, RTLD_LAZY);
	if ( NULL == hdl) {
		printf("library \"%s\" does not loaded", library_path);
		return false;
	}
	some_function = (int (*) (int)) dlsym(hdl, function_name);
	if ( NULL == some_function ) {
		printf("function \"%s\" not founded", function_name);
		return false;
	}
	return true;
}

int main(int c, char** v) 
{
	if ( c < 4 ) {
		printf("not enouth parameters passed");
		return 1;
	}

	char* library_path = *(v + 1);
       	char* function_name = *(v + 2);
       	int function_parameter = atoi(*(v + 3));
	bool cool = load_library(library_path, function_name);

	if ( false == cool ) return 1;
	
	printf("%d\n", some_function(function_parameter));
	return 0;
}
