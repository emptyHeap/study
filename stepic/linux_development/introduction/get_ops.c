#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <stdio.h>


int main(int c, char **v)
{
	int has_brackets = 0;
	int opindex = 0;
	int opchar = 0;
	char string[] = "Und wenn du lange in einen Abgrund blickst, blickt der Abgrund auch in dich hinein";
	size_t length = 0;

	struct option opts[] = {
		{"brackets", no_argument, &has_brackets, 1},
		{"length", required_argument, 0, 'l'},
		{"authornameshouldeprinted", no_argument, 0, 'a'},
		{0,0,0,0}
	};

	while ( -1 != (opchar = getopt_long(c, v, "bl:aq", opts, &opindex))) {
		switch(opchar)
		{
			case 0:
				printf("0\n");
				break;
			case 'l':
				length = atoi(optarg);
				printf("length=%zu\n", length);
				break;
			case 'a':
				printf("(c) Neitzsche\n");
				break;
			default:
				printf("opchar=%c\n", opchar);
		}
	}

	if (strlen(string) > length && 0!=length)
		string[length] = '\0';
	if (has_brackets) 
		printf("%s\n", string);
	else
		printf("%s\n", string);
	printf("Done\n");
	return 0;
}
