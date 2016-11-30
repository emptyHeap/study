#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char command[sizeof(argv[1]) + sizeof(argv[2]) + 2];
	sprintf(command, "%s %s", argv[1], argv[2]);

	FILE *coutput = popen(command, "r");
	int count = 0;
	char c;
	while ( (c = fgetc(coutput)) != EOF ) {
		if (c == '0') count++;
	}
	pclose(coutput);

	printf("%i\n", count);

	return 0;
}
