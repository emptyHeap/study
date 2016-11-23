#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>

const char* VERSION = "0.0.1";
const char* INFO = "are you a dumbass?";

int main(int c, char **v)
{
	struct option options[] = {
		{"query", required_argument, 0, 'q'},
		{"longinformationrequest", no_argument, 0, 'i'},
		{"version", no_argument, 0, 'v'},
		{0,0,0,0}
	};

	char opchar;
	int opindex;
	bool write_info = false;
	bool write_version = false;
	char* query = NULL;

	while ( -1 != (opchar = getopt_long(c, v, "q:iv", options, &opindex))) {
		switch (opchar) 
		{
			case 'q':
				query = optarg;
				break;
			case 'i':
				write_info = true;
				break;
			case 'v':
				write_version = true;
				break;
			default:
				printf("wrong parameter passed: \"%c\"\n", opchar);
				return 1;
		}

       	}

	if ( write_version ) printf("useless programm \"%s\" version\n\n", VERSION);
	if ( write_info ) printf("%s\n", INFO);
	if ( NULL != query ) printf("%s\n", query);
	return 0;
}
